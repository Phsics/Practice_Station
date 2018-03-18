#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "tgaimage.h"

TGAImage::TGAImage() : data(NULL), width(0), height(0), bytespp(0) {		// 이미지의 데이터와 넓이 높이 픽셀 당 바이트	
}

TGAImage::TGAImage(int w, int h, int bpp) : data(NULL), width(w), height(h), bytespp(bpp) {	//초기 데이터는 널
	unsigned long nbytes = width*height*bytespp;	//바이트 수는 넓이 곱하기 높이 곱하기 픽셀당 바이트
	data = new unsigned char[nbytes];	//unsigned char 는 256바이트까지 지원되므로 RGB데이터가 들어가기적당함
	memset(data, 0, nbytes);
}

TGAImage::TGAImage(const TGAImage &img) {		//이미지를 매개변수로 사용하여 함수를 호출할 경우
	width = img.width;
	height = img.height;
	bytespp = img.bytespp;
	unsigned long nbytes = width*height*bytespp;
	data = new unsigned char[nbytes];
	memcpy(data, img.data, nbytes);
}

TGAImage::~TGAImage() {					 
	if (data) delete [] data;			//데이터가 NULL이 아닐경우 데이터삭제 
}

TGAImage & TGAImage::operator =(const TGAImage &img) {		//이미지 교체? 로 생각됨 
	if (this != &img) {			//이미지가 아닐경우? 
		if (data) delete [] data;		//데이터가 NULL이 아닐경우 삭제 
		width  = img.width;				//이미지의 넓이 높이 bpp를 맞춤 
		height = img.height;
		bytespp = img.bytespp;
		unsigned long nbytes = width*height*bytespp;
		data = new unsigned char[nbytes];			//새로 데이터를 정의 
		memcpy(data, img.data, nbytes);
	}
	return *this;		
}

bool TGAImage::read_tga_file(const char *filename) {		//파일 읽기 반환형 불 
	if (data) delete [] data;		//데이터 삭제 
	data = NULL;					//데이터 = 널 
	std::ifstream in;				//ifstream in :: input file stream  in이라는 이름의 파일스트림 
	in.open (filename, std::ios::binary);     		//in.open 으로 파일을 연다. 바이너리 형식으로 출력... 
	if (!in.is_open()) {							//파일이 없어서 못여는 경우  
		std::cerr << "can't open file " << filename << "\n";
		in.close();
		return false;		//파일열기 실패시 false 반환 
	}
	TGA_Header header;		//파일 해더 
	in.read((char *)&header, sizeof(header));	//헤더파일 크기만큼 파일을 읽어내린다 
	if (!in.good()) {
		in.close();
		std::cerr << "an error occured while reading the header\n";
		return false;
	}
	width   = header.width;			//헤더파일에서 이미지의 넓이와 높이 bbp를 읽어서 집어넣는다. 
	height  = header.height;
	bytespp = header.bitsperpixel>>3;
	if (width<=0 || height<=0 || (bytespp!=GRAYSCALE && bytespp!=RGB && bytespp!=RGBA)) {	//높이,넓이, bpp가 rgb, rgb투명,무채색이 아닐경우 오류 
		in.close();
		std::cerr << "bad bpp (or width/height) value\n";
		return false;
	}
	unsigned long nbytes = bytespp*width*height;		//데이터 범위 지정 
	data = new unsigned char[nbytes];
	if (3==header.datatypecode || 2==header.datatypecode) {			//데이터 타입코드가 2,3일경우 
		in.read((char *)data, nbytes);				//파일을 읽어서 데이터변수에 저장 
		if (!in.good()) {							//ios::good이란 파일읽기중 오류가 없을경우 참 반환 
			in.close();
			std::cerr << "an error occured while reading the data\n";
			return false;
		}
	} else if (10==header.datatypecode||11==header.datatypecode) {		//데이터 타입코드가 10,11일경우 
		if (!load_rle_data(in)) {		//로드데이터 
			in.close();
			std::cerr << "an error occured while reading the data\n";
			return false;
		}
	} else {															//그 외의 타입코드일경우 
		in.close();
		std::cerr << "unknown file format " << (int)header.datatypecode << "\n";	//알수없는 파일 포멧형식 
		return false;
	}
	if (!(header.imagedescriptor & 0x20)) {		//헤더의 이미지묘사기가 0x20일 경우 수직 
		flip_vertically();
	}
	if (header.imagedescriptor & 0x10) {		//헤더의 이미지묘사기가 0x10일 경우 수평 
		flip_horizontally();
	}
	std::cerr << width << "x" << height << "/" << bytespp*8 << "\n";		//std::cerr 표준 에러 스트림 std::clog 표준 로그 스트림 
	in.close();
	return true;
}

