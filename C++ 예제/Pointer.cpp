#include <iostream>

int main(void) {
	
	int a = 10;
	int *b = &a;
	
	std::cout << "a값 : " << a << std::endl;
	std::cout << "*b값 : " << *b << std::endl;
	*b = 20;
	std::cout << "a값 : " << a << std::endl;
	std::cout << "*b값 : " << *b << std::endl; 
	
}
