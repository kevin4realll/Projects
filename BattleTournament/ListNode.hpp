/*********************************************************************
** Program: HarryPotter.hpp
** Author:Kevin Spevacek
** Date:11/18/19
** Description:Header file for ListNode Class in combat tournament
*********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Character.hpp"

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

class ListNode
{
protected:
	Character* playerCharacter;
	ListNode* nextNode;
	ListNode* prevNode;
public:
	ListNode();
	ListNode(Character* playerCharacter);
	string getCharName();
	string getPlayerName();
	void setNextNode(ListNode* nextChar);
	void setPrevNode(ListNode* prevChar);
	ListNode* getPrevNode();
	ListNode* getNextNode();
	Character* getCharacter();
};

#endif // !LISTNODE_HPP