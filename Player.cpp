#include <iostream>

int main(void){
	std::cout << "Player..." << std::endl;
	Player player1("현명","도적");
	return 0;
}

void Player{
	void Player(char *name, char *job){
		Player.HP = 50;
		Player.Max_HP = 50;
		Player.MP = 0;
		Player.Max_MP = 0;
		Player.name = name;
		Player.damage = 1.0;
		Player.masic_power = 0;
		Player.armor = 0 ;
		Player.masic_resistance = 0;
		Player.exp = 0;
		Player.Max_exp = 10;
		Player.job = job;
		Player.level = 1;
		Player.agility = 0.5;
		Player.utility = 300.0;
	}
	int HP;
	int Max_HP;
	int MP;
	int Max_MP;
	char name[10];
	float damage;
	float masic_power;
	int armor;
	int masic_resistance;
	int exp;
	int Max_exp;
	char job[10];
	int level;
	float agility;
	float utility;
	
}
