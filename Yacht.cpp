/************************************************************************
***Program namee:Yacht.cpp
Author: Kevin Spevacek
Date: 11/30/2019
Description: Definition file for Yacht class in business game
			Derived class from Space class. Final Space of game
			and requires Player to have salesLead item to advance/win
***********************************************************************/
//#include "pch.h"
#include "Yacht.hpp"
#include <cstdlib>
using std::string;
using std::cout;
using std::endl;
/****************************************************************
Function:constructor
Description:
Arguments:none
Return type:Briefcase
**************************************************************************/
Yacht::Yacht() : Space() 
{

}
/****************************************************************
Function:constructor
Description:creates Yacht space inherits 4 adjacent space pointers
Arguments:4 Space pointers
Return type:Boardroom
**************************************************************************/
Yacht::Yacht(Space* up, Space* down, Space* left, Space* right) : Space(up, down, left, right)
{

}
/****************************************************************
Function:spaceFunction
Description:Yacht spaceFunction is final Space for client negotiation.
            Player must have the salesLead item in order to negotiatie
			with the client. Negotiations then simulated with 70% chance of success
Arguments: Player*
Return type: void
**************************************************************************/
void Yacht::spaceFunction(Player* player1)
{
	if (!(player1->hasItem("salesLead") && (player1->getPipeline() > 1000000)))
	{
		cout << "Big Dog will not see you!!" << endl;
		cout << "You must have without an appointment and $1M Sales Meter!" << endl;
		cout << "Go back to an office and make some calls!" << endl;
	}
	else
	{
		cout << endl;
		cout << "********************" <<endl;
		cout << " BIG DOG'S YACHT" << endl;	
		cout << "********************" << endl;
		cout << "........" << endl;
		cout << "...........NEGOTIATING...." << endl;
		cout << "......" << endl;
		cout << ".... Schmoozing ..." << endl;
		cout << "...." << endl;
		cout << "It's now time to close!!" << endl;
		cout << "........" << endl << endl;
		int win = (rand() % 100 + 1);
		if (win >= 20)
		{
			cout << "*******************" << endl; 
			cout << "CONGRATULATIONS!!!! " << endl;
			cout << "*******************" << endl;
			player1->setClosedDeal(true);
		}
		else
		{
			cout << "*******" << endl;
			cout << " OH NO!" << endl;
			cout << "*******" << endl;
			cout << " You were unsuccessful in negotiations" << endl;
			cout << "Big Dog is  dissatisfied and you are now Black Listed!" << endl;
			cout << " Sales Meter is down $1M" << endl;
			player1->decreasePipeline(1000000);
		}
	}

}
/****************************************************************
Function:getSpaceType
Description:returns Space type for printing the game board
Arguments:none
Return type:void
**************************************************************************/
string Yacht::getSpaceType()
{
	return "Yacht";
}
/****************************************************************
Function:destructor
Description:
Arguments:
Return type:
**************************************************************************/
Yacht::~Yacht()
{
}
