/************************************************************************
***Program name: Market.hpp
Author: Kevin Spevacek
Date: 11/30/2019
Description: Definition file for Market Class in business game.
			Derived class from Space class. Client interactions that 
			increase/decrease sales pipeline (i.e. player health meter)
***********************************************************************/
#pragma once
#include <iostream>
#include "Space.hpp"

#ifndef MARKET_HPP
#define MARKET_HPP
class Space;
class Player;

class Market :
	public Space
{
public:
	Market();
	Market(Space* up, Space* down, Space* left, Space* right);
	virtual void spaceFunction(Player* player1);
	virtual string getSpaceType();
	~Market();
};

#endif // !MARKET_HPPs