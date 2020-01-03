/*********************************************************************
** Program: BlueMen.hpp
** Author:Kevin Spevacek
** Date:11/24/19
** Description:Header file for BlueMen Class in combat Game
*********************************************************************/
#include <iostream>
#pragma once
#include "Character.hpp"
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen :
	public Character
{
public:
	BlueMen();
	BlueMen(string pName);
	virtual int rollAttack();
	virtual int rollDefense();
	//void defend(int playerAttack, int defendNum) override;
};
#endif
