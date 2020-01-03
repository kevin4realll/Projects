/*********************************************************************
** Program:Lineup.hpp
** Author:Kevin Spevacek
** Date:11/18/19
** Description:Lineup class definition file. Queue like ADT (FIFO style) for combat game
				Characters. Is also doubly linked in order to run until one linup is empty.
*********************************************************************/
#include "ListNode.hpp"
#include "Character.hpp"
#pragma once
#ifndef LINEUP_HPP
#define LINEUP_HPP

class Lineup
{
protected:
	int lineupSize;
	ListNode* front;
	ListNode* back;
public:
	Lineup();
	int getLineupSize();
	void addCharacter(Character* addChar);
	Character* removeCharacter();
	Character* getCharacter();
	void advance();
	~Lineup();
};

#endif // !LINEUP_HPP