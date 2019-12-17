/*********************************************************************
** Program: InputVal.hpp
** Author:Kevin Spevacek
** Date:11/29/19
** Description: Header file for inputValidation
*********************************************************************/
#pragma once
#include <iostream>
#include <string>
using std::string;

int getInt(int lowerLimit, int upperLimit);
bool intCheck(string input, int lowerLimit, int upperLimit);
