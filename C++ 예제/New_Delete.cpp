#include <iostream>

int main(void){
	
	int *a = new int;
	
	std::cout << "a의 위치 : " << &a << std::endl;
	*a = 10;
	std::cout << "a초기화 값 : " << *a << std::endl;	
	
	delete a;	

	
	return 0;
}
