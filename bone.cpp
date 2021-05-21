#include "bone.h"
bone::bone()
{
	/* initialize random seed: */
	srand(time(NULL));
	top = rand() % 9 + 1;
	bottom = rand() % 9 + 1;
}

bone::bone(int top, int bottom)
{
	this->top = top;
	int bottomCopy = bottom;
}

bone::~bone()
{
	//there is nothing for me to delete 
}

int bone::getTop()
{
	return top;
}

int bone::getBottom()
{
	return bottom;
}

void bone::showTop(int top)
{
	cout << "The top of the card is " << top << endl;
}

void bone::showBottom(int bottom)
{
	cout << "The bottom of the card is " << bottom << endl;
}

int bone::getFree()
{
	return free;

}

void bone::setFree(int i)
{
	//1 is for top
	if (i == 1)
		free = top;
	else
		free = bottom;
}

void bone::setYesDNo(int i)
{
	if (i == 0)	//represents a double
		yesDno = 0;
	else
		yesDno = 1;
}