/*********************************************************************
** Program: Tournament.cpp
** Author:Kevin Spevacek
** Date:11/23/19
** Description:Definition file for Tournament class. Drives simulation
				using Character lineups and combat showing results to the user
*********************************************************************/
#include <iostream>
#include <string>
//#include "pch.hpp"
#include "Tournament.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "inputVal.hpp"

using std::cout;
using std::cin;
using std::endl;

/**************************************************************
Function:constructor 

Description: Initializes tournament object with user defined number of 
			Characters for each team/lineup
			-Arguments: int 
			-Returns: Tournament
****************************************************************/
Tournament::Tournament(int numChars)
{
	characterCount = numChars;
	roundNumber = 1;
	score1 = 0;
	score2 = 0;

}
/**************************************************************
Function: setLineup

Description:sets lineup of Characters with user given names for each team
			-Arguments:none
			-Returns:void
****************************************************************/
void Tournament::setLineup()
{
	cout << "***********************" << endl;
	cout << "TEAM 1 LINEUP SELECTION" << endl;
	cout << "***********************" << endl;
	for (int i = 0; i < characterCount; i++)
	{
		showCharacterMenu();
		int charChoice = getInt(1, 5);
		string newName;
		cout << "Enter Player Character Name: " << endl;
		getline(cin, newName);

		//Set playerOne character
		if (charChoice == 1)
		{
			lineup1.addCharacter(new Barbarian(newName));
			cout << "*************************************************************" << endl;
			cout << "                TEAM 1 HAS Barbarian NAMED " << lineup1.getCharacter()->getPlayerName() << endl;
			cout << "**************************************************************" << endl;
			cout << "Team size is now " << lineup1.getLineupSize() << endl;
		}
		else if (charChoice == 2)
		{
			lineup1.addCharacter(new Vampire(newName));
			cout << "***************************************************************" << endl;
			cout << "               TEAM 1 HAS Vampire NAMED " << lineup1.getCharacter()->getPlayerName() << endl;
			cout << "***************************************************************" << endl;
			cout << "Team size is now " << lineup1.getLineupSize() << endl;	
		}
		else if (charChoice == 3)
		{
			lineup1.addCharacter(new BlueMen(newName));
			cout << "*******************************************************************" << endl;
			cout << "                TEAM 1 HAS BlueMen NAMED " << lineup1.getCharacter()->getPlayerName() << endl;
			cout << "******************************************************************" << endl;
			cout << "Team size is now " << lineup1.getLineupSize() << endl;
		}
		else if (charChoice == 4)
		{
			lineup1.addCharacter(new Medusa(newName));
			cout << "********************************************************************" << endl;
			cout << "                TEAM 1 HAS Medusa NAMED  " << lineup1.getCharacter()->getPlayerName() << endl;
			cout << "*******************************************************************" << endl;
			cout << "Team size is now " << lineup1.getLineupSize() << endl;	
		}
		else if (charChoice == 5)
		{
			lineup1.addCharacter(new HarryPotter(newName));
			cout << "*****************************************************************" << endl;
			cout << "               TEAM 1 HAS Harry Potter NAMED " << lineup1.getCharacter()->getPlayerName() << endl;
			cout << "*****************************************************************" << endl;
			cout << "Team size is now " << lineup1.getLineupSize() << endl;
		}
		cout << "Press enter to continue" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}


	cout << "*************************" << endl;
	cout << "TEAM 2 LINEUP SELECTION" << endl;
	cout << "*************************" << endl;
	for (int i = 0; i < characterCount; i++)
	{
		showCharacterMenu();
		int charChoice = getInt(1, 5);
		string newName;
		cout << "Enter Player Character Name: " << endl;
		getline(cin, newName);

		//Set playerOne character
		if (charChoice == 1)
		{
			lineup2.addCharacter(new Barbarian(newName));
			cout << "********************************************************" << endl;
			cout << "          TEAM 2 HAS Barbarian NAMED: " << lineup2.getCharacter()->getPlayerName() << endl;
			cout << "**********************************************************" << endl; 
			cout << "Team size is now " << lineup2.getLineupSize() << endl;
		}
		else if (charChoice == 2)
		{
			lineup2.addCharacter(new Vampire(newName));
			cout << "*****************************************************************" << endl;
			cout << "          TEAM 2 has Vampire NAMED:  " << lineup2.getCharacter()->getPlayerName()  << endl; 
			cout << "*****************************************************************" << endl;
			cout << "Team size is now " << lineup2.getLineupSize() << endl;	
		}
		else if (charChoice == 3)
		{
			lineup2.addCharacter(new BlueMen(newName));
			cout << "****************************************************************" << endl;
			cout << "          TEAM  2 HAS BlueMen NAMED: " << lineup2.getCharacter()->getPlayerName() << endl; 
			cout << "****************************************************************" << endl;
			cout << "Team size is now " << lineup2.getLineupSize() << endl;
		}
		else if (charChoice == 4)
		{
			lineup2.addCharacter(new Medusa(newName));
			cout << "*****************************************************************" << endl;
			cout << "         TEAM 2 HAS Medusa NAMED: " << lineup2.getCharacter()->getPlayerName() << endl;
			cout << "*****************************************************************" << endl;	
			cout << "Team size is now " << lineup2.getLineupSize() << endl;
		}
		else if (charChoice == 5)
		{
			lineup2.addCharacter(new HarryPotter(newName));
			cout << "****************************************************************" << endl;
			cout << "       TEAM 2 HAS Harry Potter NAMED:  " << lineup2.getCharacter()->getPlayerName() << endl;
			cout << "****************************************************************" << endl;
			cout << "Team size is now " << lineup2.getLineupSize() << endl;
		}
		cout << "Press enter  to continue" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
}

/**************************************************************
Function:showCharacterMenu()

Description:displays main menu of information system to user
			-Arguments: int charNum
			-Returns:void
****************************************************************/
void Tournament::showCharacterMenu()
{
	cout << "CHOOSE YOUR FIGHTER" << endl;
	cout << "1. Barbarian - 12 strength, 0 armor" << endl;
	cout << "2. Vampire - 18 strength, 1 armor" << endl;
	cout << "3. Blue Men 12 strength, 3 armor" << endl;
	cout << "4. Medusa 8 strength, 3 armo" << endl;
	cout << "5. Harry Potter 10 strength, 0 armor" << endl;

}
/**************************************************************
Function:runGame

Description:Drives tournament simulation playing rounds until
			unitl one team lineup is empty
			-Arguments:none
			-Returns:void
****************************************************************/
void Tournament::runGame()
{
	cout << "**********************************" << endl;
	cout << "      BEGIN THE TOURNAMENT!!!!" << endl;
	cout << "**********************************" << endl;

	while (lineup1.getLineupSize() > 0 && lineup2.getLineupSize() > 0)
	{
		runRound(lineup1.getCharacter(), lineup2.getCharacter(), roundNumber);

		//Add dead player 1 to graveyard stack and remove from lineup queue
		//Player 2 recovers
		if (lineup1.getCharacter()->getStrength() <= 0)
		{
			graveyard1.pushCharacter(lineup1.removeCharacter());
			lineup2.getCharacter()->recover();
			lineup2.advance();
			score2++;
		}

		//Add dead player 2 to graveyard stack and remove from lineup queue
		//Player 1 recovers
		if (lineup2.getCharacter()->getStrength() <= 0)
		{
			graveyard2.pushCharacter(lineup2.removeCharacter());
			lineup1.getCharacter()->recover();
			lineup1.advance();
			score1++;
		}

		//Show round results
		showScore();
		roundNumber++;

	}
	//Show Tournament results
	showLoser();
	showWinner();
}

/**************************************************************
Function:attackCharacter

Description: Characters attack by way of defender using takeDamage method after 
			both attack and defense dice have been rolled
			-Arguments:Character* for attacker, Character* for defender
			-Returns:void
****************************************************************/
void Tournament::attackCharacter(Character* attacker, Character* defender)
{
	int attackNum = attacker->rollAttack();
	int defenseNum = defender->rollDefense();
	defender->defend(attackNum, defenseNum);
}

/**************************************************************
Function:runRound

Description: simulates combat between two Character pointers. Calls alternating attacks
			until one Charcter is dead
			-Arguments:Character*, Character*, int
			-Returns:void
****************************************************************/
void Tournament::runRound(Character* char1, Character* char2, int roundNum)
{
	//pull random number from previous labs
	int coinToss = (rand() % 2 + 1);

	cout << "**************************" << endl;
	cout << "----TOURNAMENT ROUND " << roundNum << "---" << endl;
	cout << "Team 1's " << char1->getCharName() << " vs." << " Team 2's " << char2->getCharName() << endl;
	cout << "**************************" << endl << endl;

	while ((char1->getStrength() > 0) && (char2->getStrength() > 0))
	{
		//coin toss for first attack
		if (coinToss == 1)
		{
			attackCharacter(char1, char2);
		}
		else if (coinToss == 2)
		{
			attackCharacter(char2, char1);
		}

		//alternate attacker/defender
		if (coinToss == 1)
		{
			attackCharacter(char2, char1);
		}
		else if (coinToss == 2)
		{
			attackCharacter(char1, char2);
		}

	}
	
	//Display outcome of battle
	//p1 wins
	if ((char1->getStrength() > 0) && (char2->getStrength() <= 0))
	{
		cout << "TEAM 1: "  << char1->getCharName() << " aka " << char1->getPlayerName() << " WINS THE BATTLE!" << endl;
		cout << "Team 2 lost this round and now has " << char2->getPlayerName() << " SENT TO THE  GRAVEYARD!!!." << endl << endl;
	}
	//p2 wins
	else if ((char1->getStrength() <= 0) && (char2->getStrength() > 0))
	{
		cout << "TEAM 2: " << char2->getCharName() << " aka " << char2->getPlayerName() << " WINS THE BATTLE!!!" << endl;
		cout << "Team 1 lost this round and now has " << char1->getPlayerName() << " SENT TO THE GRAVEYARD!!!" << endl << endl;
	}
}
/**************************************************************
Function:showScore

Description:Displays score for each round
			-Arguments:none
			-Returns:void
****************************************************************/
void Tournament::showScore()
{
	cout << "********************************* " << endl;
	cout << "           TEAM SCORES  " << endl;
	cout << "********************************" << endl;
	cout << "Team 1: " << score1 << endl;
	cout << "Team 2: " << score2 << endl;

}
/**************************************************************
Function:showWinner

Description: Displays winning team for the tournament
			-Arguments:none
			-Returns:void
****************************************************************/
void Tournament::showWinner()
{
	cout << "**********************************" << endl;
	cout << "       AND THE WINNER IS....." << endl;
	cout << "***********************************" << endl;
	cout << ".........." << endl;
	cout << "     `  ....... " << endl;
	cout << "           ..... " << endl;

	if (score1 > score2)
	{
		cout << "**************************** " << endl;
		cout << "        TEAM 1!!!" << endl;
		cout << "   CONGRATULATIONS!" << endl;
		cout << "*****************************"  << endl;;
	}
	else if (score1 < score2)
	{
		cout << "******************************" << endl;
		cout << "      TEAM 2!!! " << endl;
		cout << "  CONGRATULATIONS!" << endl;;
		cout << "******************************" << endl;
	}
	else
	{
		cout << "It's a tie!!" << endl << endl;
	}

}
/**************************************************************
Function:showLoser

Description:Displays lsoing character for each round
			-Arguments:none
			-Returns:void
****************************************************************/
void Tournament::showLoser()
{
	cout << "**********************************" << endl;
	cout << "   ---CHARACTER  GRAVEYARD---- " << endl; 
	cout << "**********************************" << endl;
	cout << "TEAM 1: ";
	graveyard1.showGraveyard();
	cout << "TEAM 2: ";
	graveyard2.showGraveyard();

}
/**************************************************************
Function:destructor

Description:deletes memory created for eaceh lineup of characters
			and each graveyard of dead characters
			-Arguments:none
			-Returns:none
****************************************************************/
Tournament::~Tournament()
{
	while (lineup1.getLineupSize() > 0)
	{
		delete lineup1.removeCharacter();
	}
	while (lineup2.getLineupSize() > 0)
	{
		delete lineup2.removeCharacter();
	}
	while (graveyard1.getSize() > 0)
	{
		graveyard1.popCharacter();
	}
	while (graveyard2.getSize() > 0)
	{
		graveyard2.popCharacter();
	}
}
