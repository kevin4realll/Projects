/************************************************************************
***Program namee:Hotel.cpp
Author: Kevin Spevacek
Date: 11/30/2019
Description: Implementation file for Hotel class in business game
			Derived from Space class, Player can rest for an increased
			sales pipeline though also losing a day to close the client deal
***********************************************************************/
//#include "pch.h"
#include "Hotel.hpp"
#include <cstdlib>
using std::string;
using std::set;
using std::cout;
using std::endl;

/****************************************************************
Function:constructor
Description: Hotel space constructor
Arguments:none
Return type:Hotel
**************************************************************************/
Hotel::Hotel() : Space()
{
}
/****************************************************************
Function:constructor
Description: Hotel space constructor
Arguments: 4 Space*'s
Return type:Hotel
**************************************************************************/
Hotel::Hotel(Space* up, Space* down, Space* left, Space* right) : Space(up, down, left, right)
{

}
/****************************************************************
Function:printMenu
Description: Display Hotel space menu
Arguments:none
Return type:void
**************************************************************************/
void Hotel::printMenu()
{
	cout << "****************************" << endl;
	cout << "Welcome to the Diamond Plaza" << endl;
	cout << "*****************************" << endl << endl;
	cout << "Would you like to stay the night and recouperate?" << endl;
	cout << "Enter 1 for yes or 2 for no" << endl;
}
/****************************************************************
Function:spaceFunction
Description:Hotel space allows Player to rest resulting in increased pipeline 
Arguments:Player*
Return type:void
**************************************************************************/
void Hotel::spaceFunction(Player* player1)
{
	printMenu();
	int choice = getInt(1, 2);
	if (choice == 1)
	{
		cout << "..." << endl;
		cout << ".....ZZzzz" << endl;
		cout << ".....ZZZzzzzzzzz" << endl;
		int coinToss = (rand() % 2) + 1;
		if (coinToss == 1)
		{
			cout << "You are refreshed and closed another deal! This one is $200k!" << endl;
			player1->increasePipeline(200000);//$200k increase for rest
			cout << "Now grab some coffee and go get the Big Dog!" << endl << endl;
		}
		else if(coinToss == 2)
		{
			cout << "You are refreshed and closed another deal! This one is $100k!" << endl;
			player1->increasePipeline(100000);//$100k increase for rest
			cout << "Grab some coffee and go get the Big Dog!" << endl << endl;
		}
	}
	else if (choice == 2)
	{
		cout << "See you next time!" << endl << endl;
	}

}
/****************************************************************
Function:getSpaceType
Description:gets the Hotel space type
Arguments:none
Return type:string
**************************************************************************/
string Hotel::getSpaceType()
{
	return "Hotel";
}
/****************************************************************
Function:destructor
Description: Hotel destructor
Arguments: none
Return type:none
**************************************************************************/
Hotel::~Hotel()
{
}
