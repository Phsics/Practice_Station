#include <iostream>

namespace asd {
	
	void print(void) {
		std::cout << "asd 이름공간에서 실행되었습니다." << std::endl;
	}
}

namespace qwe {
	
	void print(void) {
		std::cout << "qwe 이름공간에서 실행되었습니다." << std::endl;
	}
}

using namespace std;

int main(void) {
	
	asd::print();
	qwe::print();
	
	cout << "std생략" << endl; 
	
	
	return 0; 
}
