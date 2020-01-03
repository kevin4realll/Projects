/*********************************************************************
** Program: Tournament.hpp
** Author:Kevin Spevacek
** Date:11/18/2019
** Description:Implementation file for Tournament class in combat game tournament
*********************************************************************/
#pragma once
#include "Lineup.hpp"
#include "Graveyard.hpp"
#include "Character.hpp"

class Tournament
{
private:
	int characterCount;
	int roundNumber;
	Lineup lineup1;
	Lineup lineup2;
	Graveyard graveyard1;
	Graveyard graveyard2;
	int score1;
	int score2;
	void attackCharacter(Character* attacker, Character* defender);
	void runRound(Character* char1, Character* char2, int roundNum);
	void showScore();
	void showWinner();
	void showLoser();
//	void showCharacterMenu();
public:
	Tournament(int numCharacters);
	void showCharacterMenu();
	void setLineup();
	void runGame();
	~Tournament();
};

