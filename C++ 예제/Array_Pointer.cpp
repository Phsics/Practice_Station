#include <iostream>

int main(void) {
	
	int num[5] = {3,5,4,2,1};
	
	for(int i = 0; i<5; i++) {
		std::cout << "num[" << i << "] : " << num[i] << std::endl;
	}
	
	for(int i = 0; i<5; i++) {
		std::cout << "num[" << i << "] : " << *(num + i) << std::endl;
	}
	
	std::cout << "sizeof(num) : " << sizeof(num) << std::endl;
	std::cout << "&num : " << &num << std::endl;
	std::cout << "&(*num) : " << &(*num) << std::endl;
	std::cout << "&num[3] : " << &num[3] << std::endl;
	std::cout << "&*(num+3) : " << &*(num+3) << std::endl;
	
	
	return 0 ;
}
