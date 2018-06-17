#include <iostream>
#include <cstring>

class User {
	private :
		const int sirial_number ;
		int age;
		char *name ;
		
	public :
		User(int a, char *b,int c) :sirial_number(c){
			int len = sizeof(b);
			name = new char[len];
			strcpy(name,b);
			age = a;
		}
		
		char *Get_Name() {
			return name;
		}
		
		int Get_Age() {
			return age;
		}
		
		int Get_Sirial_Number() {
			return sirial_number;
		}
		
		void Set_Age(int a) {
			age = a;
		}
		~User() {
			delete[] name;
			std::cout << "소멸자 실행" <<std::endl;
		}
};

int main(void) {
	char a[5] = "현명"; 
	User abc(10,a,300);
	std::cout << "이름 : " <<abc.Get_Name() << std::endl;
	std::cout << "나이 : " <<abc.Get_Age() << std::endl;
	abc.Set_Age(20);
	std::cout << "나이 : " <<abc.Get_Age() << std::endl;
	std::cout << "시리얼 넘버 : " <<abc.Get_Sirial_Number() << std::endl;
	
	return 0;
}
