// KinematicsWizard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h> // * sqrt *  and  * pow *

#include "userYesNo.h"

using namespace std;

//global variables
double t{ 1 };			//s		how much time passes during event in question
double v1{ 2 };			//m/s	initial velocity t = 0
double v2{ 4 };			//m/s	final velocity after given time has passed
double d{ 3 };			//m		total distance traveled after time t has passed
double a{ 2 };			//m/s^2	constant acceleration of the object in question
bool tKnown{ false };	//is time known?
bool v1Known{ false };	//is initial velocity known?
bool v2Known{ false };	//is final velocity known?
bool dKnown{ false };	//is distance known?
bool aKnown{ false };	//is acceleration known?
//int knownCount{ 0 };	UNIMPLEMENTED //this helps the program determine whether there is enough info to calculate stuff.


//welcome, state purpose, version
void introductionText()
{
	cout << "\tWelcome to borrowbreadcat's KINEMATICS WIZARD.\n";
	cout << "\tThis is a practice coding project for me while I learn to code C++.\n";
	cout << "\tThis program will easily calculate the values of an object's Newtonian motion properties.\n\n";
	cout << "\t\tVERSION HISTORY\n";
	cout << "\t\tver 1.0 2018-07-12: suffers from floating point arithmetic rounding error. works otherwise.\n";
	cout << "\t\tver 0.5 2018-07-12: squashing bugs. bug with solving for d remains.\n";
	cout << "\t\tver 0.4 2018-07-10: core programming. runs start to end. buggy. \n";
	cout << "\t\tver 0.3 2018-07-09: core programming \n";
	cout << "\t\tver 0.2 2018-07-04: core programming \n";
	cout << "\t\tver 0.1 2018-06-25: core programming \n\n";
}

//  I can't figure how to use a function parameter to change which global variable the function affects.
//  I'm sorta guessing that this is where pointers come in handy, and I have to do it the dumb way until I learn pointers.


void listVariables()
{
	cout << "\nAlright, let's review what we have:\n\n";
	if (tKnown) {
		cout << "\t t  = \t " << t << " seconds\n";
	}
	else if (!tKnown)
	{
		cout << "\t t  = \t ?? seconds\n";
	}

	if (v1Known) {
		cout << "\t v1 = \t " << v1 << " meters per second \n";
	}
	else if (!v1Known) {
		cout << "\t v1 = \t ?? meters per second \n";
	}

	if (aKnown) {
		cout << "\t a  = \t " << a << " meters per second per second \n";
	}
	else if (!aKnown) {
		cout << "\t a  = \t ?? meters per second per second \n";
	}

	if (v2Known) {
		cout << "\t v2 = \t " << v2 << " meters per second \n";
	}
	else if (!v2Known) {
		cout << "\t v2 = \t ?? meters per second \n";
	}

	if (dKnown) {
		cout << "\t d  = \t " << d << " meters \n";
	}
	else if (!dKnown) {
		cout << "\t d  = \t ?? meters \n";
	}

}

//figuring out the variables.
int requestKnownVariables() 
{
	cout << "First, I will go down a list of variables commonly found in kinematics word problems.\n";
	cout << "I say a variable, you say if you know the value or not, then we do another one.  Easy for you, right? \n";

	int count{ 0 };
	bool redo{ true };
	bool known{ false };
	while (redo)
	{
		cout << "For each known variable, you'll type a number (decimals acceptable).\n";
		count = 0;

		cout << "\nDo we know the value of t, the total time of the event?\n"; //getting t
		known = userYesNo();
		if (known)
		{
			tKnown = true;
			cout << "What is the total time?  How long, in seconds, was the entire event in question?\n";
			cout << "t = ";
			cin >> t;
			count += 1;
		}
		else if (!known)
		{
			cout << "time is an unknown.\n";
			tKnown = false;
		}

		cout << "\nDo we know the value of v1, the initial velocity?\n"; //getting v1
		known = userYesNo();
		if (known)
		{
			v1Known = true;
			cout << "What is the initial velocity (m/s) of the object in question?\n";
			cout << "v1 = ";
			cin >> v1;
			count += 1;
		}
		else if (!known)
		{
			v1Known = false;
			cout << "initial velocity is an unknown.\n";
		}

		cout << "\nDo we know the acceleration of the object?\n"; //getting a
		known = userYesNo();
		if (known)
		{
			aKnown = true;
			cout << "What was the acceleration (m/s^2) during the event?\n";
			cout << "a = ";
			cin >> a;
			count += 1;
		}
		else if (!known)
		{
			aKnown = false;
			cout << "acceleration is an unknown.\n";
		}

		cout << "\nDo we know the final velocity of the object at the end of the event?\n"; //getting v2
		known = userYesNo();
		if (known)
		{
			v2Known = true;
			cout << "How fast was the object moving after the time passed?\n";
			cout << "v2 = ";
			cin >> v2;
			count += 1;
		}
		else if (!known)
		{
			v2Known = false;
			cout << "final velocity is an unknown.\n";
		}

		cout << "\nDo we know the total distance the object traveled?\n"; //getting d
		known = userYesNo();
		if (known)
		{
			dKnown = true;
			cout << "In the end how far, in meters, did the object travel?\n";
			cout << "d = ";
			cin >> d;
			count += 1;
		}
		else if (!known)
		{
			dKnown = false;
			cout << "distance is an unknown.\n";
		}

		listVariables();
		cout << "\nLook 'em over.  If it's not right, then I'll let you do it again.\n";
		cout << "Are these values and unknowns right?\n";
		redo = !userYesNo();
	}
	return count;
}

