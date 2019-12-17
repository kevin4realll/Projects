/************************************************************************
***Program namee:Briefcase.cpp
Author: Kevin Spevacek
Date: 11/29/2019
Description: Definition file for Briefcase Class in Business Game.
			This is the item container for use with clients 
***********************************************************************/
//#include "pch.h"
#include <iostream>
#include <set> //items
#include "Briefcase.hpp"
using std::cout;
using std::endl;

/****************************************************************
Function:constructor
Description:creates briefcase object with capacity for 5 items
Arguments:none
Return type:Briefcase
**************************************************************************/
Briefcase::Briefcase()
{
	capacity = 4;
}
/****************************************************************
Function:hasItem
Description: returns true if defined item is present in Player briefcase
Arguments: string itemName
Return type: bool
**************************************************************************/
bool Briefcase::hasItem(string itemName)
{
	if (items.find(itemName) != items.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
/****************************************************************
Function: addItem
Description:adds item into Player briefcase for use in Business game
Arguments: string itemName
Return type: void
**************************************************************************/
void Briefcase::addItem(string itemName)
{
	if (items.size() >= capacity)
	{
		cout << "Briefcase is full." << endl;
		//cout <<"Would you like to discar an item? Press 1 for yes and 2 for no." << endl;
		//int choice = getInt(1, 2)
		//{
			//removeItem()
		//}
	}
	else
	{
		items.insert(itemName);
		cout << "Briefcase now has a " << itemName << endl;
	}
}
/****************************************************************
Function:removeItem
Description:removes item from Player briefcase
Arguments:string itemName
Return type:void
**************************************************************************/
void Briefcase::removeItem(string itemName)
{
	if (hasItem(itemName))
	{
		items.erase(itemName);
		cout << itemName << " is removed from the briefcase" << endl;
	}
	else
	{
		cout << "No " << itemName << " found in briefcase" << endl;
	}
}
/****************************************************************
Function:printItems
Description:displays which items Player has in his briefcase
Arguments:none
Return type:void
**************************************************************************/
void Briefcase::printItems()
{
	if (items.size() == 0)
	{
		cout << "Briefcase is empty" << endl;
	}
	else
	{
		cout << "Player briefcase shown below: " << endl;
		set<string>::iterator i;
		for (i = items.begin(); i != items.end(); i++)
		{
			cout << *i << endl;
		}
	}
}
/****************************************************************
Function:briefcaseFull
Description:returns true if Player briefcase is at capacity
Arguments: none
Return type:bool
**************************************************************************/
bool Briefcase::briefcaseFull()
{
	if (items.size() >= capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/****************************************************************
Function:destructor
Description: destructor for Briefcase object
Arguments: none
Return type: none
**************************************************************************/
Briefcase::~Briefcase()
{

}
