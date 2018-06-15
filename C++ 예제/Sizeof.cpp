#include <iostream>

int main(void) {
	
	int a = 10;
	int *b = &a;
	char c = 'a';
	char *d = &c;
	
	std::cout << "a의 크기 : " << sizeof(a) << std::endl;
	std::cout << "b의 크기 : " << sizeof(b) << std::endl;
	std::cout << "c의 크기 : " << sizeof(c) << std::endl;
	std::cout << "d의 크기 : " << sizeof(d) << std::endl;
	 
	
	
}
