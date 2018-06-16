#include <iostream>

int main(void){
	
	int *p = NULL;
	int count;
	int sum=0;
	
	std::cout << "몇 개의 숫자를 더하시겠습니까? : " ;
	std::cin >> count;
	
	if(count <= 0 ) {
		std::cout << "입력된 값이 잘못 되었습니다." << std::endl;
		return -1;
	}
	
	p = new int[count];
	
	if(p == NULL) {
		std::cout << "메모리 할당 오류 " << std::endl;
		return -1;
	}
	
	for(int i = 0;i<count;i++){
		std::cout<< i+1 << "번째 숫자를 입력하시오 : ";
		std::cin >>  p[i];
		sum += p[i];
	}
	std::cout<< "총 합은 : ";
	for(int i = 0;i<count;i++){
		std::cout<<p[i] <<" + ";
	}
	std::cout<< "= " << sum << std::endl;
	
	return 0;
}
