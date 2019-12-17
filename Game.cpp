/************************************************************************
***Program name: Game.cpp
Author: Kevin Spevacek
Date: 11/29/2019
Description: Definition file for Game Class. Runs the business game 
***********************************************************************/
//#include "pch.h"
#include <iostream>
#include <functional>
#include <set>
#include <string>
#include "Game.hpp"
#include "Space.hpp"
#include "Office.hpp"
#include "Player.hpp"
#include "Market.hpp"
#include "Yacht.hpp"
#include "Hotel.hpp"
using std::cout;
using std::endl;


/****************************************************************
Function: constructor
Description: sets up game Spaces in 4 rows and also sets the special spaces 
			(office, market, boardroom, hotel) 
			Also sets initial Game attributes (pipeline, days, etc.)
Arguments: none 
Return type: Game
**************************************************************************/
Game::Game()
{
	days = 1;
	daysLimit = 14;
	pipeline = 1300000; //$1M

	localOffice = new Hotel;
	Space* tempSpace1 = localOffice;
	Space* tempSpace2 = new Market;
	Space* tempSpace3 = new Market;
	Space* tempSpace4 = new Office;
	
	//point to 1st Space in each row(i.e. index 0)
	spaceRow1 = localOffice;//starting point
	spaceRow2 = tempSpace2;
	spaceRow3 = tempSpace3;
	spaceRow4 = tempSpace4;

/*	//initialize each row of 4 Space pointers to Market pointers
	for (int i = 0; i < 3; i++)
	{
		tempSpace1->setRight(new Market);
		tempSpace1->getRight()->setLeft(tempSpace1);
		tempSpace1 = tempSpace1->getRight();
	}
*/

		//setup first row
		tempSpace1->setRight(new Market);
		tempSpace1->setUp(nullptr);
		tempSpace1->getRight()->setLeft(tempSpace1);
		tempSpace1->getRight()->setUp(nullptr);
		tempSpace1 = tempSpace1->getRight();
		tempSpace1->setRight(new Hotel);
		tempSpace1->getRight()->setLeft(tempSpace1);
		tempSpace1->getRight()->setUp(nullptr);
		tempSpace1 = tempSpace1->getRight();
		tempSpace1->setRight(new Market);
		tempSpace1->getRight()->setLeft(tempSpace1);
		tempSpace1->getRight()->setUp(nullptr);

		//setup second row now including up and down pointers
		tempSpace1 = spaceRow1;
		spaceRow2->setUp(spaceRow1);
		spaceRow1->setDown(spaceRow2);
		tempSpace2 = spaceRow2;

		tempSpace2->setRight(new Office);
		tempSpace2->getRight()->setLeft(tempSpace2);
		tempSpace2->getRight()->setUp(tempSpace1->getRight());
		tempSpace1->getRight()->setDown(tempSpace2->getRight());
		tempSpace1 = tempSpace1->getRight();
		tempSpace2 = tempSpace2->getRight();
		tempSpace2->setRight(new Market);
		tempSpace2->getRight()->setLeft(tempSpace2);
		tempSpace2->getRight()->setUp(tempSpace1->getRight());
		tempSpace1->getRight()->setDown(tempSpace2->getRight());
		tempSpace1 = tempSpace1->getRight();
		tempSpace2 = tempSpace2->getRight();
		tempSpace2->setRight(new Office);
		tempSpace2->getRight()->setLeft(tempSpace2);
		tempSpace2->getRight()->setUp(tempSpace1->getRight());
		tempSpace1->getRight()->setDown(tempSpace2->getRight());

		//setup third row 
		tempSpace2 = spaceRow2;
		spaceRow3->setUp(spaceRow2);
		spaceRow2->setDown(spaceRow3);
		tempSpace3 = spaceRow3;

		tempSpace3->setRight(new Market);
		tempSpace3->getRight()->setLeft(tempSpace3);
		tempSpace3->getRight()->setUp(tempSpace2->getRight());
		tempSpace2->getRight()->setDown(tempSpace3->getRight());
		tempSpace2 = tempSpace2->getRight();
		tempSpace3 = tempSpace3->getRight();
		tempSpace3->setRight(new Hotel);
		tempSpace3->getRight()->setLeft(tempSpace3);
		tempSpace3->getRight()->setUp(tempSpace2->getRight());
		tempSpace2->getRight()->setDown(tempSpace3->getRight());
		tempSpace2 = tempSpace2->getRight();
		tempSpace3 = tempSpace3->getRight();
		tempSpace3->setRight(new Market);
		tempSpace3->getRight()->setLeft(tempSpace3);
		tempSpace3->getRight()->setUp(tempSpace2->getRight());
		tempSpace2->getRight()->setDown(tempSpace3->getRight());
		

		//setup fourth row 
		tempSpace3 = spaceRow3;
		spaceRow4->setUp(spaceRow3);
		spaceRow3->setDown(spaceRow4);
		tempSpace4 = spaceRow4;

		tempSpace4->setRight(new Market);
		tempSpace4->getRight()->setLeft(tempSpace4);
		tempSpace4->getRight()->setUp(tempSpace3->getRight());
		tempSpace3->getRight()->setDown(tempSpace4->getRight());
		tempSpace3 = tempSpace3->getRight();
		tempSpace4 = tempSpace4->getRight();
		tempSpace4->setRight(new Market);
		tempSpace4->getRight()->setLeft(tempSpace4);
		tempSpace4->getRight()->setUp(tempSpace3->getRight());
		tempSpace3->getRight()->setDown(tempSpace4->getRight());
		tempSpace3 = tempSpace3->getRight();
		tempSpace4 = tempSpace4->getRight();
		tempSpace4->setRight(new Yacht);
		tempSpace4->getRight()->setLeft(tempSpace4);
		tempSpace4->getRight()->setUp(tempSpace3->getRight());
		tempSpace3->getRight()->setDown(tempSpace4->getRight());

	//Creates player at 1st room in row 1
	//Will be Office Space (see localOffice)
	player1 = new Player(spaceRow1);

}
/****************************************************************
Function:prinMenu
Description: prints the Business Game goal and other information for the user
Arguments:none
Return type:void
**************************************************************************/
void Game::printMenu()
{
	cout << "*******************" << endl;
	cout << "   BIZ-OPS GAME " << endl;
	cout << "********************" << endl;
	cout << "Goal: " << endl;
	cout << "You are a Sales Dog and need to close a deal" 
	 " with the Big Dog on his Yacht." << endl << endl;

	cout << "Rules:" << endl;
	cout << "Big Dog will not see you without a Sales Lead and at least $1M Sales Meter " << endl;
	cout << "Your Sales Meter  also must not fall below $500k or you will be unable to continue." << endl;
	cout << "Finally you only have **" << daysLimit << "** days to close before Big Dog goes with a competitor." << endl << endl;
	
	cout << "Setup:" << endl;
	cout << "You will begin at the Diamond Plaza hotel - Enjoy the Top Floor view!" << endl;
	cout << "The Sales Lead may only be acquired by working in an office!" << endl;
	cout << "Your Sales Meter starts at **$1.3M!** - be careful of small dog clients in the Market!" << endl;
	cout << "Good luck!!" << endl << endl;
}

