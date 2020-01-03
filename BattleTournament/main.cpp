/*********************************************************************
** Program:main.cpp
** Author:Kevin Spevacek
** Date:11/23/19
** Description:main function for combat tournament. Gets team size and 
				then creates tournament to run the full simulation
*********************************************************************/

//#include "pch.hpp"
#include <ctime>
#include <iostream>
#include <string>
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Lineup.hpp"
#include "ListNode.hpp"
#include "Graveyard.hpp"
#include "Tournament.hpp"
#include "inputVal.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;


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

	while (!inputValid)
	{
		try
		{
			cout << "Enter numeric choice:" << endl;
			getline(cin, input);
			inputValid = intCheck(input);
			if (!inputValid)
				throw input;
		}
		catch (string inv)
		{
			cout << inv << " is not valid. Please try again" << endl;
		}

		int inputInt = atoi(input.c_str());
		if (inputInt < lowerLimit || inputInt > upperLimit) {
			cout << "input is out of range. Please try again" << endl;
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
bool intCheck(string input)
{

	if (input.size() == 0)
	{
		cout << "Empty input" << endl;
		return 0;
	}

	for (int i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]))
		{
			return 0;
		}
	}

	return 1;

}

/**************************************************************
Function: main

Description: main function for Battle Tournament
			Gets input for team size then creates tournament object
			to run the simulation
			-Arguments: none
			-Returns: int
****************************************************************/
int main()
{
	srand(time(0));
	cout << "************************************************" << endl; 
	cout << "Welcome to Kevin Spevacek's Battle Tournament!!!" << endl;
	cout << "************************************************" << endl;
	bool quitBool = 1;

	while (quitBool != 0)
	{	
		cout << "********************" << endl;
		cout << " BATTLE TOURNAMENT" << endl;
		cout << "    MAIN MENU" << endl;
		cout << "********************" << endl;
		cout << " 1. Play Tournament" << endl;
		cout << " 2. Exit" << endl;
		int mainChoice = getInt(1,2);
		if (mainChoice == 1)
		{
			

			cout << "***************************" << endl;
			cout << "     TOURNAMENT SETUP " << endl;
			cout << "***************************" << endl;
			cout << "TEAM 1 VS TEAM 2!" << endl;
			cout << "Enter Team Size: (NOTE: Both Teams Will Have THe Same Size" << endl;
			int teamSize = getInt(1, 5);
			cout << "*************************************************" << endl;
			cout << "       " << teamSize << " V " << teamSize << " TOURNAMENT!!" << endl;
			cout << "***********************************************" << endl;
			Tournament myTournament(teamSize);
			myTournament.setLineup();
			myTournament.runGame();
			cout << "*****************" << endl;
			cout << "   GAME COMPLETE"  << endl;
			cout << "    THANK YOU!!!" <<  endl;
			cout << "*****************" << endl;
		}
		else if (mainChoice == 2)
		{
			cout << "GAME EXIT - GOODBVYE " << endl;
			quitBool =  0;
		}
	}

	return 0;
}

