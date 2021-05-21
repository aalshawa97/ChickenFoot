#include "chickenyard.h"

//Remember to shuffle
ChickenYard::ChickenYard()
{
	for (int i = 0; i < 30; i++)
	{
		bone* tempplayer1Card;
		deck.push_back(tempplayer1Card);
	}
}

int ChickenYard::getDeckSize()
{
	return deck.size();
}

void ChickenYard::shuffle()
{
	random_shuffle(deck.begin(), deck.end());
}
ChickenYard::ChickenYard(vector<bone*> deck)
{
	vector<bone*> copyDeck(deck);
}

ChickenYard::~ChickenYard()
{
	for (int i = 0; i < deck.size(); i++)
	{
		deck.pop_back();
	}
}

//Draws up to seven cards
void ChickenYard::firstDrawCard(player*& playerI)
{
	cout << "You have currently no cards. 7 Cards will be drawn from you for your first turn" << endl;
	for (int i = 0; i < 7; i++)
	{
		playerI->setHand(*deck.begin());	//needed to return value
		deck.erase(deck.begin());
	}
}

//Draws up one card at a time
int ChickenYard::drawCard(player*& playerI)
{
	if (!deck.empty())
	{
		cout << "Player is drawing a card" << endl;
		int i = 0;
		playerI->setHand(*deck.begin());


		return 1;
	}
	else
	{
		return 0;
	}
}

int ChickenYard::isDeckEmpty()
{
	if (deck.empty())
	{
		cout << "The deck is empty" << endl;
		return 1;

	}
	else
	{
		cout << "The deck is not empty" << endl;
		return 0;
	}

}
