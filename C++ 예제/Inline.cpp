#include <iostream>
#define SQUARE(x) ((x)*(x))

inline int Square(int x) {
	return x*x;
}

int main(void) {
	
	
	
	std::cout << "SQUARE(5) : " << SQUARE(5) << std::endl;
	std::cout << "SQUARE(3.1) : " << SQUARE(3.1) << std::endl;
	std::cout << "SQUARE(2.9) : " << SQUARE(2.9) << std::endl;
	std::cout << "Square(5) : " << Square(5) << std::endl;
	std::cout << "Square(3.1) : " << Square(3.1) << std::endl;
	std::cout << "Square(2.9) : " << Square(2.9) << std::endl;
	
	return 0; 
}
