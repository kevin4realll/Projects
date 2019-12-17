/************************************************************************
***Program name:Player.hpp
Author: Kevin Spevacek
Date: 11/29/2019
Description: Header file for Player Class in Business Game.
***********************************************************************/
#include <iostream>
#include <string>
#include "Briefcase.hpp"
#pragma once

#ifndef PLAYER_HPP
#define PLAYER_HPP
using std::string;

class Space;
class Briefcase;

class Player
{
private:
	Space* curPosition;
	int pipeline;
	Briefcase myBriefcase;
	bool closedDeal;

public:
	Player(Space* startingSpace);
	Space* getCurSpace();
	void movePlayer(Space* curSpace);
	int getPipeline();
	void decreasePipeline(int reduction);
	void increasePipeline(int amount);
	bool hasItem(string item);
	void addItem(string item);
	void removeItem(string item);
	void printItems();
	bool briefcaseFull();
	bool isBankrupt();
	void setClosedDeal(bool dealStatus);
	bool getClosedDeal();
	~Player();
};

#endif
