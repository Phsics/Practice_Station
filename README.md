# Practice_Station

## DownLoading Dev c++ : https://sourceforge.net/projects/orwelldevcpp/
## Current Learning : http://www.craftinginterpreters.com/introduction.html
## C# Visual Studio : https://marketplace.visualstudio.com/items?itemName=ms-vscode.csharp
## Current Learning C# : https://scottlilly.com/learn-c-by-building-a-simple-rpg-index/lesson-00-3-the-parts-of-visual-studio/
## Python : https://www.python.org
## Pycharm : https://www.jetbrains.com/pycharm/download/
## Anaconda : https://www.anaconda.com/download/

## c++ tutorial : https://blog.naver.com/fb_lua/220820422079
## 현재 배우고 있는것 : C 언어 튜토리얼 리눅스의 쉘을 C언어로 만들기

### Hello World 출력하기
```cpp
#include <iostream>

int main(void)
{
	std::cout << "Hello World" << std::endl;    //Hello World 출력
	
	return 0;
}
```

### 변수선언 및 출력
```cpp
#include <iostream>

int main(void)
{
	int nData = 10;
	int nData2;
	char cData = 'a';
	float fData = 1.50f;
	double dData = 1.50;
	
	nData2 = 20;
	
	std::cout << nData << " " << nData2 << std::endl;
	std::cout << cData << std::endl;
	std::cout << fData << std::endl;
	std::cout << dData << std::endl;
	
	return 0;
}
```
### 입력
```cpp
#include <iostream>

int main(void){

	int nData;
	
	std::cout <<"Please input a number : ";
	std::cin >>nData;
	std::cout << "Number : " << nData << std::endl;
	
	return 0;
}
```
### if문 사용
```cpp
#include <iostream>

int main(void){

	int nData = 10;
	
	if (nData == 10){
		std::cout << "right" <<std::endl;
	}	
	else {
		std::cout << "wrong" <<std::endl;
	}
	return 0;
}
```
### switch문 사용
```cpp
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
```
### while문 사용
```cpp
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
```
### for문 사용
```cpp
#include <iostream>

int main(void) {
	
	for(int i=0;i<10;i++){
		std::cout << i*2 << std::endl;	
	}
}
```
### 포인터 변수
```cpp
#include <iostream>

int main(void) {
	
	int a = 10;
	int *b = &a;
	
	std::cout << "a값 : " << a << std::endl;
	std::cout << "*b값 : " << *b << std::endl;
	*b = 20;
	std::cout << "a값 : " << a << std::endl;
	std::cout << "*b값 : " << *b << std::endl; 
	
}
```
### sizeof 사용하기
```cpp
#include <iostream>

int main(void) {
	
	int a = 10;
	int *b = &a;
	char c = 'a';
	char *d = &c;
	
	std::cout << "a의 크기 : " << sizeof(a) << std::endl;
	std::cout << "b의 크기 : " << sizeof(b) << std::endl;
	std::cout << "c의 크기 : " << sizeof(c) << std::endl;
	std::cout << "d의 크기 : " << sizeof(d) << std::endl;
	 
	
	
}
```
### 함수
```cpp
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
```
