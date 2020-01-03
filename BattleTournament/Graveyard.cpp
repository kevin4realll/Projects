/*********************************************************************
** Program:Graveyard.cpp
** Author:Kevin Spevacek
** Date:11/23/19
** Description:Definition file for Graveyard. Stack for losing Characters in tournament
*********************************************************************/
#include <iostream>
//#include "pch.h"
#include "Graveyard.hpp"
using std::cout;
using std::endl;

/**************************************************************
Function:Graveyard constructor

Description:Create new stack for losing Characters. 
			-Arguments:none
			-Returns:Graveyard
****************************************************************/
Graveyard::Graveyard()
{
	stackSize = 0;
	stackBottom = 0;
	stackTop = 0;

}
/**************************************************************
Function:popCharacter()

Description:removes Character from top of stack
			-Arguments:none
			-Returns:Character*
****************************************************************/
Character* Graveyard::popCharacter()
{
	if (stackSize == 0)
	{
		return 0;
	}
	else
	{
		ListNode* removedNode = stackTop;
		Character* removedChar = stackTop->getCharacter();

		if (stackTop->getPrevNode() != 0)
		{
			stackTop = stackTop->getPrevNode();
			stackTop = 0;
		}
		delete removedNode;
		stackSize--;
		return removedChar;
	}
}
/**************************************************************
Function:addCharacter(Character*)

Description:Adds new Character to the stack (FILO data type)
			-Arguments:Character*
			-Returns:void
****************************************************************/
void Graveyard::pushCharacter(Character* newDeadCharacter)
{
	ListNode* newNode = new ListNode(newDeadCharacter);
	if (stackSize == 0)
	{
		stackBottom = newNode;
		stackTop = newNode;
	}
	else
	{
		stackTop->setNextNode(newNode);
		newNode->setPrevNode(stackTop);
		stackTop = newNode;
	}
	stackSize++;
}
/**************************************************************
Function: showGraveyard()

Description: displays stack of Characters from top to bottom
			-Arguments: 
			-Returns: 
****************************************************************/
void Graveyard::showGraveyard()
{
	if (stackSize == 0)
	{
		cout << "No Soulss are in the Graveyard" << endl;
	}
	else
	{
		ListNode* currentNode = stackTop;
		for (int i = 0; i < stackSize; i++)
		{
			cout << currentNode->getCharName() << " aka " << currentNode->getPlayerName() << endl;
			currentNode = currentNode->getPrevNode();
		}

	}
	//cout << endl;
}
/**************************************************************
Function:getSize()

Description:returns size of stack (i.e. number of defeated Characters)
			-Arguments:none
			-Returns:int
****************************************************************/
int Graveyard::getSize()
{
	return stackSize;

}
/**************************************************************
Function:Graveyard destructor

Description:removes memory for each Node on the stack of losing Characters
			-Arguments:none
			-Returns:
****************************************************************/
Graveyard::~Graveyard()
{
	if (stackSize == 0)
	{
		return;
	}

	else
	{
		ListNode* currentNode = stackTop;

		while (currentNode->getPrevNode() != 0)
		{
			currentNode = currentNode->getPrevNode();
			delete currentNode->getNextNode();
		}
		delete currentNode;

	}
}
