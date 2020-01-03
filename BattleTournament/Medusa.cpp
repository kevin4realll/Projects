/*********************************************************************
** Program: Vampire.cpp
** Author:Kevin Spevacek
** Date:11/6/19
** Description:Definition file for Medusa  class.
*********************************************************************/
#include "Medusa.hpp"
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

/**************************************************************
Function: constructor

Description: constructor for Medusa object. Derived class of Character class
			-Arguments: none
			-Returns: Medusa object
****************************************************************/
Medusa::Medusa() : Character()
{
	armor = 3;
	strength = 8;

}

/**************************************************************
Function: constructor

Description: constructor for Medusa object. Derived class of Character class
			-Arguments: none
			-Returns: Medusa object
****************************************************************/
Medusa::Medusa(string pName) : Character(pName)
{
	armor = 3;
	strength = 8;
	charName = "Medusa";
	playerName = pName;

}

/**************************************************************
Function:rollAttack

Description: 2d6 attack for Medusa attack. 
			Returns attack value for use in defender's takeDamage function
			-Arguments: None
			-Returns:int
****************************************************************/
int Medusa::rollAttack()
{
	//(2d6) for attack
	int die1 = (rand() % 6 + 1);
	int die2 = (rand() % 6 + 1);
	int totalAttack = die1 + die2;

	cout << "Medusa Attack Dice roll 1 is " << die1 << endl;
	cout << "Medusa Attack Dice roll 2 is " << die2 <<endl;
	//Glare check
	if (totalAttack == 12)
	{
		cout << "Medusa uses the fatal glare attack and!!!" << endl;
		totalAttack = 1000;
	}
	else
	{
		cout << "Medusa's attack = " << totalAttack << endl;
	}
	return totalAttack;

}
/**************************************************************
Function:rollDefense

Description: 1d6 defense for Medusa attack.
			Returns defense value for use in defend function
			-Arguments: None
			-Returns:int
****************************************************************/
int Medusa::rollDefense()
{
	//1d6 for defend
	int die1 = (rand() % 6 + 1);
	cout << "Medusa defense dice roll is " << die1 << endl;
	return die1;
}

/**************************************************************
Function:defend

Description: 1d6 defend for Medusa 
			Damage is calculated from the attack int and the defend roll
			Damage is calculated against strength
			-Arguments: int playerAttack, bool isMedusa
			-Returns:void
****************************************************************
void Medusa::defend(int attackNum, int defenseNum)
{
		//Calculate damage against strength points
		//1d6 for defend
		int attackDamage = attackNum - (defenseNum) - armor;
		if (attackDamage <= 0)
		{
			attackDamage = 0;
		}

		cout << "Damage to Medusa is " << attackDamage << endl;
		strength -= attackDamage;
		if (strength <= 0)
		{
			strength = 0;
			lifeNum--;
		}
		cout << getCharName() << " pre-Attack strength was " << initialStrength << endl;
		cout << "Remaining strength level is now " << strength << endl << endl;

		if (strength <= 0)
		{
			cout << "Medusa is dead! Better luck next time" << endl;
		}

	}
}
***/
