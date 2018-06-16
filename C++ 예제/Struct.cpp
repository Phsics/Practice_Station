#include <iostream>

typedef struct vector{
	int x;
	int y;
	double length;
}vector;

int main(void) {
	
	vector v1 {3,4,5};
	
	std::cout << "벡터의 가로길이 : " << v1.x << std::endl; 
	std::cout << "벡터의 세로길이 : " << v1.y << std::endl; 
	std::cout << "벡터의 길이 : " << v1.length << std::endl; 
	
    
    return 0;
}
