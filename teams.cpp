#include <unistd.h>
#include <iostream>
#include <stdlib.h> 	// srand
#include<time.h> 
using namespace std;

int hp_1 = 100;
int dmg_1 = 10;
int hp_2 = 100;
int dmg_2 = 10;

void attack(int ally_damage, int *enemy_health) { 	// attacks the enemy team for random amount of damage
	int cur_damage = ally_damage + rand() % 10;
	*enemy_health = *enemy_health - cur_damage;
};

void heal(int *ally_health) {						// heals team for random amount of health, less than damage
	*ally_health = *ally_health + rand() % 10;
};

int main() {
	srand(time(0)); // for true randomness
	int round_counter = 0;
	do {
		round_counter++;
		attack(dmg_1, &hp_2);	// at first each team damage each other
		attack(dmg_2, &hp_1);	// then checks current hp

		cout << "Round " << round_counter << " results are: \n" << "Team 1 health:" << hp_1 << "\n" << "Team 2 health:" << hp_2 << "\n";
		if ( hp_1 <= 0 && hp_2 <= 0)
		{
			cout << "It's a tie! \n";
			break;
		}else
		if (hp_1 <= 0)
		{
			cout << "Team 2 won! \n";
			break;
		}
		else if (hp_2 <= 0)
		{
			cout << "Team 1 won! \n";
			break;
		}
		heal(&hp_1);	// after checkup teams can heal
		heal(&hp_2);
	} while (1);
	exit(0);
}
