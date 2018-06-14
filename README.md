# Practice_Station

## DownLoading Dev c++ : https://sourceforge.net/projects/orwelldevcpp/
## Current Learning : http://www.craftinginterpreters.com/introduction.html
## C# Visual Studio : https://marketplace.visualstudio.com/items?itemName=ms-vscode.csharp
## Current Learning C# : https://scottlilly.com/learn-c-by-building-a-simple-rpg-index/lesson-00-3-the-parts-of-visual-studio/
## Python : https://www.python.org
## Pycharm : https://www.jetbrains.com/pycharm/download/
## Anaconda : https://www.anaconda.com/download/

## https://blog.naver.com/tipsware/221216558792
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
