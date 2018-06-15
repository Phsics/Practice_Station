#include <iostream>

void swap(int a, int b) {
	
	int temp;
	temp = a;
	a = b;
	b = temp;
		
}

void real_swap(int *a, int *b) {
	
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
		
}


void printNumber(int a, int b) {
	std::cout << "a : " << a << " // b : " << b << std::endl; 

}
int main(void) {
	
	int a = 10;
	int b = 20;
	
	printNumber(a,b);
	swap(a,b);
	printNumber(a,b);
	real_swap(&a,&b);
	printNumber(a,b);
	
	
	
	return 0; 
}
