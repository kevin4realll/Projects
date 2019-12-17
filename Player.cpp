/************************************************************************
***Program name: Player.cpp
Author: Kevin Spevacek
Date: 11/29/2019
Description: Definition file for Player Class in Business Game

***********************************************************************/
//#include "pch.h"
#include <iostream>
#include "Player.hpp"
#include "Space.hpp"
#include "Briefcase.hpp"
#include <string>
using std::cout;
using std::endl;
using std::string;

/****************************************************************
Function:constructor
Description: Creates player object with initial attributes for business game 
Arguments: Space* startingSpace
Return Player
**************************************************************************/
Player::Player(Space* startingSpace)
{
	pipeline = 1300000; //start w/ 1.3M
	closedDeal = false;
	curPosition = startingSpace;
}

/****************************************************************
Function: getCurSpace
Description: Gets a pointer to the current space on the map
			where the Player is located
Arguments:none
Return type: Space*
**************************************************************************/
Space* Player::getCurSpace()
{
	return curPosition;
}
/****************************************************************
Function: movePlayer
Description: moves the Player to the Space passed in as function argument
Arguments: Space*
Return type: void
**************************************************************************/
void Player::movePlayer(Space* spacePosition)
{
	if (spacePosition != NULL)
	{
		curPosition = spacePosition;
	}
	else
	{
		cout << "No business on this space. Please select another." << endl;
	}
}
/****************************************************************
Function: getPipeline
Description: returns sales pipeline (i.e. Player health) meter
Arguments: none
Return type: int
**************************************************************************/
int Player::getPipeline()
{
	return pipeline;
}
/****************************************************************
Function: increasePipeline
Description: adds to Player sales piepline by specified amount
Arguments: int
Return type: void
**************************************************************************/
void Player::increasePipeline(int amount)
{
	pipeline = pipeline + amount;
}
/****************************************************************
Function: decreasePipeline
Description: decreaseses Player sales piepline by specified amount
Arguments: int 
Return type: void
**************************************************************************/
void Player::decreasePipeline(int reduction)
{
	pipeline = pipeline - reduction;
}
/****************************************************************
Function:
Description:
Arguments:
Return type:
**************************************************************************/
bool Player::hasItem(string item)
{
	return myBriefcase.hasItem(item);
}
/****************************************************************
Function:addItem
Description: adds item to Player briefcase
Arguments:string
Return type:void
**************************************************************************/
void Player::addItem(string item)
{
	myBriefcase.addItem(item);
}
/****************************************************************
Function: removeItem
Description: removes item from player briefcase
Arguments: string itemName
Return type: void
**************************************************************************/
void Player::removeItem(string item)
{
	myBriefcase.removeItem(item);
}
/****************************************************************
Function:printItems
Description: Shows items currently in player briefcase
Arguments: none
Return type: void
**************************************************************************/
void Player::printItems()
{
	myBriefcase.printItems();
}
/****************************************************************
Function:briefcaseFull
Description: returns true if player briefcase capacity is reached
Arguments: none
Return type: bool
**************************************************************************/
bool Player::briefcaseFull()
{
	return myBriefcase.briefcaseFull();
}
/****************************************************************
Function: isBankrupt
Description: Returns true if Player sales pipeline is below $250k. 
			Player cannot continue if true
Arguments: none
Return type: bool
**************************************************************************/
bool Player::isBankrupt()
{
	if (pipeline <= 500000)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/****************************************************************
Function:setClosedDeal
Description: sets the closedDeal member 
Arguments: bool
Return type: void
**************************************************************************/
void Player::setClosedDeal(bool dealStatus)
{
	this->closedDeal = dealStatus;
}
/****************************************************************
Function: getClosedDeal
Description: returns true if player has closed the Big Dog deal
Arguments: none
Return type: bool
**************************************************************************/
bool Player::getClosedDeal()
{
	return closedDeal;
}
/****************************************************************
Function:destructor
Description:destructor 
Arguments:none
Return type:
**************************************************************************/
Player::~Player()
{
}
