/*********************************************************************
** Program: Graveyard.hpp
** Author:Kevin Spevacek
** Date:11/18/19
** Description:Header file for Graveyard stack in combat Tournament
*********************************************************************/
#pragma once
#include "ListNode.hpp"
#ifndef GRAVEYARD_HPP
#define GRAVEYARD_HPP

class Graveyard
{
protected:
	int stackSize;
	ListNode* stackBottom;
	ListNode* stackTop;
public:
	Graveyard();
	~Graveyard();
	Character* popCharacter();
	void pushCharacter(Character* newCharacter);
	void showGraveyard();
	int getSize();
};

#endif //GRAVEYARD_HPP
