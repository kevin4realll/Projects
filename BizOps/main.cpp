/************************************************************************
***Program name: simpleSearch
Author: Kevin Spevacek
Date: 11/29/2019
Description: main function for business game. 
			Creates game object then runs from member functions
			Object is to reach client boardroom after attaining sales lead from foreign office
***********************************************************************/
//#include "pch.h"
#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

bool intCheck(string input, int lowerLimit, int upperLimit);
/**************************************************************
Function:getInt

Description: Gets user integer input and checks if it is between the lower and upper limits.
			-Arguments: None
			-Returns:int
****************************************************************/
int getInt(int lowerLimit, int upperLimit)
{
	bool inputValid = false;
	string input;
	bool inRange = false;

	while (!inputValid && !inRange)
	{
		try
		{
			cout << "Please enter your choice number" << endl;
			getline(cin, input);
			inputValid = intCheck(input, lowerLimit, upperLimit);
			if (!inputValid)
				throw input;
		}
		catch (string inv)
		{
			cout << inv << " is not valid. Please try again" << endl;
		}

		
	}

return atoi(input.c_str());
}
/**************************************************************
Function:intCHeck

Description:input validation function function. Rules out empty and non-digit input
			-Arguments:string user input
			-Returns: bool
****************************************************************/
bool intCheck(string input, int lowerLimit, int upperLimit)
{

	if (input.size() == 0)
	{
		cout << "Empty input" << endl;
		return 0;
	}
	//int check
	for (int i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]))
		{
			return 0;
		}
	}
	//range check
	int inputInt = atoi(input.c_str());
	if (inputInt < lowerLimit || inputInt > upperLimit) {
			return 0;
		}
	return 1;
}
/**************************************************************
Function:main

Description:main function for business game. Creates game object 
		which then runs its own playGame function 
		-Arguments: none
		-Returns:int 
****************************************************************/
int main()
{
	cout << "Welcome to Kevin Spevacek's Biz-Ops Game!" << endl;
	srand(time(NULL));
	bool quitBool = false;
	while (!quitBool)
	{
		cout << endl;
		cout << "*********" << endl;
		cout << "MAIN MENU" << endl;
		cout << "*********" << endl;
		cout << "1. New Game " << endl;
		cout << "2. Exit" << endl;
		int mainChoice = getInt(1,2);
		if (mainChoice ==1)
		{ 
			Game myGame;
			myGame.playGame();
		}
		else if (mainChoice ==2)
		{
			cout << "See you next time!" << endl;
			quitBool = 1;
		}
	}	
return 0;
}

