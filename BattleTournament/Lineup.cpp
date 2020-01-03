/*********************************************************************
** Program:Lineup.cpp
** Author:Kevin Spevacek
** Date:11/18/19
** Description:Implementation file for Lineup class of Characters in combat tournament simulation
*********************************************************************/
#include <iostream>
//#include "pch.h"
#include "ListNode.hpp"
#include "Lineup.hpp"
#include "Character.hpp"
using std::cout;
using std::endl;

/**************************************************************
Function:Lineup constructor

Description:
			-Arguments:
			-Returns:
****************************************************************/
Lineup::Lineup()
{
	lineupSize = 0;
	front = 0;
	back = 0;
}
/**************************************************************
Function:pushCharacter(Character*)

Description:adds new Character object to lineup stack.
			-Arguments:Character*
			-Returns:void
****************************************************************/
void Lineup::addCharacter(Character* addChar)
{
	ListNode* newNode = new ListNode(addChar);

	if (lineupSize == 0)
	{
		front = newNode;
		back = newNode;
		front->setNextNode(front);
		front->setPrevNode(front);
	}
	else
	{
		newNode->setPrevNode(back);
		newNode->setNextNode(front);
		back->setNextNode(newNode);
		front->setPrevNode(newNode);
		back = newNode;
	}
	lineupSize++;
}
/**************************************************************
Function:popCharacter()

Description:removes Character from top of lineup queue
			-Arguments:none
			-Returns:Character pointer to removed Character
****************************************************************/
Character* Lineup::removeCharacter()
{
	if (lineupSize == 0)
	{
		return 0;
	}
	else
	{
		ListNode* removedNode = front;
		Character* removedCharacter = front->getCharacter();

		front = front->getNextNode();
		back->setNextNode(front);
		front->setPrevNode(back);
		delete removedNode;

		lineupSize--;
		return removedCharacter;
	}
}
/**************************************************************
Function:advance

Description:Moves items in queue forward
			-Arguments:none
			-Returns:void
****************************************************************/
void Lineup::advance()
{
	if (lineupSize != 0)
	{
		back = front;
		front = front->getNextNode();
	}
	else
	{
		cout << "Empty lineup queue cannot advance positions." << endl;
	}
}
/**************************************************************
Function:getCharacter()

Description: returns pointer to Character at top of lineup queue
			-Arguments:none
			-Returns:Character*
****************************************************************/
Character* Lineup::getCharacter()
{
	if (lineupSize == 0)
	{
		return 0;
	}
	else
	{
		return front->getCharacter();
	}
}
/**************************************************************
Function:getLineupSize()

Description:returns the size (i.e. number of elements) in the lineup queue
			-Arguments:none
			-Returns:int
****************************************************************/
int Lineup::getLineupSize()
{
	return lineupSize;
}
/**************************************************************
Function:destructor

Description:deletes memory created in the lineup queue
			-Arguments:none
			-Returns:none
****************************************************************/
Lineup::~Lineup()
{
	if (lineupSize == 0)
	{
		return;
	}
	else
	{
		back = 0;
		ListNode* currentNode = front;

		while (currentNode->getNextNode() != 0)
		{
			currentNode = currentNode->getNextNode();
			delete currentNode->getPrevNode();

		}
		delete currentNode;
	}
}
