#include <iostream>

void Make_zero(int & a) {
	a = 0;
}


int main(void) {
	int a = 10;
	int & b = a;
	
	std::cout << "a의 값은 : " << a << std::endl;
	
	b = 20;
	
	std::cout << "a의 값은 : " << a << std::endl;

	Make_zero(a);
	
	std::cout << "a의 값은 : " << a << std::endl;
		
	return 0 ;
}
