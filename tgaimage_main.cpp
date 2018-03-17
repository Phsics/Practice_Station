#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);        //  컬러를 지정하였음 (R,G,B,투명도 )로생각됨  
const TGAColor red   = TGAColor(255, 0,   0,   255);        

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);          //이미지 형식으로  보임  (가로, 세로 , 픽셀당 bite)로생각됨 
	image.set(52, 41, red);                           //51,41 번픽셀에  빨간색을  칠한다는  의미  ?
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}
