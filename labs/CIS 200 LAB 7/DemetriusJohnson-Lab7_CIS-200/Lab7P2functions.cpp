/*
* Author: Demetrius Johnson
* Creation Date : 26 Oct 2020
* Modification Date : 26 Oct 2020
* Purpose : .cpp file for program 2 (lab 7) functions
*/

#include "Lab7P2functions.h"



void main_Menu() {

	cout << "---------------------------------------------WELCOME-------------------------------------------\n";
	cout << "This Program will calculate the value of an integer factorial provided by the user (userIntger! = ....)\n";
	cout << "Enter an integer value to be calculated (warning, too large a value will cause stack overflow): ";
	
}

int IntFactorialCalc(const int userValue) {

	int userValCopy = userValue;

	if (userValue < 0) //case: invalid user data
		return -1;


	if (userValue == 0) //Base Case
		return 1; //0! is equal to 1.

	else { //recursive Case
		
		userValCopy--; //userValCopy = userVal - 1 --> factorial n*(n-1)....etc.

		return (userValue * IntFactorialCalc(userValCopy)); //n* (n-1)...etc.
	}

	return 0; //protection return in case above cases are deffective
}

void outputCalculation(int& userVal, int& outputVal) {

	if (outputVal == -1)
		cout << "\nUser has input an INVALID number: " << userVal << "!\nNegative numbers are not allowed in the caclulation of a factorial.\n\n";
	else if (userVal > 12) {
		cout << "\nUser has input an INVALID value to calculate: " << userVal << "! != " << outputVal << ".\n" << endl;
		cout << "The maxmium number that an integer can hold is +/-2,147,483,647\n";
		cout << "12! = 479,001,600 is the largest possible value that can be calculated, all other values yield incorrect results.\n\n";
	}
	else
		cout << "\nUser has input a valid value to calculate: " << userVal << "! = " << outputVal << ".\n" << endl;

}
