//Abdullah Alshawa and Tenzin Shakya 
//6/22/15
//Project 1
#include "player.h"
#include "bone.h"
#include "chickenyard.h"
#include "game.h"
#include "field.h"

int main()
{
	game gameI;
	ChickenYard * ChickenYardI=new ChickenYard;
	player1 * playerI= new player1;
	player2 * playerII=new player2;
	field * fieldI=new field;
	gameI.menu(ChickenYardI, playerI, playerII, fieldI);

	gameI.results(playerI, playerII);

	getchar();
	getchar();
	return 0;
}