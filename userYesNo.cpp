//a borrowbreadcat project. v 1.2 2018-06-25

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//user types yes, no, y, n, YES, NO, et al. failsafe loops until valid entry is given
bool userYesNo()
{
	bool yesno{ false };				//return value
	string userSays{ "undefined" };		//contains user input or yes, no, etc.
	bool validAnswer{ false };			//allows while loop to refuse invalid input
	while (!validAnswer)				//!validAnswer is the same as validAnswer == false
	{
		cout << "Type 'yes' or 'no'.\n";
		cin >> userSays;
		if (userSays == "yes" || userSays == "y" || userSays == "YES" || userSays == "Yes" || userSays == "Y")
		{
			yesno = true;
			validAnswer = true;
		}
		else if (userSays == "no" || userSays == "n" || userSays == "NO" || userSays == "No" || userSays == "N")
		{
			cout << "'No'?  Okay then...\n";
			yesno = false;
			validAnswer = true;
		}
		else //loops back to beginning of while loop if user gave invalid input
		{
			cout << "Invalid input.  In words you might understand, \'" << userSays << "\' doesn't make any sense to me.\n";
			cout << "Look... just try again.\n\n";
			validAnswer = false;
		}
	}
	return yesno;
}
