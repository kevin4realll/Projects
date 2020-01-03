/*********************************************************************
** Program: inputVal.cpp
** Author:Kevin Spevacek
** Date:11/20/19
** Description:inputValidation functions
*********************************************************************/
#include <iostream>
#include <string>
#include <functional>
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
			cout << "Please enter your choice number" << endl;
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
