#include <iostream>

int main(void) {
	
	const int num = 10;
	// 변수 num을 상수화
	const int *a = &num;
	// a를 통해서 num의 값을 변경할 수 없음
	int * const b = &num;
	// 포인터 b가 상수화가 됨.
	const int * const c = &num; 
	// 포인터 c가 상수호가 되며, 포인터 c를 통해 num의 값 변경 불가
	
	num = 20;	//불가능 
	*a = 30;	//불가능 
	*b = 40;
	b = '\0';	//불가능 
	*c = 50; 	//불가능 
	return 0;
}
