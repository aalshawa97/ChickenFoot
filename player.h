#ifndef PLAYER_H
#define PLAYER_H 

#include "bone.h"

class player
{
public:
	player();
	//a copy constructor
	player(bone* ahand);
	~player();

 int getScore();
	void setScore(int newScore);
	void setHand(bone * newHand);

	vector<bone*>::iterator getBoneFirst();     //Added
	vector<bone*>::iterator getBoneEnd();	// Added
	//void incrementPoints();
	 int fLargeDouble();	//virtual later
	bone *& fDouble(int & index);
	bool removeBone(int position, bone *& aBone);
	void showHand() const;
	int size() const;
	int getTop(int index);
	int getBot(int index);
	void setFree(int index, int i);   //int i is used for the other setFree() in bone.h
	vector<bone*> getHand();
	void deleteBone(vector<bone*>::iterator it);
	virtual string printName() = 0;

private:
	int score;
	vector<bone*> hand;

};

class player1 : public player
{
public:
	string printName();

private:
	string name="Player 1";
};

class player2 : public player
{
public:
	string printName();

private:
	string name = "Player 2";

};

#endif
