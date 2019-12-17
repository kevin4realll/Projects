/************************************************************************
***Program name: Space.hpp
Author: Kevin Spevacek
Date: 11/29/2019
Description: Definition file for Space Class in Business Game
			Class is abstract base class with derived spaces including
			office, marketplace, and boardroom
***********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Player.hpp"
#include "inputVal.hpp"
#pragma once
using std::string;

#ifndef SPACE_HPP
#define SPACE_HPP
class Player;

class Space
{
protected:
	Space* up;
	Space* down;
	Space* left;
	Space* right;

public:
	Space();
	Space(Space* up, Space* down, Space* left, Space* right);
	virtual void spaceFunction(Player* player1) = 0;
	void setUp(Space* up);
	void setDown(Space* down);
	void setLeft(Space* left);
	void setRight(Space* right);
	Space* getRight();
	Space* getLeft();
	Space* getUp();
	Space* getDown();
	virtual string getSpaceType() = 0;
	virtual ~Space();
};




#endif
