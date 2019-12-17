/************************************************************************
***Program name: Game.hpp
Author: Kevin Spevacek
Date: 11/29/2019
Description: Header file for Briefcase Class (item container)
			in Business game.
***********************************************************************/
#include <iostream>
#include <set>
#include <string>
#pragma once
using std::string;
using std::set;

#ifndef BRIEFCASE_HPP
#define BRIEFCASE_HPP

class Briefcase
{
protected:
	int capacity;
	set<string> items;
public:
	Briefcase();
	bool hasItem(string itemName);
	void addItem(string itemName);
	void removeItem(string itemName);
	void printItems();
	bool briefcaseFull();
	~Briefcase();
};

#endif // !BRIEFCASE_HPP