/************************************************************************
***Program name: Market.cpp
Author: Kevin Spevacek
Date: 11/30/2019
Description: Definition file for Market Class in business game.
			Derived class from Space class. Client interactions that
			increase/decrease sales pipeline (i.e. player health meter)
***********************************************************************/
//#include "pch.h"
#include "Market.hpp"
#include <cstdlib>
using std::string;
using std::cout;
using std::endl;

/****************************************************************
Function: constructor
Description: empty constructor 
Arguments: none
Return type :Market
**************************************************************************/
Market::Market() : Space()
{
}
/****************************************************************
Function:constructor
Description:copy constructor inherits 4 Space pointers
Arguments: 4 Space pointers
Return type: Market
**************************************************************************/
Market::Market(Space* up, Space* down, Space* left, Space* right) : Space(up, down, left, right)
{

}
/****************************************************************
Function: spaceFunction
Description: Market space simulates potential client interaction. 
			 Player can choose to avoid or engage the client
			with different effets on sales pipeline health meter
Arguments: Player*
Return type: void
**************************************************************************/
void Market::spaceFunction(Player* player1)
{
	cout << "****************************" << endl;
	cout << "        Market" << endl;
	cout << "*****************************" << endl << endl;
	cout << "There is a small dog client in the market!" << endl;
	cout << "1. Avoid/Ignore the client - 50% chance of hurting of your Sales Meter." << endl;
	cout << "2. Engage the client - You may win/lose Sales Meter  based on how this goes" << endl;
	int choice = getInt(1, 2);
	//Avoid client
	if (choice == 1)
	{
		cout << "Avoiding the client...." << endl;
		cout << "....." << endl;
		int coinToss = (rand() % 2 + 1);
		if (coinToss == 1)
		{
			cout << "Success! You avoided this client with no hurt to your Sales Meter." << endl;
			cout << "Smart move! - There are bigger fish to fry!" << endl << endl;
		}
		else
		{
			cout << "Oh no! You lost rapport with this client." << endl;
			player1->decreasePipeline(200000);//200k detrement
			cout << "Sales Meter is down $200k" << endl;
		}
	}
	//Engage client
	else if (choice == 2)
		{
		if (player1->hasItem("newSuit"))
		{
			cout << "The client is impressed with your new suit. Sales Meter is up $50k" << endl;
			player1->increasePipeline(50000);
		}
		else if (player1->hasItem("newProduct"))
		{
			cout << "The client is very interested in your new product and wants to order." << endl;
			cout << " Sales Meter is up $100k" << endl;
			player1->increasePipeline(100000);
		}
		
		else if (player1->hasItem("newAd"))
		{
			cout << "The client is enticed by your slick Advertisement!" << endl;
			cout << "Sales Meter is up $100k" << endl;
			player1->increasePipeline(100000);
		}
	else 
		{
			cout << "You have nothing of interest to the client and he is unimpressed." << endl;
			cout << " Sales Meter is down $200k" << endl;
			player1->decreasePipeline(200000);//200k detrement
		}
	}
}
/****************************************************************
Function: getSpaceType
Description: returns the child Class name (i.e. "Market") for this Space. 
Arguments: none
Return type: string
**************************************************************************/
string Market::getSpaceType()
{
	return "Market";
}
/****************************************************************
Function:destructor
Description: empty destructor
Arguments: none
Return type: none
**************************************************************************/
Market::~Market()
{
}
