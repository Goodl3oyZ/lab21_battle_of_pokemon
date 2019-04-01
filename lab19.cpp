#include "lab19.h"

int main(){
	srand(time(0));
	Unit hero,mons;
	hero.create("Hero");
	mons.create("Monster");	
	int turn_count = 1;
	char player_action = '\0',monster_action = '\0';
	int p = 0, m = 0;
	while(true){
		mons.newTurn();	
		hero.newTurn();			
		mons.showStatus();
		drawScene(player_action,p,monster_action,m);
		hero.showStatus();		
		cout << "[A] Attack [H] Heal [G] Guard [E] Exit";
		cout << "\n[Turn " << turn_count << "] Enter your action: ";
		cin >> player_action;
		player_action = toupper(player_action);
		if(player_action == 'E') break; 
		
		int temp = rand()%3;
		if(temp <= 1) monster_action = 'A';
		else if(temp == 2) monster_action = 'G';
		
		if(player_action == 'G') hero.guard();
		if(monster_action == 'G') mons.guard();
		
		if(player_action == 'H') p = hero.heal();
		
		if(player_action == 'A') p = hero.attack(mons); 
		if(monster_action == 'A') m = mons.attack(hero); 
		
		if(hero.isDead()){
			drawScene(player_action,p,monster_action,m);
			playerLose();
			break; 
		}
		
		if(mons.isDead()){
			drawScene(player_action,p,monster_action,m);
			playerWin();
			break; 
		}
		
		turn_count++;
	}
	return 0;
}
