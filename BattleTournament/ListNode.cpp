/*********************************************************************
** Program:ListNode.cpp
** Author:Kevin Spevacek
** Date:11/18/19
** Description:Definition file for ListNode class. Doubly linked and used 
	for stack ADT in combat tournament
*********************************************************************/
#include <iostream>
#include <string>
#include "Character.hpp"
//#include "pch.h"
#include "ListNode.hpp"

/**************************************************************
Function: constructor

Description: constructor for ListNode object. 
			-Arguments: none
			-Returns: ListNode object
****************************************************************/
ListNode::ListNode()
{
	nextNode = 0;
	prevNode = 0;
	playerCharacter = 0;
}
/**************************************************************
Function: constructor

Description: constructor for ListNode object.
			-Arguments: none
			-Returns: ListNode object
****************************************************************/
ListNode::ListNode(Character* pCharacter)
{
	nextNode = 0;
	prevNode = 0;
	playerCharacter = pCharacter;
}
/**************************************************************
Function: getName()

Description: returns name of Character type
			-Arguments: none
			-Returns: string
****************************************************************/
string ListNode::getCharName()
{
	return playerCharacter->getCharName();

}
/**************************************************************
Function: getName()

Description: returns user defined name for the Character
			-Arguments: none
			-Returns: string
****************************************************************/
string ListNode::getPlayerName()
{
	return playerCharacter->getPlayerName();

}
/**************************************************************
Function: setNextNode

Description: sets the next pointer to the given ListNode pointer
			-Arguments: ListNode*
			-Returns:void
****************************************************************/
void ListNode::setNextNode(ListNode* nextChar)
{
	nextNode = nextChar;

}
/**************************************************************
Function:setPrevNode(ListNode*)

Description:sets the previous pointer to the given ListNode pointer
			-Arguments:ListNode*
			-Returns:void
****************************************************************/

void ListNode::setPrevNode(ListNode* prevChar)
{
	prevNode = prevChar;

}
/**************************************************************
Function:getPrevNode()

Description:returns the ListNode pointer in previous position
			-Arguments:none
			-Returns:ListNode*
****************************************************************/
ListNode* ListNode::getPrevNode()
{
	return prevNode;
}
/**************************************************************
Function:getNextNode()

Description: Returns the ListNode pointer in next position
			-Arguments:none
			-Returns:ListNode*
****************************************************************/
ListNode* ListNode::getNextNode()
{
	return nextNode;
}
/**************************************************************
Function:getCharacter()

Description:returns the pointer to the Character at the current ListNode
			-Arguments:none
			-Returns:Character*
****************************************************************/
Character* ListNode::getCharacter()
{
	return playerCharacter;
}
