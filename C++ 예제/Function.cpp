#include <iostream>

void print(void) {
	
	std::cout << "print 함수가 실행되었습니다." <<std::endl; 
	
}

void printName(char *a) {
	std::cout << "당신의 이름은 " << a << " 입니다." << std::endl; 

}
int main(void) {
	
	print();
	print();
	print();
	printName("현명"); 
	
	return 0; 
}
