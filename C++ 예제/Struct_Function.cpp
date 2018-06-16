#include <iostream>
#include <math.h>

struct vector {
	int x;
	int y;
	double length;
	
	void initial_length() {
		length = sqrt(pow((double)x,2.0)+pow((double)y,2.0));
	}
	
	void print_info() {
		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl;
		std::cout << "length = " << length << std::endl;
	}
};


int main(void){
	vector vector1;
	vector1.x = 3;
	vector1.y = 11;
	vector1.initial_length();
	vector1.print_info();
	
	return 0;
}
