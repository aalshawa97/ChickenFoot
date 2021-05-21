#ifndef CHICKENYARD_H
#define CHICKENYARD_H

#include "bone.h"
#include "player.h"

class ChickenYard
{
public:
	ChickenYard();
	//a copy constructor
	ChickenYard(vector<bone*> deck);
	~ChickenYard();
	int isDeckEmpty();
	int drawCard(player*& playerI);
	void firstDrawCard(player*& playerI);
	int getDeckSize();
	void shuffle();
private:
	vector<bone*> deck;
};

#endif