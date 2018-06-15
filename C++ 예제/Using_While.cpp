#include <iostream>

int main(void) {
	
	int i = 1;
	
	while(i<=10){
		if(i%3 == 0){
			i++;
			std::cout << '*' << std::endl;
			continue;
		}
		std::cout << i << std::endl;
		i++;	
	}
	
	return 0;
}
