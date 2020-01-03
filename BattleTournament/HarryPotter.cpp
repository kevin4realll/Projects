/*********************************************************************
** Program: HarryPOtter.cpp
** Author:Kevin Spevacek
** Date:11/6/19
** Description:Definition file for BlueMne  class in combat fighting game.
*********************************************************************/
#include "HarryPotter.hpp"
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;

/**************************************************************
Function: constructor

Description: constructor for HarryPotter object. Derived class of Character class
			-Arguments: none
			-Returns: HarryPotter object
****************************************************************/
HarryPotter::HarryPotter()
{
	armor = 0;
	strength = 10; //(20 on second life "Hogwarts revive")
	charName = "Harry Potter";
}

/**************************************************************
Function: constructor

Description: constructor for HarryPotter object. Derived class of Character class
			-Arguments: none
			-Returns: HarryPotter object
****************************************************************/
HarryPotter::HarryPotter(string pName) : Character(pName)
{
	armor = 0;
	strength = 10; //(20 on second life "Hogwarts revive")
	charName = "Harry Potter";
	playerName = pName;
}


/**************************************************************
Function:rollAttack

Description: 2d6 attack for Harry Potter. 
			Returns attack value for use in defender's takeDamage function
			-Arguments: None
			-Returns:int
****************************************************************/
int HarryPotter::rollAttack()
{	
	//(2d6) for attack
	int die1 = (rand() % 6 + 1);
	int die2 = (rand() % 6 + 1);
	int totalAttack = die1 + die2;

		cout << "Harry's Attack Dice roll 1 is: " << die1 << endl;
		cout << "Harry's Attack Dice roll 2 is: " << die2 << endl;
		cout << "Harry Potter attack = " << totalAttack << endl;

	return totalAttack;
}
/**************************************************************
Function:rollDefense

Description: 2d6 defend for Harry Potter.
			Returns defend value for use in defend function
			-Arguments: None
			-Returns:int
****************************************************************/
int HarryPotter::rollDefense()
{
	//(2d6) for defend
	int die1 = (rand() % 6 + 1);
	int die2 = (rand() % 6 + 1);

	cout << "Harry's Defense Dice roll 1 is: " << die1 << endl;
	cout << "Harry's Defense Dice roll 2 is: " << die2 << endl;
	int totalDefend = die1 + die2;

return totalDefend;
}
/**************************************************************
Function:defend

Description: 
			Damage is calculated from the attack int and the defend roll arguments
			Damage is calculated against strength
			Harry Potter also revives after 1st and only 1st death
			-Arguments: int attackRoll, int defendseRoll
			-Returns:void
****************************************************************/
void HarryPotter::defend(int playerAttack, int defendNum)
{
	int initialStrength = strength;

	int attackDamage = playerAttack - (defendNum)-armor;
	if (attackDamage <= 0)
	{
		attackDamage = 0;
	}
	strength -= attackDamage;
	if (strength <= 0)
	{
		strength = 0;
		lifeNum--;
	}
	cout << getCharName() << " pre-Attack strength was " << initialStrength << endl;
	cout << "Remaining strength level is now " << strength << endl << endl;

	//Hogwarts revive ability
	if (strength <= 0 && secondLife == 0)
	{
		cout << "Harry P. is dead! Better luck next time" << endl;
		cout << "..... " << endl;
		cout << "RENNERVATE! Harry Potter is revived for a second life." << endl;
		strength = 20;
		secondLife = 1;
	}
	else if (strength <= 0 && secondLife == 1)
	{
		cout << "AVADA KEDAVRA!!! " << endl << "Harry Potter is dead and cannot revive" << endl;
	}
		
	
}


