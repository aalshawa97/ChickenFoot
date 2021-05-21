#include "player.h"

player::player()
{
	score = 0;
}

player::player(bone* aHand)
{
	//hand(aHand);	//copying into deck or creating a seperate copy vector?
}

player::~player()
{
	/*	Used to delete non-pointer vector
	for (int i = 0; i < hand.size(); i++)
	{
	hand.pop_back();
	}
	*/

	for (vector<bone*>::iterator it = hand.begin(); it != hand.end(); it++)
	{
		delete *it;
	}
}

int player::getScore()
{
	return score;
}

void player::setScore(int newScore)
{
	score = newScore;
}

void player::setHand(bone * newHand)
{
	hand.push_back(newHand);
}

//Added
//vector<string>::iterator Union::types()
vector<bone*>::iterator player::getBoneFirst()
{
	return hand.begin();
}

//Added
vector<bone*>::iterator player::getBoneEnd()
{
	return hand.end();
}


void player::showHand() const
{
	for (int i = 0; i < hand.size(); i++)
	{
		cout << "Top: " << hand[i]->getTop() << endl;
		cout << "Bottom: " << hand[i]->getBottom() << endl << endl;
	}
}
vector<bone*> player::getHand()
{
	return hand;
}
bool player::removeBone(int position, bone *& aBone)
{
	if (position < 0 || position >= hand.size())
		return false;
	int index = 0;
	for (vector<bone*>::iterator it = hand.begin(); it != hand.end(); it++, index++)
	{
		if (index == position)
		{
			aBone = *it;
			hand.erase(it);
			break;
		}
	}

	return true;
}

int player::size() const
{
	return hand.size();
}

//finds the largest double
//!!!!! REVISE LATER !!!!!!
 int player::fLargeDouble()
{
	int index = 0;
	int rVal = 0;
	int lVal = 0;
	bool sVal = true;

	for (vector<bone*>::iterator it = hand.begin(); it != hand.end(); it++, index++)
	{
		//checks for the first index counter
		if (hand[0]->getTop() == hand[0]->getBottom() && sVal == true)
		{
			index++;
			sVal = false;
		}
		if (hand[index]->getTop() == hand[index]->getBottom())
		{

			if (hand[lVal]->getTop() < hand[index]->getTop())
			{

			}
		}

		rVal = 1;
	}

	if (rVal == 0)
	{

		cout << "This player doesn't have a double" << endl;
		return rVal;
	}
	return hand[index]->getTop();
}

//finds the largest double
bone *& player::fDouble(int &index)
{
	bone * aMatch;
	//int index = 0;
	int rVal = 0;
	int lVal = 0;
	bool sVal = true;

	for (vector<bone*>::iterator it = hand.begin(); it != hand.end(); it++, index++)
	{
		//checks for the first index counter
		if (hand[0]->getTop() == hand[0]->getBottom() && sVal == true)
		{
			index++;
			sVal = false;
		}
		if (hand[index]->getTop() == hand[index]->getBottom())
		{
			if (hand[lVal]->getTop() < hand[index]->getTop())
			{
				aMatch = *it;
			}
		}

		rVal = 1;
	}

	if (rVal == 0)
	{

		cout << "This player doesn't have a double" << endl;
		cout << "The player has a single" << endl;
	}
	return aMatch;
}

int player::getTop(int index)
{
	return hand[index]->getTop();
};

int player::getBot(int index)
{
	return hand[index]->getBottom();
};

void player::setFree(int index, int i)
{
	hand[index]->setFree(i);

	return;
};

void player::deleteBone(vector<bone*>::iterator it)
{
	hand.erase(hand.begin() );//not cool !!!!
}

 string player1::printName()
{
	return name;
}

string player2::printName()
{
	return name;
}