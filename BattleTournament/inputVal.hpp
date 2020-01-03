/*********************************************************************
** Program:inputVal.hpp
** Author:Kevin Spevacek
** Date:11/20/19
** Description: input validation functino prototypes for use in combat tournament
*********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <functional>
using std::string;
#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

int getInt(int lowerLimit, int upperLimit);
bool intCheck(string input);

#endif // !INPUTVAL_HPP