bool TGAImage::load_rle_data(std::ifstream &in) {			//로드 데이터 
	unsigned long pixelcount = width*height;		//픽셀수 
	unsigned long currentpixel = 0;					//최근 픽셀	 
	unsigned long currentbyte  = 0;					//최근 바이트 
	TGAColor colorbuffer;							//색 버퍼 
	do {											//do 루프 
		unsigned char chunkheader = 0;				//덩어리헤더 = 0;		
		chunkheader = in.get();						//get()이란, 입력버퍼에서 문자 하나를 가져옴				
		if (!in.good()) {							//good이 아니면 오류 
			std::cerr << "an error occured while reading the data\n";
			return false;
		}
		if (chunkheader<128) {						
			chunkheader++;
			for (int i=0; i<chunkheader; i++) {
				in.read((char *)colorbuffer.raw, bytespp);
				if (!in.good()) {
					std::cerr << "an error occured while reading the header\n";
					return false;
				}
				for (int t=0; t<bytespp; t++)
					data[currentbyte++] = colorbuffer.raw[t];
				currentpixel++;
				if (currentpixel>pixelcount) {
					std::cerr << "Too many pixels read\n";
					return false;
				}
			}
		} else {
			chunkheader -= 127;
			in.read((char *)colorbuffer.raw, bytespp);
			if (!in.good()) {
				std::cerr << "an error occured while reading the header\n";
				return false;
			}
			for (int i=0; i<chunkheader; i++) {
				for (int t=0; t<bytespp; t++)
					data[currentbyte++] = colorbuffer.raw[t];
				currentpixel++;
				if (currentpixel>pixelcount) {
					std::cerr << "Too many pixels read\n";
					return false;
				}
			}
		}
	} while (currentpixel < pixelcount);
	return true;
}

bool TGAImage::write_tga_file(const char *filename, bool rle) {
	unsigned char developer_area_ref[4] = {0, 0, 0, 0};
	unsigned char extension_area_ref[4] = {0, 0, 0, 0};
	unsigned char footer[18] = {'T','R','U','E','V','I','S','I','O','N','-','X','F','I','L','E','.','\0'};
	std::ofstream out;
	out.open (filename, std::ios::binary);
	if (!out.is_open()) {
		std::cerr << "can't open file " << filename << "\n";
		out.close();
		return false;
	}
	TGA_Header header;
	memset((void *)&header, 0, sizeof(header));
	header.bitsperpixel = bytespp<<3;
	header.width  = width;
	header.height = height;
	header.datatypecode = (bytespp==GRAYSCALE?(rle?11:3):(rle?10:2));
	header.imagedescriptor = 0x20; // top-left origin
	out.write((char *)&header, sizeof(header));
	if (!out.good()) {
		out.close();
		std::cerr << "can't dump the tga file\n";
		return false;
	}
	if (!rle) {
		out.write((char *)data, width*height*bytespp);
		if (!out.good()) {
			std::cerr << "can't unload raw data\n";
			out.close();
			return false;
		}
	} else {
		if (!unload_rle_data(out)) {
			out.close();
			std::cerr << "can't unload rle data\n";
			return false;
		}
	}
	out.write((char *)developer_area_ref, sizeof(developer_area_ref));
	if (!out.good()) {
		std::cerr << "can't dump the tga file\n";
		out.close();
		return false;
	}
	out.write((char *)extension_area_ref, sizeof(extension_area_ref));
	if (!out.good()) {
		std::cerr << "can't dump the tga file\n";
		out.close();
		return false;
	}
	out.write((char *)footer, sizeof(footer));
	if (!out.good()) {
		std::cerr << "can't dump the tga file\n";
		out.close();
		return false;
	}
	out.close();
	return true;
}