/****************************************************************
Function:printRow
Description: prints the game board row defined by the argument
Arguments:Space*
Return type:void
**************************************************************************/
void Game::printRow(Space* row)
{
	Space* tempSpace = row;

	while (tempSpace != nullptr)
	{
		if (player1->getCurSpace() == tempSpace)
		{
			cout << "P ";
		}
		else if (tempSpace->getSpaceType() == "Yacht")
		{
			cout << "Y ";
		}
		/*else if (!tempSpace->isFound())
		{
			cout << "X" << endl;
		}
		*/
		else if (tempSpace->getSpaceType() == "Market")
		{
			cout << "M ";
		}
		else if (tempSpace->getSpaceType() == "Hotel")
		{
			cout << "H ";
		}
		else if (tempSpace->getSpaceType() == "Office")
		{
			cout << "O ";
		}
		/*else if (tempSpace->getSpaceType() == "Empty")
		{
			cout << "X" << endl;
		}
		*/
		tempSpace = tempSpace->getRight();
	}
	cout << endl;

}
/****************************************************************
Function:printMap()
Description:prints the game board one row at a time after each move/turn
Arguments:none
Return type:void
**************************************************************************/
void Game::printMap()
{
	cout << "The Current Game Map is Shown below" << endl;
	cout << "P is your Player location" << endl;
	cout << "O are offices" << endl;
	cout << "M is the Market"  << endl;
	cout << "H are hotels" << endl;
	cout << "Y is the Big Dog's Yacht" << endl << endl;

	printRow(spaceRow1);
	printRow(spaceRow2);
	printRow(spaceRow3);
	printRow(spaceRow4);
	cout << endl;
}

