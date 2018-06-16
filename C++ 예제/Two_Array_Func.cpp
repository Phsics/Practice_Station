#include <iostream>

void printData(int (*data)[5],int count) {
	
    for(int i=0;i<count;i++){
    	for(int j=0;j<5;j++){
        std::cout << "데이터 " << i*5+j+1 << "번 : " << data[i][j] << std::endl;
    	}
	}
}

int main(void) {

    int data[4][5] = 
	{1 , 2 , 3 , 4 , 5,
     6 , 7 , 8 , 9 , 10,
     11, 12, 13, 14, 15,
     16, 17, 18, 19, 20};
     
    printData(data,sizeof(data)/sizeof(int)/5);
     
     
    return 0;
}