void weNeedV1()
{
	cout << "Well this is awkward. Is is possible to solve for another variable without the value of v1?? \n";
}

void solve_t()
{
	if (!v1Known)
	{	weNeedV1();	}
	
	else if (!v2Known)
	{	
		t =  (sqrt((pow(2.0, v1)) + (2 * a * d))) - v1;	//tricky
		tKnown = true;
	}
	
	else if (!aKnown)
	{	
		t = (2 * d) / (v2 + v1); 
		tKnown = true;
	}
	
	else //if (!dKnown)
	{	
		t = (v2 - v1) / a; 
		tKnown = true;
	}

}

void solve_v1()
{
	if (!tKnown)
	{	
		v1 = sqrt((pow(2.0, v2)) - (2 * a * d)); 
		v1Known = true;
	}

	else if (!v2Known)
	{	
		v1 = ( (d / t) - ( (a * t)/2) );
		v1Known = true;
	}

	else if (!aKnown)
	{	
		v1 = (2 * d / t) - v2;
		v1Known = true;
	}

	else //if (!dKnown)
	{
		v1 = v2 - (a * t);
		v1Known = true;
	}
}

void solve_v2()
{
	if (!tKnown)
	{
		v2 = sqrt((pow(2.0, v1)) + (2 * a * d));
		v2Known = true;
	}

	else if (!v1Known)
	{	weNeedV1();	}

	else if (!aKnown)
	{	
		v2 = (2 * d / t) - v1;
		v2Known = true;
	}

	else //if (!dKnown)
	{	
		v2 = v1 + (a * t);
		v2Known = true;
	}
}

void solve_a()
{
	if (!tKnown)
	{	
		a = ((pow(2.0, v2)) - (pow(2.0, v1))) / (2 * d);
		aKnown = true;
	}
	
	else if (!v1Known)
	{	weNeedV1();	}
	
	else if (!v2Known)
	{	
		a = (2 * ((d / t) - v1)) - t;
		aKnown = true;
	}
	
	else //if (!dKnown)
	{	
		a = (v2 - v1) / t;
		aKnown = true;
	}
}

void solve_d()
{
	if (!tKnown)
	{	
		d = (pow(2.0, v2) - pow(2.0, v1)) / (2 * a);
		dKnown = true;
	}

	else if (!v1Known)
	{	weNeedV1();	}

	else if (!v2Known)
	{	
		d = (v1 * t) + (0.5 * a * pow(2.0, t));
		dKnown = true;
	}

	else //if (!aKnown)
	{
		d = ((v2 - v1) / 2) * t;
		dKnown = true;
	}
}

void solveTheUnknowns()
{
	if (!tKnown)
	{	solve_t();	}

	if (!v1Known)
	{	solve_v1();	}

	if (!v2Known)
	{	solve_v2();	}

	if (!aKnown)
	{	solve_a();	}

	if (!dKnown);
	{	solve_d();	}
	
}


int solveUnknownVariables(int knownCount)
{
	if (knownCount == 0)
	{
		cout << "\nUm... you don't know anything? Then... I guess... make something up?\n";
		cout << "I'm not good at making stuff up.  That's your job!\n";
		return 0;
	}

	if (knownCount == 1)
	{
		cout << "\nYou only know one variable?  I can't work with that!  We need at least 3 knowns to solve anything! \n";
		return 0;
	}

	if (knownCount == 2)
	{
		cout << "\nYou only know two variables?  I'll need at least one more to be able to solve anything! \n";
		return 0;
	}

	if (knownCount == 3)
	{
		cout << "\nThree known and two unknown?  Tricky, but nothing we can't handle!\n";
		solveTheUnknowns();
	}

	if (knownCount == 4)
	{
		cout << "\nOnly one unknown?  Piece of cake!\n";
		solveTheUnknowns();
	}

	if (knownCount == 5)
	{
		cout << "\nErm... what did you need ME to do?  You have all the variables!  Go play or something!\n";
		return 0;
	}

	return 0;
}

int main()
{
	introductionText();
	bool doRepeat{ true }; //helps loop the program to beginning if user doesn't want to quit
	int count{ 0 };
	while (doRepeat == true)
	{
		count = requestKnownVariables();
		solveUnknownVariables(count);
		cout << "This goes here...\n square that... \n carry the two... \n THERE! \n\n";
		listVariables();
		cout << "\nI hope I did that right!  Make sure you check my work.  Does it all makes logical sense?\n";
		cout << "What am I saying?  You're using a computer to solve simple algebra problems; what do you know?\n\n";
		//	adjustValues();
		cout << "\nWould you like to start over?\n";
		doRepeat = userYesNo();
	}
	cout << "\nThanks for using the Kinematics wizard!  See ya next time!\n";
	return 0;
}

