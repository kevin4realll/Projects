/************************************************************************
***Program namee:Hotel.hpp
Author: Kevin Spevacek
Date: 12/6/2019
Description: Definition file for Hotel class in business game
***********************************************************************/
#pragma once
#include <iostream>
#include "Space.hpp"

#ifndef HOTEL_HPP
#define HOTEL_HPP

class Space;
class Player;

class Hotel :
	public Space
{
private:
	void printMenu();
public:
	Hotel();
	Hotel(Space* up, Space* down, Space* left, Space* right);
	virtual void spaceFunction(Player* player1);
	virtual string getSpaceType();
	~Hotel();
};
#endif // !HOTEL_HPP
