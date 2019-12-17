/************************************************************************
***Program name: Space.cpp
Author: Kevin Spevacek
Date: 11/29/2019
Description: Implementation file for Space Class in Business Game
			Class is abstract base class with derived spaces including
			office, marketplace, and boardroom
***********************************************************************/
//#include "pch.h"
#include "Space.hpp"

/****************************************************************
Function:constructor
Description: Creates Space object with initial attributes. 4 adjacent Space pointers set to NULL
Arguments: none
Return type: Space
**************************************************************************/
Space::Space()
{
	up = NULL;
	down = NULL;
	right = NULL;
	left = NULL;

}
/****************************************************************
Function:constructor
Description: Creates Space object with initial attributes. 4 adjacent Space pointers set to arguments
Arguments: none
Return type: Space
**************************************************************************/
Space::Space(Space* up, Space* down, Space* left, Space* right)
{
	this->up = up;
	this->down = down;
	this->left = left;
	this->right = right;
}

/****************************************************************
Function: setUp
Description:sets Space* to Space above current Space of Player object
Arguments: Space*
Return type: void
**************************************************************************/
void Space::setUp(Space* up)
{
	this->up = up;
}
/****************************************************************
Function:etDown
Description: sets Space* down to the Space below the current Player Space
Arguments: Space*
Return type: void
**************************************************************************/
void Space::setDown(Space* down)
{
	this->down = down;
}
/****************************************************************
Function:setLeft
Description: sets Space* left to the Space left of the current Player Space
Arguments: Space*
Return type:void
**************************************************************************/
void Space::setLeft(Space* left)
{
	this->left = left;
}
/****************************************************************
Function:setRight
Description:sets Space* right to the Space right of the current Player Space
Arguments: Space*
Return type: void
**************************************************************************/
void Space::setRight(Space* right)
{
	this->right = right;
}
/****************************************************************
Function:getRight
Description:returns pointer to the Space right of the current Space
Arguments:noen
Return type:Space*
**************************************************************************/
Space* Space::getRight()
{
	return right;
}
/****************************************************************
Function:getLeft
Description:returns pointer to the Space left of the current Space
Arguments:none
Return type:Space*
**************************************************************************/
Space* Space::getLeft()
{
	return left;
}
/****************************************************************
Function:getUp
Description:returns pointer to the Space above the current Space
Arguments:none
Return type:Space*
**************************************************************************/
Space* Space::getUp()
{
	return up;
}
/****************************************************************
Function:getDown
Description:returns pointer to the Space below the current Space
Arguments:none
Return type:Space*
**************************************************************************/
Space* Space::getDown()
{
	return down;
}

/****************************************************************
Function:destructor
Description: empty desctructor for Space object
Arguments:none
Return type:none
**************************************************************************/
Space::~Space()
{

}
