/*********************************************************************
** Program: Vampire.hpp
** Author:Kevin Spevacek
** Date:11/23/19
** Description:Implementation file for Vampire class
				-Class derived from Character base class
*********************************************************************/
#pragma once
#include <iostream>
#include "Character.hpp"
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire :
	public Character
{	
public:
	Vampire();
	Vampire(string pName);
	virtual int rollAttack();
	virtual int rollDefense();
	virtual void defend(int attackNum, int defenseNum) override;
};
#endif
