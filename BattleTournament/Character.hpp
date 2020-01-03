/*********************************************************************
** Program: Character.hpp
** Author:Kevin Spevacek
** Date:11/24/19
** Description:Implementation file for Character base class.
				-Class is abstract class (i.e. all virtual members/functions)
*********************************************************************/
#pragma once
#include <cstdlib> //for rand
#include <iostream>
#include <string>


#ifndef CHARACTER_HPP
#define CHARACTER_HPP
using std::string;

class Character //abstract base class for all game characers 
				//which inherit attributes/members as defined here
{
protected:
	int armor;
	int lifeNum;
	int strength;
	int initialStrength;
	string charName;
	string playerName;

public:
	Character();
	Character(string pName);
	virtual int rollAttack() = 0;
	virtual int rollDefense() = 0;
	virtual void defend(int attackNum, int defenseNum);
	virtual int getArmor();
	virtual int getStrength();
	string getCharName();
	string getPlayerName();
	void setPlayerName(string userName);
	void recover();
};

#endif // !CHARACTER_HPP
