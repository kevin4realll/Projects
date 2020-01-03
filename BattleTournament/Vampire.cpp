/*********************************************************************
** Program: Vampire.cpp
** Author:Kevin Spevacek
** Date:11/6/19
** Description:Definition file for Vampire  class.
*********************************************************************/
#include <iostream>
#include "Vampire.hpp"
#include <cstdlib> //for rand
#include <ctime>
using std::cout;
using std::endl;

/**************************************************************
Function: constructor

Description: constructor for Vampire object. Derived class of Character class
			-Arguments: none
			-Returns: Vampire object
****************************************************************/
Vampire::Vampire() : Character()
{
	this->armor = 1;
	this->strength = 18;
	this->charName = "Vampire";
}
/**************************************************************
Function: constructor

Description: constructor for Vampire object. Derived class of Character class
			-Arguments: none
			-Returns: Vampire object
****************************************************************/
Vampire::Vampire(string pName) : Character(pName)
{
	this->armor = 1;
	this->strength = 18;
	this->charName = "Vampire";
	this->playerName = pName;

}

/**************************************************************
Function:rollAttack

Description: 1d12 attack for Vampire
			-Arguments: None
			-Returns:int
****************************************************************/
int Vampire::rollAttack()
{
	//1d12 attack
	int die1 = (rand() % 12 + 1);

	cout << "Vampire Attack Dice Roll is " << die1 << endl;

	return die1;
}
/**************************************************************
Function:rollDefense

Description: 1d6 defense roll for Vampire.
			-Arguments: None
			-Returns:int
****************************************************************/
int Vampire::rollDefense()
{
	//1d6 defense 
	int die1 = (rand() % 6 + 1);
	cout << "Vampire's dice roll is " << die1 << endl;
	return die1;

}

/**************************************************************
Function:defend

Description: Runs "coin toss" for charm ability causing 0 damage if applied
			Otherwise damage is calculated from the attack int and the defend roll
			Damage is calculated against strength 
			-Arguments: int attackNum, int defenseNum
			-Returns:void
****************************************************************/
void Vampire::defend(int attackNum, int defenseNum)
{
		initialStrength = strength;
		//defend with charm 50% probability
		int charm = rand() % 2;
		if (charm == 0)
		{
			cout << "Vamprire's charm has his opponent unable to attack. " << endl;
		}
		else {
			int attackDamage = attackNum - (defenseNum)-armor;

			if (attackDamage <= 0)
				attackDamage = 0;

			cout << "Vampire takes " << attackDamage << " damage." << endl;
			strength -= attackDamage;
			if (strength <= 0)
			{
				strength = 0;
				lifeNum--;
			}
			cout << getCharName() << " pre-Attack strength was " << initialStrength << endl;
			cout << "Remaining strength level is now " << strength << endl << endl;
		
		} 
		if (strength <= 0)
			cout << "Vampire is dead! Better luck next time." << endl << endl;
	

}
