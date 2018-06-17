#include <iostream>

class Pointer{
	private :
		
		int x;
		int y;
		
	public :
		Pointer(int x, int y) {
			this->x = x;
			this->y = y;
		}
		
		int Get_x () {
			return this->x;
		}
		
		int Get_y () {
			return this->y;
		}
};

int main(void) {
	
	Pointer here(10,20);
	
	std::cout << "현재 위치 x값 : " << here.Get_x() << std::endl; 
	std::cout << "현재 위치 y값 : " << here.Get_y() << std::endl; 
	
	return 0;
}
