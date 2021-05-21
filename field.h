#ifndef FIELD_H
#define FIELD_H

#include "bone.h"
#include "player.h"
#include "chickenyard.h"
#include <list>

struct node
{
	bone * aBone;
	node * left;
	node * middle;
	node * right;
	//bool avail[4];
};

class field
{
public:
	field();
	~field();
	void PlaceFirstCard(player * aPlayer, player * bPlayer, ChickenYard*& ChickenYardI);
	int add(bone* link, int index);
	int remove(bone * link, int index);

	int matchBone(player * aPlayer);
	int FinishThe;
	//int isDeckEmpty(ChickenYard * aDeck);
	int isHandEmpty(player * aPlayer);

private:
	int firstBone;
	//the map is just set to the amount of cards in the deck
	list<node> map[30];
	vector<node*> frees;
	node * currChicFt;
	node * head;
	int FinishedFoot;
	int mapIndexCurr;	//current for insertion point
	int mapIndex;	//available indexes
	//node* currDouble;
	//node* currSingle;

};
#endif