/****************************************************************
Function:playGame
Description:runs Business Game simulation.
			Runs function of the current Space, checks if game is complete,
			Then 
Arguments:
Return type:void
**************************************************************************/
void Game::playGame()
{
	printMenu();
	Space* nextSpace = NULL;
	bool gameOver = false;

	while (!gameOver)
	{
		//Show map and run function of current Space
		printMap();
		cout << "Day #" << days << endl;
		player1->getCurSpace()->spaceFunction(player1);

		//Check if winning/losing conditions are met
		if (player1->getClosedDeal() == true)
		{
			gameOver = true;
			cout << "The deal is closed! Enjoy the commission $$$$!" << endl;
			cout << "*************************" << endl;
			cout << " BIZ-OPS GAME COMPLETE!!" << endl;
			cout << "*************************" << endl;
			break;
		}

		else if (player1->isBankrupt() == true)
		{
			gameOver = true;
			cout << endl <<  "OH NO! Your Sales Meter is too low to continue" << endl;
			cout << "**********" << endl;
			cout << "GAME OVER" << endl;
			cout << "***********" << endl;
		}

		else if (days == daysLimit)
		{
			gameOver = true;
			cout << endl <<  "OH NO! You've taken too long and the Big Dog has gone to a competitor" << endl;
			cout << "**********" << endl;
			cout << "GAME OVER" << endl;
			cout << "***********" << endl;
		}

		//Continue player1 to next space
		while ((nextSpace == nullptr) && (!gameOver))
		{
			cout << "Your Sales Meter is now $" << player1->getPipeline() << endl;
			printMap();
			cout << "Which space do you want to move to?" << endl;
			cout << "1. Up" << endl;
			cout << "2. Down" << endl;
			cout << "3. Left" << endl;
			cout << "4. Right" << endl;
			int nextChoice = getInt(1, 4);

			if (nextChoice == 1) //Up
			{
				nextSpace = player1->getCurSpace()->getUp();
			}
			else if (nextChoice == 2) //Down
			{
				nextSpace = player1->getCurSpace()->getDown();
			}
			else if (nextChoice == 3) //Left
			{
				nextSpace = player1->getCurSpace()->getLeft();
			}
			else if (nextChoice == 4) //Right
			{
				nextSpace = player1->getCurSpace()->getRight();
			}

			player1->movePlayer(nextSpace);

		}
		days++;
		nextSpace = nullptr;
	}

}
/****************************************************************
Function:destructor
Description:Game class destructor deletes Space pointers row by row
		and finally the player poniter
Arguments:none
Return type:none
**************************************************************************/
Game::~Game()
{
	Space* tempSpace1 = spaceRow1;
	Space* tempSpace2 = spaceRow2;
	Space* tempSpace3 = spaceRow3;
	Space* tempSpace4 = spaceRow4;

	//delete each row of Space pointers
	while(tempSpace1->getRight()!= nullptr)
	{
		tempSpace1 = tempSpace1->getRight();
		delete tempSpace1->getLeft();
	}
	delete tempSpace1;

	while(tempSpace2->getRight()!= nullptr)
	{
		tempSpace2 = tempSpace2->getRight();
		delete tempSpace2->getLeft();
	}
	delete tempSpace2;

	while(tempSpace3->getRight()!= nullptr)
	{
		tempSpace3 = tempSpace3->getRight();
		delete tempSpace3->getLeft();
	}
	delete tempSpace3;

	while(tempSpace4->getRight()!= nullptr)
	{
		tempSpace4 = tempSpace4->getRight();
		delete tempSpace4->getLeft();
	}
	delete tempSpace4;
	delete player1; 
}
