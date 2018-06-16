#include <iostream>

void printData(int * data,int count) {
	
    for(int i=0;i<count;i++){
        std::cout << "데이터 " << i+1 << "번 : " << data[i] << std::endl;
    }
}

int main(void) {

    int data[5] = {10,20,30,40,50};
    printData(data,sizeof(data)/sizeof(int));
    return 0;
}
