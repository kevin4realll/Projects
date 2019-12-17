/************************************************************************
***Program name: Game.hpp
Author: Kevin Spevacek
Date: 11/29/2019
Description: Header file for Game Class. 
***********************************************************************/
#include <iostream>
#include "Space.hpp"

#ifndef GAME_HPP
#define GAME_HPP
#pragma once
class Space;
class Hotel;
class Office;
class Player;

class Game
{
private:
	Space* localOffice;
	Space* spaceRow1;
	Space* spaceRow2;
	Space* spaceRow3;
	Space* spaceRow4;
	void printRow(Space* row);
	Player* player1;
	int pipeline;
	int days;
	int daysLimit;

public:
	Game();
	void printMap();
	void printMenu();
	void playGame();
	~Game();
};

#endif
