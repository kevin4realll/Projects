/*********************************************************************
** Program: BlueMen.cpp
** Author:Kevin Spevacek
** Date:11/23/19
** Description:Definition file for BlueMne  class in combat fighting game.
*********************************************************************/
#include <iostream>
#include "BlueMen.hpp"
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

/**************************************************************
Function: constructor

Description: constructor for BlueMen object. Derived class of Character class
			-Arguments: none
			-Returns: BlueMen object
****************************************************************/
BlueMen::BlueMen() : Character()
{
	armor = 3;//from game specs
	strength = 12; //from game specs
	charName = "BlueMen";
}

/**************************************************************
Function: constructor

Description: constructor for BlueMen object. Derived class of Character class
			-Arguments: none
			-Returns: BlueMen object
****************************************************************/
BlueMen::BlueMen(string pName) : Character(pName)
{
	armor = 3;//from game specs
	strength = 12; //from game specs
	charName = "BlueMen";
	playerName = pName;
}

/**************************************************************
Function:rollattack

Description: 2d10 attack for BlueMen. 
			Returns attack value for use in defend function
			-Arguments: None
			-Returns:int
****************************************************************/
int BlueMen::rollAttack()
{
	//2d10 attack
	int die1 = (rand() % 10 + 1);
	int die2 = (rand() % 10 + 1);
	cout << "BlueMen First Attack Dice roll is " << die1 << endl;
	cout << "BlueMen Second Attack Dice roll is " << die2 << endl;
	int totalAttack = die1 + die2;

	cout << "BlueMen attack = " << totalAttack << endl;

	return totalAttack;
}
/**************************************************************
Function:rollDefense

Description: 3d6 attack for BlueMen.
			Returns attack value for use in defend function
			-Arguments: None
			-Returns:int
****************************************************************/
int BlueMen::rollDefense()
{
	//3d6 for BlueMen defense
	int die1 = (rand() % 6 + 1);
	int die2 = (rand() % 6 + 1);
	int die3 = (rand() % 6 + 1);
	cout << "BlueMen Defense Dice roll 1 is " << die1 << endl;
	cout << "BlueMen Defense Dice roll 2 is " << die2 << endl;
	cout << "BlueMen Defense Dice roll 3 is " << die3 << endl;
	int totalDefense = die1 + die2 + die3;
	cout << "BlueMen Total Defense is: " << totalDefense << endl;


}
/**************************************************************
Function:defend

Description: 3d6 defend for Blue Men
			Damage is calculated from the attack int and the defend roll
			Damage is calculated against strength
			-Arguments: int playerAttack, bool isMedusa
			-Returns:void
****************************************************************
void BlueMen::defend(int playerAttack, int defenseNum)
{


		int attackDamage = playerAttack - (defenseNum)-armor;

		cout << "BlueMen armor is: " << armor << endl;
		cout << "Attack Damage to BlueMen is" << attackDamage << endl;
		strength -= attackDamage;
		cout << "BlueMen remaining strength is " << strength << endl << endl;
		
		if (strength <= 0)
			cout << "BlueMen are dead! Better luck next time." << endl;



}
**/


