/*********************************************************************
** Program: Medusa.hpp
** Author:Kevin Spevacek
** Date:11/6/19
** Description:Header file for Medusa Class in combat Game
*********************************************************************/
#pragma once
#include "Character.hpp"
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa :
	public Character
{
public:
	Medusa();
	Medusa(string pName);
	virtual int rollAttack();
	virtual int rollDefense();
	//void defend(int attackRoll, int defenseRoll) override;
};
#endif