// TODO: it is not necessary to break a raw chunk for two equal pixels (for the matter of the resulting size)
bool TGAImage::unload_rle_data(std::ofstream &out) {
	const unsigned char max_chunk_length = 128;
	unsigned long npixels = width*height;
	unsigned long curpix = 0;
	while (curpix<npixels) {
		unsigned long chunkstart = curpix*bytespp;
		unsigned long curbyte = curpix*bytespp;
		unsigned char run_length = 1;
		bool raw = true;
		while (curpix+run_length<npixels && run_length<max_chunk_length) {
			bool succ_eq = true;
			for (int t=0; succ_eq && t<bytespp; t++) {
				succ_eq = (data[curbyte+t]==data[curbyte+t+bytespp]);
			}
			curbyte += bytespp;
			if (1==run_length) {
				raw = !succ_eq;
			}
			if (raw && succ_eq) {
				run_length--;
				break;
			}
			if (!raw && !succ_eq) {
				break;
			}
			run_length++;
		}
		curpix += run_length;
		out.put(raw?run_length-1:run_length+127);
		if (!out.good()) {
			std::cerr << "can't dump the tga file\n";
			return false;
		}
		out.write((char *)(data+chunkstart), (raw?run_length*bytespp:bytespp));
		if (!out.good()) {
			std::cerr << "can't dump the tga file\n";
			return false;
		}
	}
	return true;
}

TGAColor TGAImage::get(int x, int y) {
	if (!data || x<0 || y<0 || x>=width || y>=height) {
		return TGAColor();
	}
	return TGAColor(data+(x+y*width)*bytespp, bytespp);
}

bool TGAImage::set(int x, int y, TGAColor c) {
	if (!data || x<0 || y<0 || x>=width || y>=height) {
		return false;
	}
	memcpy(data+(x+y*width)*bytespp, c.raw, bytespp);
	return true;
}

int TGAImage::get_bytespp() {
	return bytespp;
}

int TGAImage::get_width() {
	return width;
}

int TGAImage::get_height() {
	return height;
}

bool TGAImage::flip_horizontally() {
	if (!data) return false;
	int half = width>>1;
	for (int i=0; i<half; i++) {
		for (int j=0; j<height; j++) {
			TGAColor c1 = get(i, j);
			TGAColor c2 = get(width-1-i, j);
			set(i, j, c2);
			set(width-1-i, j, c1);
		}
	}
	return true;
}

bool TGAImage::flip_vertically() {
	if (!data) return false;
	unsigned long bytes_per_line = width*bytespp;
	unsigned char *line = new unsigned char[bytes_per_line];
	int half = height>>1;
	for (int j=0; j<half; j++) {
		unsigned long l1 = j*bytes_per_line;
		unsigned long l2 = (height-1-j)*bytes_per_line;
		memmove((void *)line,      (void *)(data+l1), bytes_per_line);
		memmove((void *)(data+l1), (void *)(data+l2), bytes_per_line);
		memmove((void *)(data+l2), (void *)line,      bytes_per_line);
	}
	delete [] line;
	return true;
}

unsigned char *TGAImage::buffer() {
	return data;
}

void TGAImage::clear() {
	memset((void *)data, 0, width*height*bytespp);
}

bool TGAImage::scale(int w, int h) {
	if (w<=0 || h<=0 || !data) return false;
	unsigned char *tdata = new unsigned char[w*h*bytespp];		//temp 데이터 
	int nscanline = 0;
	int oscanline = 0;
	int erry = 0;
	unsigned long nlinebytes = w*bytespp;
	unsigned long olinebytes = width*bytespp;
	for (int j=0; j<height; j++) {
		int errx = width-w;
		int nx   = -bytespp;
		int ox   = -bytespp;
		for (int i=0; i<width; i++) {
			ox += bytespp;
			errx += w;
			while (errx>=(int)width) {
				errx -= width;
				nx += bytespp;
				memcpy(tdata+nscanline+nx, data+oscanline+ox, bytespp);
			}
		}
		erry += h;
		oscanline += olinebytes;
		while (erry>=(int)height) {
			if (erry>=(int)height<<1) // it means we jump over a scanline
				memcpy(tdata+nscanline+nlinebytes, tdata+nscanline, nlinebytes);
			erry -= height;
			nscanline += nlinebytes;
		}
	}
	delete [] data;
	data = tdata;
	width = w;
	height = h;
	return true;
}
