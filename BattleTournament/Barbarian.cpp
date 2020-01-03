/*********************************************************************
** Program: Barbarian.cpp
** Author:Kevin Spevacek
** Date:11/23/19
** Description:Definition file for Barbarian  class.
*********************************************************************/
#include <iostream>
#include "Barbarian.hpp"
#include <string>
#include <cstdlib> //for rand
#include <ctime> //for seeding srand
using std::cout;
using std::endl;


/**************************************************************
Function: constructor

Description: constructor for Barbarian object. Derived class of Character class
			-Arguments: none
			-Returns: Barbarian object
****************************************************************/
Barbarian::Barbarian() : Character()
{
	this->armor = 0; //from game specs
	this->strength = 12;//from game specs
	this->charName = "Barbarian";
}

/**************************************************************
Function: constructor

Description: constructor for Barbarian object. Derived class of Character class
			-Arguments: none
			-Returns: Barbarian object
****************************************************************/
Barbarian::Barbarian(string pName) : Character(pName)
{
	this->armor = 0; //from game specs
	this->strength = 12;//from game specs
	this->charName = "Barbarian";
	this->playerName = pName;

}

/**************************************************************
Function:rollAttack

Description: 2d6 attack for Barbarian 
			Returns attack value for use in defender's takeDamage function
			-Arguments: None
			-Returns:int
****************************************************************/
int Barbarian::rollAttack()
{
	//2d6 attack
	int die1 = (rand() % 6 + 1);
	int die2 = (rand() % 6 + 1);
	cout << "Barbarian Attack Dice roll 1 is " << die1 << endl;
	cout << "Barbarian Attack Dice roll 2 is " << die2 << endl;
	int totalAttack = die1 + die2;

	cout << "Barbarian Total Attack = " << totalAttack << endl;
return totalAttack;

}
/**************************************************************
Function:rollDefense

Description: 2d6 defense for Barbarian
			Returns defense value for use in defender's defend function
			-Arguments: None
			-Returns:int
****************************************************************/
int Barbarian::rollDefense()
{
	//2d6 defense
	int die1 = (rand() % 6 + 1);
	int die2 = (rand() % 6 + 1);
	cout << "Barbarian Defense Dice roll is " << die1 << endl;
	cout << "Barbarian Defense Dice roll  is " << die2 << endl;
	int totalDefense = die1 + die2;

	return totalDefense;
}
/***************************************************************
Function:defend

Description:Damage is calculated from the attack, defend, and armore numbers
			Damage is calculated against strength
			-Arguments: int playerAttack, int defendNum
			-Returns:void
****************************************************************
void Barbarian::defend(int playerAttack, int defendNum) 
{

		int attackDamage = playerAttack - (defendNum) - armor;
		if (attackDamage <= 0)
		{
			attackDamage = 0;
		}

		cout << "Attack Damage to Barbarian is " << attackDamage << endl;
		strength -= attackDamage;
		cout << "Barbarian remaining strength level is " << strength << endl << endl;
		if (strength <= 0)
		{
			cout << "Barbarian is dead! Better luck next time" << endl << endl;
		}

}
**/



