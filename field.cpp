#include "bone.h"
#include "field.h"

field::field()
{
	currChicFt = NULL;
	FinishedFoot == 0;
	mapIndex = 1;
	mapIndexCurr = 0;
	firstBone = 0;
}

field::~field()
{

}


int field::add(bone* link, int index)
{
	node * temp = new node;

	temp->aBone = new bone;
	temp->aBone = link;

	map[index].push_front(*temp);
	return 0;
}


int field::isHandEmpty(player * aPlayer)
{
	if (aPlayer->getScore() == 0)
	{
		
		return 1;
	}
	else
	{
		
		return 0;
	}
}

void field::PlaceFirstCard(player * aPlayer, player * bPlayer, ChickenYard*& ChickenYardI)
{
	int j = 0, index, botOrTop;
	int z = 0;
	while (aPlayer->fLargeDouble() == 0 && bPlayer->fLargeDouble() == 0)
	{
		ChickenYardI->drawCard(aPlayer);
		cout << "player 1 drew a card" << endl;
		aPlayer->setScore(aPlayer->getScore() + 1);
		if (aPlayer->fLargeDouble() == 1)
		{
			cout << "Now player 1 has a double" << endl;
			

			break;
		}
		ChickenYardI->drawCard(bPlayer);
		cout << "player 2 drew a card" << endl;
		bPlayer->setScore(bPlayer->getScore() + 1);
		if (bPlayer->fLargeDouble() == 1)
		{
			cout << "Now player 2 has a double" << endl;
			
			break;
		}

	}

	if (aPlayer->fLargeDouble() > bPlayer->fLargeDouble())
	{	
		cout << "player one has the largest double" << endl;
		//pushing back the first dominio of the game
		node * temp = new node;
		temp->aBone = new bone;
		temp->aBone = aPlayer->fDouble(index);
		map[mapIndex].push_back(*temp);
		
		
		for (vector<bone*>::iterator itB = aPlayer->getBoneFirst(); itB != aPlayer->getBoneEnd(); itB++, index++)	//Not sure why errors are showing up
		{
			frees.push_back(temp);
			currChicFt = temp;
		}

	
		if (aPlayer->fLargeDouble() == aPlayer->getBot(index))
		{
			botOrTop = 1;		//changed - opposite is correct
			aPlayer->setFree(index, botOrTop);
		}
		else if (aPlayer->fLargeDouble() == aPlayer->getTop(index))
		{
			botOrTop = 0;		
			aPlayer->setFree(index, botOrTop);
		}

		
		aPlayer->setScore(aPlayer->getScore() - 1);

	}
	else
	{
		cout << "player two has the largest double" << endl;
		//pushing back the first dominio of the game
		node * temp = new node;
		temp->aBone = new bone;
		temp->aBone = aPlayer->fDouble(index);
		map[mapIndex].push_back(*temp);
		mapIndex++;

		for (int i = 0; i <= 3; i++)
		{
			
			if (bPlayer->fLargeDouble() == bPlayer->getBot(index))
			{
				botOrTop = 1;
				bPlayer->setFree(index, botOrTop);
			}
			else if (bPlayer->fLargeDouble() == bPlayer->getTop(index))
			{
				botOrTop = 0;
				bPlayer->setFree(index, botOrTop);
			}
			//map[i].push_back(*temp);   //<------- changed
			bPlayer->setScore(bPlayer->getScore() - 1);
		}
	}
	return;

}

