#include <iostream>

int Multiply(int a, int b = 2) {
	return a*b;
}

int main(void) {
	int a = 3;
	
	std::cout << "Multiply(a) : " << Multiply(a) << std::endl;
	std::cout << "Multiply(a,a) : " << Multiply(a,a) << std::endl;
	
	return 0; 
}
