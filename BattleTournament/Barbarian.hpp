/*********************************************************************
** Program: Barbarian.hpp
** Author:Kevin Spevacek
** Date:11/24/19
** Description:Header file for Barbarian Class in combat Game
*********************************************************************/
#include <iostream>
#include "Character.hpp"
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#pragma once

class Barbarian : public Character
{
public:
	Barbarian();
	Barbarian(string pName);
	virtual int rollAttack();
	virtual int rollDefense();
};

#endif // !BARBARIAN_HPP
