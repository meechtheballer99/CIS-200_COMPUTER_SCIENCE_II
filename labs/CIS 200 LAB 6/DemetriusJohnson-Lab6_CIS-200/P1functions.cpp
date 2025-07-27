

#include "P1functions.h"


void openingMenu(void) {
	
	cout << "-------------------------------WELCOME-----------------------------------\n\n";
	cout << "This program reads the number of Positive values that a user enters for a 2D array.\n";
	cout << "Total number of input values accepted from user is 3x2 = 6 values; values may only be POSITIVE.\n\n";
	cout << "The array is of size 3x2(3 rows, 2 columns in each row),\nand input gathers all columns of a row before moving to next row's input.\n\n";
	cout << "In addition, the program will output a display table of the current user 2D array.\n\n";
	cout << "As an example, the default 2D array in this program is:\n\nint arrayIntValues[MAX_ROWS][MAX_COLUMNS] = { {3 , 2}, {4, 5}, {2, 2} }\n";
	cout << "The total number of positive even numbers in the array is:\n\n";


}

int numPosAndEven_InArray(int arrayIntValues[ROWS][COLUMNS]) {

	int evenNumCounter = 0, rCount = 0, cCount = 0;

	while (rCount < ROWS) { // use this loop to iterate through each row of the 2D array
		
		for (cCount = 0; cCount < COLUMNS; cCount++) { //use this loop to iterate through each column of each row of the 2D array
			if ((arrayIntValues[rCount][cCount] % 2) == 0)
				if (arrayIntValues[rCount][cCount] != 0)
					evenNumCounter++;
		}
		rCount++;
	}

	return evenNumCounter;
}


void printArray(int arrayIntValues[ROWS][COLUMNS]) {
	int rCount = 0;
	int cCount = 0;

	for (cCount = 0; cCount < COLUMNS; cCount++) { //use this loop for outer layers to designate columns of the 2D array
		
		cout << setw(16) << "COLUMN_" << cCount;
	

	}
	cout << endl << endl;
	while (rCount < ROWS) { // use this loop to output each row and row number
		cout << "ROW_" << rCount << ":";
		
		for (cCount = 0; cCount < COLUMNS; cCount++){ //use this loop to actually output the columns of each row of the 2D array
			if (cCount == 0)
				cout << right << setw(10) << arrayIntValues[rCount][cCount];
			else
				cout << right << setw(17) << arrayIntValues[rCount][cCount];
		}
		cout <<  endl << endl << endl;
		rCount++;
	}

	cout << "The total number of Positive Even Numbers in the array is: " << numPosAndEven_InArray(arrayIntValues);

}

void userInput2D_array(int arrayIntValues[ROWS][COLUMNS]) {

	int rCount = 0, cCount = 0, userInput = 0;
	
	
	while (rCount < ROWS) { // use this loop to iterate through each row of the 2D array

		for (cCount = 0; cCount < COLUMNS; cCount++) { //use this loop to iterate through each column of each row of the 2D array
			cout << "Input your value for position (row, column) " << "(" << rCount << ", " << cCount << "): ";
			cin >> userInput;
			while (cin.fail() == true) {
				cin.clear();
				cin.ignore(100); //set streamsize limit to 100, to clear the next 100 characters inside the cin input buffer stream -- likely a user won't enter more than 100 characters since program asks only for 1.
				cout << "\nINVALID USER INPUT, please input a number >= 0:";
				cin >> userInput;
			}
			arrayIntValues[rCount][cCount] = userInput;
			cout << endl;
		}
			rCount++;
	}
	
	
}