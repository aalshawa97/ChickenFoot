#ifndef BONE_H
#define BONE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>    // std::random_shuffle
#include <vector> 

using namespace std;

class bone
{
public:
	bone();
	//copy constructor
	bone(int top, int bottom);
	~bone();
	int getTop();
	int getBottom();
	void showTop(int top);
	void showBottom(int bottom);
	int getFree();
	void setFree(int i);
	void setYesDNo(int i);

private:
	int free;
	int top;
	int bottom;
	int yesDno;
};

class player1Card : public bone
{

};

class player2Card : public bone
{

};

#endif