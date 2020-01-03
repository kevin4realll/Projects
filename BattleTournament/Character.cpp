/*********************************************************************
** Program: Character.cpp
** Author:Kevin Spevacek
** Date:11/23/19
** Description:Definition file for Character base class.
				-Class is abstract class
*********************************************************************/
#include <iostream>
#include "Character.hpp"
#include <string>
using std::cout;
using std::endl;
using std::string;

/**************************************************************
Function: constructor

Description: constructor for Character object.
			-Arguments: none
			-Returns: Character object
****************************************************************/
Character::Character()
{
	lifeNum = 1;
	charName = "Character";
}

/**************************************************************
Function: constructor

Description: constructor for Character object.
			-Arguments: none
			-Returns: Character object
****************************************************************/
Character::Character(string pName)
{
	lifeNum = 1;
	playerName = pName;
	charName = "Character";
}
/**************************************************************
Function: defend

Description: Defend function for Characer battle
			-Arguments: ints for both total attack and total defense dice rolls
			Calculates attack damage and subtracts this from strength meter value.
			-Returns: void 
****************************************************************/
void Character::defend(int attackNum, int defenseNum)
{
	int initialStrength = strength;
	int attackDamage = attackNum - (defenseNum)-armor;
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
}
/**************************************************************
Function: getArmor

Description: get function for armor member variable of Character base class
			-Arguments: none
			-Returns: int armor
****************************************************************/
int Character::getArmor()
{
	return armor;
}
/**************************************************************
Function: getStrenght

Description: get function for strength member variable of Character base class
			-Arguments: none
			-Returns: int strength
****************************************************************/
int Character::getStrength()
{
	return strength;
}

/**************************************************************
Function: getCharName

Description: get function for Character type in combat
			-Arguments: none
			-Returns:string
****************************************************************/
string Character::getCharName()
{
	return charName;
}
/**************************************************************
Function: getPlayerName

Description: get function for user defined Player name for each Character
			in the cobat game
			-Arguments: none
			-Returns:string
****************************************************************/
string Character::getPlayerName()
{
	return playerName;
}
/**************************************************************
Function: setPlayerName

Description: sets the user defined name for Character objects
			-Arguments:string
			-Returns:void
****************************************************************/
void Character::setPlayerName(string userName)
{
	playerName = userName;
}
/**************************************************************
Function: recover()

Description: Character strength is increased by half of the strength lost
			in that combat round
			-Arguments:none
			-Returns:void
****************************************************************/
void Character::recover()
{
	cout << getCharName() << " recovers half of the strength lost in battle" << endl;
	int newStrength = strength;
	int oldStrength = (newStrength + ((initialStrength - strength) / 2));
	cout << "Strength is restored from " << oldStrength << " to " << newStrength << endl;
	strength = newStrength;
}
