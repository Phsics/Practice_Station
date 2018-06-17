#include <iostream>

class User {
	private :
		const int sirial_number ;
		int age;
		char const *name = NULL;
		
	public :
		User(int a, char const *b,int c) : name(b),sirial_number(c){
			age = a;
		}
		
		char const *Get_Name() {
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
};

int main(void) {
	User abc(10,"현명",300);
	std::cout << "이름 : " <<abc.Get_Name() << std::endl;
	std::cout << "나이 : " <<abc.Get_Age() << std::endl;
	abc.Set_Age(20);
	std::cout << "나이 : " <<abc.Get_Age() << std::endl;
	std::cout << "시리얼 넘버 : " <<abc.Get_Sirial_Number() << std::endl;
	
	return 0;
}
