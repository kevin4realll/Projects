/*********************************************************************
** Program: HarryPotter.hpp
** Author:Kevin Spevacek
** Date:11/24/19
** Description:Header file for HarryPotter Class in combat Game
*********************************************************************/
#pragma once
#include "Character.hpp"
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter :
	public Character
{
private:
	bool secondLife = 0;
public:
	HarryPotter();
	HarryPotter(string pName);
	virtual int rollAttack();
	virtual int rollDefense();
	void defend(int playerAttack, int defenseNum) override;

};
#endif