//Added
int field::matchBone(player * aPlayer)
{
	//for the first bone played onto the field 
	if (firstBone != NULL)
	{
		if (firstBone == 3)
		{
			firstBone = NULL;
			firstBone = 0;
			cout << "first 4 cards have been attached" << endl;
			mapIndex++;
			return 0;
		}

		for (vector<bone*>::iterator itB = aPlayer->getBoneFirst(); itB != aPlayer->getBoneEnd(); itB++)	//Not sure why errors are showing up
		{
			for (vector<node*>::iterator itN = frees.begin(); itN != frees.end(); itN++)
			{
				//check if that is double
				if ((*itB)->getTop() == (*itB)->getBottom())
				{
					cout << "you can only place a single here you tried to place a double" << endl;
					break;
				}

				else if ((*itB)->getTop() == (*itN)->aBone->getTop() || (*itB)->getBottom() == (*itN)->aBone->getTop())
				{
					node*temp = new node;
					temp->aBone = new bone;
					temp->aBone = *itB;
					//aPlayer->getHand->erase(aPlayer->getBoneFirst() + itB);	//testing to see if this will work in place of (aPlayer->getBoneFirst() + itB)
					//delete aPlayer->getHand()[itB];
					aPlayer->deleteBone(itB);
					frees.push_back(temp);
					if (mapIndex < 30)
					{
						map[mapIndexCurr].push_back(*temp);
						map[mapIndex].push_back(*temp);
						mapIndex += 1;
					}

					FinishedFoot++;
				}
				else
				{
					cout << "haha you can't place a card (match card function)" << endl;
					return 0;
				}

			}
		}
		mapIndexCurr++;
		return 1;
	}
	//chicken mode
	else if (currChicFt!=NULL)
	{
		if (FinishedFoot==2)
		{ 
			currChicFt = NULL;
			FinishedFoot = 0;
			cout << "The Chicken Foot is complete" << endl;
			return 0;
		}
		

		cout << "A chickenfoot is already in progress before placing a bone anywhere else you must finish it" << endl;

		for (vector<bone*>::iterator itB = aPlayer->getBoneFirst(); itB != aPlayer->getBoneEnd(); itB++)	//Not sure why errors are showing up
		{
			for (vector<node*>::iterator itN = frees.begin(); itN != frees.end(); itN++)
			{
				//check if that is double
				if ((*itB)->getTop() == (*itB)->getBottom())
				{
					cout << "you can only place a single here you tried to place a double" << endl;
					break;
				}

				else if ((*itB)->getTop() == (*itN)->aBone->getTop() || (*itB)->getBottom() == (*itN)->aBone->getTop())
				{
					node*temp = new node;
					temp->aBone = new bone;
					temp->aBone = *itB;
					aPlayer->getHand().erase(itB);	//testing to see if this will work in place of (aPlayer->getBoneFirst() + itB)
					frees.push_back(temp);
					if (mapIndex < 30)
					{
						map[mapIndexCurr].push_back(*temp);
						map[mapIndex].push_back(*temp);
						mapIndex += 1;
					}

					FinishedFoot++;
				}
				else
				{
					cout << "haha you can't place a card " << endl;
					return 0;
				}

			}
		}
		mapIndexCurr++;
		return 1;
	}
	else
	{
		for (vector<bone*>::iterator itB = aPlayer->getBoneFirst(); itB != aPlayer->getBoneEnd(); itB++)	//Not sure why errors are showing up
		{
			for (vector<node*>::iterator itN = frees.begin(); itN != frees.end(); itN++)
			{
				if ((*itB)->getTop() == (*itN)->aBone->getTop() || (*itB)->getBottom() == (*itN)->aBone->getTop())
				{
					node*temp = new node;
					temp->aBone = new bone;
					temp->aBone = *itB;
					aPlayer->getHand().erase(itB);	//testing to see if this will work in place of (aPlayer->getBoneFirst() + itB)

					//check if that is double
					if (temp->aBone->getBottom() == temp->aBone->getTop())
					{
						temp->aBone->setYesDNo(temp->aBone->getBottom());
						for (int i = 0; i < 4; i++)
						{
							frees.push_back(temp);
							currChicFt = temp;
						}
					}
					else
					{
						frees.push_back(temp);
						node*temp = new node;
						temp->aBone = new bone;
						temp->aBone = *itB;
						aPlayer->getHand().erase(itB);	//testing to see if this will work in place of (aPlayer->getBoneFirst() + itB)
						frees.push_back(temp);
						if (mapIndex < 30)	//this is for non-double nodes to add to the map
						{
							map[mapIndex].push_back(*temp);
							map[mapIndex + 1].push_back(*temp);
						}

						return 1;
					}


				}
				else
				{
					cout << "haha you can't place a card " << endl;
					return 0;

				}

			}
		}
	}
	return 0;
}