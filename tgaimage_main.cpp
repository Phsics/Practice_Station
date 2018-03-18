#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);        //  컬러를 지정하였음 (R,G,B,투명도 )로생각됨  
const TGAColor red   = TGAColor(255, 0,   0,   255);        

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {	// 선그리기 (x0,y0) ~ (x1,y1) 사이에 color  칠하기 
    for (float t=0.; t<1.; t+=.1) {
        int x = x0*(1.-t) + x1*t;
        int y = y0*(1.-t) + y1*t;
        image.set(x, y, color);
    }
}

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);          //이미지 형식으로  보임  (가로, 세로 , 픽셀당 bite)로생각됨 
	line(13, 20, 80, 40, image, white);                           //(13,20) ~ (80,40) 까지 하얀색 선 
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}
