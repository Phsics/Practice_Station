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
