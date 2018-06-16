# Practice_Station

## DownLoading Dev c++ : https://sourceforge.net/projects/orwelldevcpp/
## Current Learning : http://www.craftinginterpreters.com/introduction.html
## C# Visual Studio : https://marketplace.visualstudio.com/items?itemName=ms-vscode.csharp
## Current Learning C# : https://scottlilly.com/learn-c-by-building-a-simple-rpg-index/lesson-00-3-the-parts-of-visual-studio/
## Python : https://www.python.org
## Pycharm : https://www.jetbrains.com/pycharm/download/
## Anaconda : https://www.anaconda.com/download/

## c++ tutorial_55 : https://blog.naver.com/fb_lua/221105754379
### 멤버 이니셜 라이저란?

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
### Call by Refference & Call by Value
```cpp
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
```
### 함수 오버로딩
```cpp
#include <iostream>

int Sum(void) {
	return 0;
}

int Sum(int a) {
	return a;
}

int Sum(int a, int b) {
	return a+b;
}

int Sum(int a, int b, int c) {
	return a+b+c;
}

int Sum(int a, int b, int c, int d) {
	return a+b+c+d;
}

int main(void) {
	int a = 1, b = 2, c = 3, d = 4;
	
	std::cout << "Sum() : " << Sum() << std::endl;
	std::cout << "Sum(a) : " << Sum(a) << std::endl;
	std::cout << "Sum(a,b) : " << Sum(a,b) << std::endl;
	std::cout << "Sum(a,b,c) : " << Sum(a,b,c) << std::endl;
	std::cout << "Sum(a,b,c,d) : " << Sum(a,b,c,d) << std::endl;
	
	
	return 0; 
}
```
### 매개변수의 디폴트 값
```cpp
#include <iostream>

int Multiply(int a, int b = 2) {
	return a*b;
}

int main(void) {
	int a = 3;
	
	std::cout << "Multiply(a) : " << Multiply(a) << std::endl;
	std::cout << "Multiply(a,a) : " << Multiply(a,a) << std::endl;
	
	return 0; 
}
```
### inline 함수 :: 자료형에 구애받지 않고 함수를 만들수 있음??
```cpp
#include <iostream>
#define SQUARE(x) ((x)*(x))

inline int Square(int x) {
	return x*x;
}

int main(void) {
	
	
	
	std::cout << "SQUARE(5) : " << SQUARE(5) << std::endl;
	std::cout << "SQUARE(3.1) : " << SQUARE(3.1) << std::endl;
	std::cout << "SQUARE(2.9) : " << SQUARE(2.9) << std::endl;
	std::cout << "Square(5) : " << Square(5) << std::endl;
	std::cout << "Square(3.1) : " << Square(3.1) << std::endl;
	std::cout << "Square(2.9) : " << Square(2.9) << std::endl;
	
	return 0; 
}
```
### namespace와 using 
```cpp
#include <iostream>

namespace asd {
	
	void print(void) {
		std::cout << "asd 이름공간에서 실행되었습니다." << std::endl;
	}
}

namespace qwe {
	
	void print(void) {
		std::cout << "qwe 이름공간에서 실행되었습니다." << std::endl;
	}
}

using namespace std;

int main(void) {
	
	asd::print();
	qwe::print();
	
	cout << "std생략" << endl; 
	
	
	return 0; 
}
```
### const 사용
```cpp
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
```
### 참조자 사용법
```cpp
#include <iostream>

void Make_zero(int & a) {
	a = 0;
}


int main(void) {
	int a = 10;
	int & b = a;
	
	std::cout << "a의 값은 : " << a << std::endl;
	
	b = 20;
	
	std::cout << "a의 값은 : " << a << std::endl;

	Make_zero(a);
	
	std::cout << "a의 값은 : " << a << std::endl;
		
	return 0 ;
}
```
### 배열 
```cpp
#include <iostream>


int main(void) {
	
	int num[5] = {3,5,4,2,1};
	
	for(int i = 0; i<5; i++) {
		std::cout << "num[" << i << "] : " << num[i] << std::endl;
	}
	return 0 ;
}
```
### 배열로 문자열 표현하기
```cpp
#include <iostream>


int main(void) {
	
	char string1[6] = "Hello";
	char string2[5] = "Good";
	char string3[8] = "Morning";
	
	std::cout << string1 << std::endl;
	std::cout << string2 << " " << string3 << std::endl;

	return 0 ;
}
```
### 배열과 포인터
```cpp
#include <iostream>

int main(void) {
	
	int num[5] = {3,5,4,2,1};
	
	for(int i = 0; i<5; i++) {
		std::cout << "num[" << i << "] : " << num[i] << std::endl;
	}
	
	for(int i = 0; i<5; i++) {
		std::cout << "num[" << i << "] : " << *(num + i) << std::endl;
	}
	
	std::cout << "sizeof(num) : " << sizeof(num) << std::endl;
	std::cout << "&num : " << &num << std::endl;
	std::cout << "&(*num) : " << &(*num) << std::endl;
	std::cout << "&num[3] : " << &num[3] << std::endl;
	std::cout << "&*(num+3) : " << &*(num+3) << std::endl;
	
	
	return 0 ;
}
```
### 배열을 함수의 매개변수로 쓰는법
```cpp
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
```
### 2차원 배열
```cpp
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
```
### 구조체
```cpp
#include <iostream>

typedef struct vector{
	int x;
	int y;
	double length;
}vector;

int main(void) {
	
	vector v1 {3,4,5};
	
	std::cout << "벡터의 가로길이 : " << v1.x << std::endl; 
	std::cout << "벡터의 세로길이 : " << v1.y << std::endl; 
	std::cout << "벡터의 길이 : " << v1.length << std::endl; 
	
    
    return 0;
}
```
### 구조체를 배열로 사용하기
```cpp
#include <iostream>

struct card {
	char shape[10];
	int number;
	
};

void printCard(card * a,int count) {
	for(int i=0;i<count;i++){
		std::cout << a[i].shape << ". " <<a[i].number << std::endl;
	}
}


int main(void){

	card trump[3] = {
		{"heart",3},
		{"diamond",10},
		{"spade",7}
	};

	printCard(trump,sizeof(trump)/sizeof(trump[0]));


	return 0;
}
```
### 구조체 포인터를 가진 구조체
```cpp
#include <iostream>

struct card {
	char shape[10];
	int number;
	card * nextcard;
	
};

void printCard(card *a) {
	
	while(a->nextcard != '\0'){
		std::cout << a->shape << ". " << a->number << std::endl;
		a = (a->nextcard);
	}
}


int main(void){

	card trump[4] = {
		{"heart",3,'\0'},
		{"diamond",10,'\0'},
		{"spade",7,'\0'},
		{"spade",4,'\0'}
	};
	trump[0].nextcard = & trump[2];
	trump[2].nextcard = & trump[1];
	trump[1].nextcard = & trump[3];

	printCard(&trump[0]);


	return 0;
}
```
### 구조체에 함수 넣기
```cpp
#include <iostream>
#include <math.h>

struct vector {
	int x;
	int y;
	double length;
	
	void initial_length() {
		length = sqrt(pow((double)x,2.0)+pow((double)y,2.0));
	}
	
	void print_info() {
		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl;
		std::cout << "length = " << length << std::endl;
	}
};


int main(void){
	vector vector1;
	vector1.x = 3;
	vector1.y = 11;
	vector1.initial_length();
	vector1.print_info();
	
	return 0;
}
```
### 동적 할당과 메모리 해제
```cpp
#include <iostream>

int main(void){
	
	int *a = new int;
	
	if(a==NULL){
		std::cout << "메모리 할당 실패" <<std::endl;
		return -1;
	}
	
	std::cout << "a의 위치 : " << &a << std::endl;
	*a = 10;
	std::cout << "a초기화 값 : " << *a << std::endl;	
	
	delete a;	

	
	return 0;
}
```
### 동적배열
```cpp
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
```
### 클래스 사용하기
```cpp
#include <iostream>

class user {
	private :
		int age;
		char const *name = NULL;
	
	public :
	void Set_age(int a) {
		age = a;
	}
	
	void Set_name(char const * a) {
		name = a;
	}
	
	int Get_age() {
		return age;
	}
	
	char const *Get_name() {
		return name;
	}
};




int main(void){
	
	user a;
	a.Set_age(10);
	a.Set_name("현명");
	std::cout << "a의 이름은 : " << a.Get_name() << std::endl; 
	std::cout << "a의 나이는 : " << a.Get_age() << std::endl; 
	
	return 0;
}
```
### 생성자
```cpp
#include <iostream>

class user {
	private :
		
		int age;
		char const *name = NULL;
	
	public :
		
		user() {
			age = 0;
			name = "noname";
		}
		
		user(int a, char const *b) {
			age = a;
			name = b;
		}
		
		void Set_age(int a) {
			age = a;
		}
	
		void Set_name(char const * a) {
			name = a;
		}
	
		int Get_age() {
			return age;
		}
	
		char const *Get_name() {
			return name;
		}
};




int main(void){
	
	user a(10,"현명");
	std::cout << "a의 이름은 : " << a.Get_name() << std::endl; 
	std::cout << "a의 나이는 : " << a.Get_age() << std::endl; 
	
	return 0;
}
```
