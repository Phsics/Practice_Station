#include <iostream>

int main(void){

	int nData;
	std::cout <<"Please input a number (1~5) : " ;
	std::cin >> nData;
	
	if (nData < 1 || nData > 5) {
		std::cout <<"Err : wrong value" << std::endl;
		return -1;
	}
	
	switch(nData){
		case 1 :
			std::cout << "value : 1" <<std::endl;
			break;
		case 2 :
			std::cout << "value : 2" <<std::endl;
			break; 
		case 3 :
			std::cout << "value : 3" <<std::endl;
			break; 
		case 4 :6
			std::cout << "value : 4" <<std::endl;
			break; 
		case 5 :
			std::cout << "value : 5" <<std::endl;
			break; 
 	}
	return 0;
}
