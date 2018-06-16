#include <iostream>

void printData(int * data) {
    int n = sizeof(data)/sizeof(*data);
    for(int i=0;i<n;i++){
        std:cout << "데이터 " << i << "번 : " << data[i] << std::endl;
    }
}

int main(void) {

    int data[5] = {10,20,30,40,50};
    
