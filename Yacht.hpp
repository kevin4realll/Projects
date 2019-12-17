/************************************************************************
***Program name: boardroom.hpp
Author: Kevin Spevacek
Date: 11/30/2019
Description: Definition file for Yacht Class in business game.
			Derived class from Space class. Final Space of game
			and requires salesLead item to advance/win
***********************************************************************/
#pragma once
#include <iostream>
#include "Space.hpp"

#ifndef YACHT_HPP
#define YACHT_HPP
class Player;
class Space;

class Yacht :
	public Space
{
public:
	Yacht();
	Yacht(Space* up, Space* down, Space* left, Space* right);
	virtual void spaceFunction(Player* player1);
	virtual string getSpaceType();
	~Yacht();
};

#endif // !BOARDROOM_HPP
