// DemetriusJohnson-Lab7_CIS-200.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*


*	*Author: Demetrius Johnson
	*Creation Date: 26 Oct 2020
	*Modification Date: 26 Oct 2020
	*Purpose:  *******


Program 2:

You are to create a recursive function to perform a factorial calculation.

o	int factorial(const int value)
o	return -1 if any negative number passed into the function
o	Calculate the factorial of the number entered by the user

Determine value at which stack overflow occurs.


*/

#include <iostream>
#include <string>
#include "Lab7P2functions.h"

using namespace std;



int main()
{
	int userInt = 0;
	int FactorialCalculation = 0;
	char userChoice = 'y';

	main_Menu();
	cin >> userInt;				//get user value to calculate userInt factorial

	FactorialCalculation = IntFactorialCalc(userInt); // calculate factorial and store it 
	outputCalculation(userInt, FactorialCalculation); //cout the results to user

	//use below while loop to make it easier to test and calculate multiple values to find stack overflow value//


	cout << "Would you like to calculate another value? Type 'y' for yes, or any other key to exit: ";
	cin >> userChoice;
	while (userChoice == 'y') {

		cout << "\n\nEnter an integer value to be calculated (warning, too large a value will cause stack overflow): ";
		cin >> userInt;				//get user value to calculate userInt factorial

		FactorialCalculation = IntFactorialCalc(userInt); // calculate factorial and store it 
		outputCalculation(userInt, FactorialCalculation); //cout the results to user



		cout << "Would you like to calculate another value? Type 'y' for yes, and any other key to exit: ";
		cin >> userChoice;
	}

	return 0;
}



