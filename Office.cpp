/************************************************************************
***Program namee:Office.cpp
Author: Kevin Spevacek
Date: 11/30/2019
Description: Implementation file for Office class in business game
			Space allows player to work on increasing pipeline
			as well as pickup supplies (itmes) for clients/selling in the field
***********************************************************************/
//#include "pch.h"
#include "Office.hpp"
#include <cstdlib>
using std::string;
using std::set;
using std::cout;
using std::cin;
using std::endl;

/****************************************************************
Function: constructor
Description: empty constructor
Arguments: none
Return type :Market
**************************************************************************/
Office::Office() : Space()
{

}
/****************************************************************
Function: constructor
Description: constructor 
Arguments: none
Return type :Market
**************************************************************************/
Office::Office(Space* up, Space* down, Space* left, Space* right) : Space(up, down, left, right)
{

}
/****************************************************************
Function: constructor
Description: constructor
Arguments: none
Return type :Market
**************************************************************************/
Office::Office(set<string> supplies, Space* up, Space* down, Space* left, Space* right)
{
	this->officeSupplies = supplies;
}
/****************************************************************
Function: constructor
Description: constructor 
Arguments: none
Return type :Market
**************************************************************************/
Office::Office(set<string> supplies)
{
	this->officeSupplies = supplies;
}
/****************************************************************
Function:printMenu
Description:prints menu for Office space

Arguments:none
Return type: void
**************************************************************************/
void Office::printMenu()
{
	cout << "****************************" << endl;
	cout << "Welcome to the Office Suite" << endl;
	cout << "*****************************" << endl << endl;
	cout << "Time to get working" << endl;
	cout << "What is today's task?" << endl;
	cout << "    1.Prospect for Sales!!" << endl;
	cout << "    2. Pickup Supplies" << endl;
	cout << "    3. Leave Supplies" << endl;
	cout << "    4. Leave the office" << endl;
}
/****************************************************************
Function:printSupplies
Description: shows items for player in office 
Arguments:none
Return type: void
**************************************************************************/
void Office::printSupplies()
{
	set<string>::iterator i;
	for (i = officeSupplies.begin(); i != officeSupplies.end(); i++)
	{
		cout << *i << endl;
	}
}
/****************************************************************
Function:getItem
Description:Player object picks up item specified by its name
			Item is removed from office supplies set
Arguments: string, Player*
Return type: void
**************************************************************************/
void Office::getItem(string itemName, Player* player1)
{
	cout << "You got the " << itemName << "!" << endl;
	player1->addItem(itemName);
	officeSupplies.erase(itemName);
}
/****************************************************************
Function:leaveItem
Description:Player object  removes item specified by its name
			item is added to the officeSupplies set

Arguments: string, Player*
Return type: void
**************************************************************************/
void Office::leaveItem(string itemName, Player* player1)
{
	cout << "You left the " << itemName << " at the office" << endl;
	player1->removeItem(itemName);
	officeSupplies.insert(itemName);
}
/****************************************************************
Function: spaceFunction
Description:

Arguments: Player*
Return type: void
**************************************************************************/
void Office::spaceFunction(Player* player1)
{

	printMenu();
	int workChoice = getInt(1, 4);

	if (workChoice == 1)//Prospect
	{
		cout << "..... Making Calls......" << endl;
		int prospect = (rand() % 3 + 1);
		if (prospect == 1)
		{
			cout << "No Luck Today" << endl;
		}
		else if (prospect == 2)
		{
			cout << "Average day of calls. Pipeline is up $100k" << endl;
			player1->increasePipeline(100000);
		}
		else if (prospect == 3)
		{
			cout << "Great day of calls! Pipeline is up $300k" << endl;
			player1->increasePipeline(300000);
		}

		cout << endl;
		cout << "END OF DAY: Do you want to make one more call?" << endl;
		cout << "1.Yes" << endl;
		cout << "2. No" << endl;
		int choice = getInt(1,2);
	
		if (choice == 1)
		{
			if (player1->hasItem("Sales Lead"))
			{
				cout << "....." << endl;
				cout << "All clients are offline" << endl;
				cout << "Better focus on Big Dog!" << endl;
			}
			else
			{
				cout << "...." << endl;
				cout << "YOU GOT THE  BIG DOG SALES LEAD!" << endl;
				cout << "Now you can negotiate with the Big Dog!" << endl;
				player1->addItem("salesLead");
				cout << "Good luck" << endl << endl;
			}
		}
		else if (choice ==2) 
		{	
		cout << ":) Outa the office!!" << endl;
		} 
	
	}
	else if (workChoice == 2)
	{
		cout << "OFFICE SUPPLIES ARE:" << endl;
		cout << "1. New Suit" << endl;
		cout << "2. New Product" << endl;
		cout << "3. New Ad" << endl;
		
		int supplyChoice = getInt(1,3);
		if (supplyChoice == 1)
		{
		cout << endl << "You got the  new suit!! Clients Beware!" << endl;
		player1->addItem("newSuit");
		player1->printItems();
		cout << "Good luck!" << endl << endl;
		}
		else if (supplyChoice == 2)
		{
		cout << endl << "You got the New Product! This will excel in the Market" << endl;
		player1->addItem("newProduct");
		player1->printItems();

		cout << "Good luck!" << endl << endl;
		}			
		else if (supplyChoice == 3)
		{
		cout << "You got the New Ad. Niiiiice!" << endl;
		player1->addItem("newAd");
		player1->printItems();
	
		cout << "Good luck!" << endl << endl;
		}

	}
	else if (workChoice == 3)
	{
		cout << "Please enter the name of the item you want to  leave behind" << endl;
		cout << "(newSuit, newProduct, newAd, salesLead)" << endl;
		string item;
		cin >> item;
		if (player1->hasItem(item))
		{
			player1->removeItem(item);
			cout << "Ok, you let behind the " << item << endl;
		} 
		else
		{
			cout << item << " is not in your Briefcase" << endl;
		}	
	}
	else if (workChoice ==4)
	{
		cout << "Outa the office!!" << endl;
	}

}
/****************************************************************
Function: getSpaceType
Description: returns the child Class name (i.e. "Office") for this Space.
Arguments: none
Return type: string
**************************************************************************/
string Office::getSpaceType()
{
	return "Office";
}
/****************************************************************
Function:destructor
Description: empty destructor
Arguments: none
Return type: none
**************************************************************************/
Office::~Office()
{
}
