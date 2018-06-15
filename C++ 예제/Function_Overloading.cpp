#include <iostream>

int Sum(void) {
	return 0;
}

int Sum(int a) {
	return a;
}

int Sum(int a, int b) {
	return a+b;
}

int Sum(int a, int b, int c) {
	return a+b+c;
}

int Sum(int a, int b, int c, int d) {
	return a+b+c+d;
}

int main(void) {
	int a = 1, b = 2, c = 3, d = 4;
	
	std::cout << "Sum() : " << Sum() << std::endl;
	std::cout << "Sum(a) : " << Sum(a) << std::endl;
	std::cout << "Sum(a,b) : " << Sum(a,b) << std::endl;
	std::cout << "Sum(a,b,c) : " << Sum(a,b,c) << std::endl;
	std::cout << "Sum(a,b,c,d) : " << Sum(a,b,c,d) << std::endl;
	
	
	return 0; 
}
