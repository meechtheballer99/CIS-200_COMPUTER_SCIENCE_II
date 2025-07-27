// DemetriusJohnson-Lab6_CIS-200.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

	*Author: Demetrius Johnson
	*Creation Date: 20 Oct 2020
	*Modification Date: 20 Oct 2020
	*Purpose:  *******


Program 1

Given that arrayIntValues [MAX_ROWS][MAX_COLUMNS] is a 2 dimensional array of positive integers, 
write a C++ function howManyEven to find the total number of even elements in the array. 
It should have input parameter array arrayIntValues. The function should return an integer. 
Also create a C++ function called printArray, with the input parameter array arrayIntValues, 
to print out the elements in the array (be sure to have row and column labels and proper formatting (i.e. column values line up). 
Main must be in one source file and all other functions in a second source file.
The constants MAX_ROWS and MAX_COLUMNS must be accessed globally by defining the following global variables:

const int MAX_ROWS = 3;			or		#define MAX_ROWS 3
const int MAX_COLUMNS = 2;			or		#define MAX_COLUMNS 2

The array arrayIntValues is initialized by the following statement within main():
int arrayIntValues [MAX_ROWS][ MAX_COLUMNS] =  { {3 , 2}, {4, 5}, {2, 2} };

Print out the array and the count of positive even numbers (label appropriately) in function printArray.

User enters a new set of values into the array (must do it at least once) as many times as
they wish and runs printArray against the new array values each time. Be sure to validate input is positive integers.

Validate user input (“y” or “n”) when asking if the user wants to enter a new set of values.



//side note: remember that the each ROW CONTAINS its own COLUMNS in a 2D array; for example (columns DO NOT contain the rows; therefore they are IN or owned by rows):
												ROW1	ROW2	ROW3
int arrayIntValues[MAX_ROWS][MAX_COLUMNS] = { {3 , 2}, {4, 5}, {2, 2} }; notice how each row has (contains in itself) multiple columns; but each column is only apart of 1 row.
*/




#include <iostream>
#include <string>
#include "P1functions.h"
#define MAX_ROWS 3
#define MAX_COLUMNS 2

using namespace std;




int main()
{	

	int arrayIntValues[MAX_ROWS][MAX_COLUMNS] = { {3 , 2}, {4, 5}, {2, 2} };
	char userInput;
	
	openingMenu();
	printArray(arrayIntValues);
	cout << endl;
	

	do {
		cout << "Would you like to set new values into the 2D array? Input 'y' for yes or 'n' for no : ";
		cin >> userInput;
		switch (userInput) {

		case 'y':
			userInput2D_array(arrayIntValues);
			cout << "\n\nHere is your new user-input 2D array printed and displaying total number of Positive Even numbers:\n\n ";
			printArray(arrayIntValues);
			cout << endl;
		case 'n':
			cout << "You have selected '" << userInput << "' to exit the program. Thank you(:\n\n";

		default: 
			cout << "\nYou have input a value (" << userInput << ") other than 'y' or 'n'. Please input a value option.\n";
		}
	} while (userInput != 'n');

	return 0;
}


