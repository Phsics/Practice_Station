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
