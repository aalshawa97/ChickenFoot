#include "game.h"

game::game(){}

game::~game(){}

void game::menu(ChickenYard* ChickenYardI, player* playerI, player* playerII, field *fieldI)
{

	int i = 0;
	int j = 0;
	//true is for player 1 false is for player 2
	bool WhoseTurn = true;
	//if the player trys to place a card and cant find a match we set this to true
	bool NeedToDrawP1 = false;
	bool NeedToDrawP2 = false;
	ChickenYardI->shuffle();
	//The Intro
	cout << "Welcome my friends, the table is set up. Please take a seat and make yourself comfortable.\n"
		<< "Now we want a nice and clean game fellas , so if you cheat you will be disqualifed. My name\n"
		<< "is Joe and I will be your dealer tonight. Each of you will now be handed 7 cards to start\n"
		<< "the game. Have fun.\n";

	ChickenYardI->firstDrawCard(playerI);
	ChickenYardI->firstDrawCard(playerII);
	playerI->setScore(7);
	playerII->setScore(7);

	//Determine the largest doubble from player's hand and place it on field (don't forget to decrement player's points)

	//my menu
	do{
		cout << endl;
		if (WhoseTurn == true)
		{
			cout << "it is player one's turn" << endl;
			NeedToDrawP1 = fieldI->matchBone(playerI);
			//(field class function to try to match)
		}
		else
		{
			cout << "it is player two's turn" << endl;
			NeedToDrawP2 = fieldI->matchBone(playerII);
			//(field class function to try to match)
		}

		cout << "Trying to Match card for you.." << endl;

		//player1
		if (NeedToDrawP1 == false && WhoseTurn == true)
		{
			cout << "Player 1 matched a card" << endl;
			i--;
			playerI->setScore(7 + i);
		}

		//if you couldn't match a card then you need to draw one
		if (NeedToDrawP1 == true && WhoseTurn == true)
		{
			cout << "Player 1 could not match a card" << endl;
			if (ChickenYardI->isDeckEmpty() == 1)
			{
				return;
			}
			cout << "Drawing a card for you.." << endl;


			ChickenYardI->drawCard(playerI);
			i++;
			playerI->setScore(7 + i);
			cout << "Now trying to match a card again.." << endl;
			//try to match a card again - NeedToDraw will be changed
			NeedToDrawP1 = fieldI->matchBone(playerI);


			//now if that a card was matched tell them
			if (NeedToDrawP1 == false)
			{
				cout << "The card you drew matched!\n";
			}
			else
			{
				cout << "The card you drew didn't match..\n";
			}
		}

		//player 2
		if (NeedToDrawP1 == false && WhoseTurn == false)
		{
			cout << "Player 2 matched a card" << endl;
			j--;
			playerII->setScore(7 + j);
		}

		if (NeedToDrawP2 == true && WhoseTurn == false)
		{
			cout << "Player 2 could not match a card" << endl;
			if (ChickenYardI->isDeckEmpty() == 1)
			{
				return;
			}
			cout << "Drawing a card for you.." << endl;


			ChickenYardI->drawCard(playerII);
			j++;
			playerII->setScore(7 + j);
			cout << "Now trying to match a card again.." << endl;
			//try to match a card again - NeedToDraw will be changed
			NeedToDrawP2 = fieldI->matchBone(playerII);

			//now if that a card was matched tell them
			if (NeedToDrawP2 == false)
			{
				cout << "The card you drew matched!\n";
			}
			else
			{
				cout << "The card you drew didn't match..\n";
			}
		}

		if (WhoseTurn == true)

			WhoseTurn = false;
		else
			WhoseTurn = true;

		cout << "----------------------------------------------------------\n\n"
			<< "Scoreboard:\n\n"
			<< "Player 1: " << playerI->getScore() << endl
			<< "Player 2: " << playerII->getScore() << endl << endl
			<< "----------------------------------------------------------\n";

	} while (fieldI->isHandEmpty(playerI) == 0 && fieldI->isHandEmpty(playerII) == 0);

	cout << "The game is now over." << endl;



}


void game::results(player *playerI, player *playerII)
{
	if (playerI->getScore() < playerII->getScore())
	{
		cout << "The winner is player 1" << endl;
	}
	else
	{
		cout << "The winner is player 2" << endl;
	}
	cout << "Goodbye" << endl;
}
























