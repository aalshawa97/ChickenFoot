#ifndef GAME_H
#define GAME_H 
#include"bone.h"
#include"chickenyard.h"
#include"player.h"
#include"field.h"
class game
{
public:
	void menu(ChickenYard *ChickenYardI, player *playerI, player *playerII, field *fieldI);

	void results(player* playerI, player* playerII);

	game();

	~game();



private:
	int TheWinner;
	player * player1;
	player * player2;
	ChickenYard * deck;
};

#endif