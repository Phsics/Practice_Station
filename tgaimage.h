#ifndef __IMAGE_H__		//#ifndef  다음 매크로가 정의 되지 않았을 경우 #endif까지를 컴파일한다 
#define __IMAGE_H__		//#define 다음 매크로를 정의한다. 

#include <fstream>		//파일 입출력에 관한 함수 모음 

#pragma pack(push,1)	//#pragma 직접 컴파일러에게 명령. 
			//패딩비트 : 사용하지 않는 비트
			//구조체의 크기는 구조체 내에서 크기가 가장 큰 자료형의 단위로 묶는다.
			//남는 비트를 패팅비트라고 한다.
	/***********************************************************
	struct A
	{
	char a;
	int b;
	short c;
	double d;
	}; => sizeof(A) => 24
	
	
	struct B
	{
	int a;
	char b;
	short c;
	double d;
	}; => sizeof(B) => 16
	두 구조체에 a=1,b=2,c=3,d=4를 넣을경우
	넣는법
	void PeddingTest_A (A data)
	{
		memset (&data, 0, sizeof(A));  //A구조체 모든바이트에 0을 set
		memset (&data.a,1,sizeof(data.a));a에 1을 set
		memset (&data.b,2,sizeof(data.b));b에 2을 set
		memset (&data.c,3,sizeof(data.c));c에 3을 set
		memset (&data.d,4,sizeof(data.d));d에 4을 set
	}
		 결과는 A :  1000 2222 3300 0000 4444 4444   //가장큰 크기의 자료형이 double이므로 8바이트씩 묶임 
	 	 결과는 B :  1111 2033 4444 4444 
	 	 
	#pragma pack(push,1)
	//이 사이에 구조체를 넣을경우  
	#pragma pack(pop)
	
		결과는 A :   1222 2334 4444 444
		결과는 B :   1111 2334 4444 444
		
	이렇게 효과적으로 메모리를 사용할수 있다.
	단, #pragma pack(push,n) 여기서 n에는 1,2,4,8,16 단위가 들어갈수 있으며
	몇 바이트 단위로 묶음을 할 것인지 설정하는 것이다. 
	
	컴퓨터들 사이에 패킷 전송을 할때 사용하며
	어느구간부터 어느구간까지 패킷을 사용하는지를 명확히 해야한다 
	 
	****************************************************************/				 




struct TGA_Header {			//tga 해더 
	char idlength;			//id길이 
	char colormaptype;		//컬러 맵 타입 (rgb,rgba,그레이스케일) 
	char datatypecode;		//데이터타입 코드 (1,2,10,11) 
	short colormaporigin;	//컬러 맵 오리진 
	short colormaplength;	//컬러 맵 길이 
	char colormapdepth;		//컬러 맵 깊이 
	short x_origin;			//x 오리진 
	short y_origin;			//y 오리진 
	short width;			//넓이 
	short height;			//높이 
	char  bitsperpixel;		//비트퍼픽셀 
	char  imagedescriptor;	//이미지 디스크립터 (플립 수직, 플립수평) 
};
#pragma pack(pop)		//여기서 #pragma pack 마무리 



struct TGAColor {
	union {								//union 내에 변수들은 같은 값을 갖는다?? 
		struct {
			unsigned char b, g, r, a;		//rgba
		};
		unsigned char raw[4];				//raw[0]~raw[4]
		unsigned int val;					//value 
	};
	int bytespp;						//바이트 퍼 픽셀 

	TGAColor() : val(0), bytespp(1) {		//tga컬러를 매개변수 없이 설정했을경우 색=0; bytespp은 1 
	}

	TGAColor(unsigned char R, unsigned char G, unsigned char B, unsigned char A) : b(B), g(G), r(R), a(A), bytespp(4) {
	}							//tga컬러를 rgba로 설정할경우 색 = {R,G,B,A}, bpp=4 

	TGAColor(int v, int bpp) : val(v), bytespp(bpp) {	//tga컬러를 val과bpp로 설정 
	}

	TGAColor(const TGAColor &c) : val(c.val), bytespp(c.bytespp) {	//tga컬러 참조 
	}

	TGAColor(const unsigned char *p, int bpp) : val(0), bytespp(bpp) {		//raw를 통해 색 설정? 
		for (int i=0; i<bpp; i++) {
			raw[i] = p[i];
		}
	}

	TGAColor & operator =(const TGAColor &c) {			//"=" 대입 연산자 오버로딩 
		if (this != &c) {					//이를 통해 TGAColor A = TGAColor B 의 연산이 가능해짐! 
			bytespp = c.bytespp;
			val = c.val;
		}
		return *this;
	}
};


class TGAImage {					//TGAImage 클래스 
protected:					//보호된 (클래스 내에서만 사용가능, 클래스 내부의 함수로만 변경가능?) 
	unsigned char* data;	//데이터 
	int width;				//넓이 
	int height;				//높이 	
	int bytespp;			//바이트 퍼 픽셀 

	bool   load_rle_data(std::ifstream &in);		//	파일 읽기 
	bool unload_rle_data(std::ofstream &out);		//	파일 출력 
public:						//퍼블릭 
	enum Format {			//포맷 형식 그레이 스케일 1, rgb 3 , rgba 4 
		GRAYSCALE=1, RGB=3, RGBA=4
	};
							//사용 가능한 함수들 
	TGAImage();			  	//생성자 
	TGAImage(int w, int h, int bpp);
	TGAImage(const TGAImage &img);
	bool read_tga_file(const char *filename);
	bool write_tga_file(const char *filename, bool rle=true);
	bool flip_horizontally();
	bool flip_vertically();
	bool scale(int w, int h);
	TGAColor get(int x, int y);
	bool set(int x, int y, TGAColor c);
	~TGAImage();
	TGAImage & operator =(const TGAImage &img);
	int get_width();
	int get_height();
	int get_bytespp();
	unsigned char *buffer();
	void clear();
};

#endif //__IMAGE_H__
