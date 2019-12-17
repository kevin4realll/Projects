/************************************************************************
***Program namee:Office.hpp
Author: Kevin Spevacek
Date: 11/30/2019
Description: Definition file for Office class in business game
***********************************************************************/
#pragma once
#include <iostream>
#include <set>
#include "Space.hpp"
using std::string;
using std::set;

#ifndef OFFICE_HPP
#define OFFICE_HPP

class Space;
class Player;

class Office :
	public Space
{
private:
	set<string> officeSupplies;
	void printMenu();
	void printSupplies();
	void getItem(string itemName, Player* player1);
	void leaveItem(string itemName, Player* player1);
public:
	Office(); 
	Office(Space* up, Space* down, Space* left, Space* right);
	Office(set<string>, Space* up, Space* down, Space* left, Space* right);
	Office(set<string>);
	virtual void spaceFunction(Player* player1);
	virtual string getSpaceType();
	~Office();
};

#endif // !OFFICE_HPP
