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
