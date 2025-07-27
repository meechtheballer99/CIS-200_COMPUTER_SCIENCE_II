


#ifndef P1FUNCTIONS_H //if the .o (object file) of the .cpp file linked to this header file is not created/defined
#define P1FUNCTIONS_H //then define it
#include <iostream>
#include <iomanip> //use this to help with alignment of output table
#include <stdexcept> //use for exception handling
#define ROWS 3
#define COLUMNS 2

using namespace std;


int numPosAndEven_InArray(int arrayIntValues[ROWS][COLUMNS]);				//find the total number of even elements in a 2D array
void printArray(int arrayIntValues[ROWS][COLUMNS]);	//print array with neat and appropriate formatting
void openingMenu(void);
void userInput2D_array(int arrayIntValues[ROWS][COLUMNS]); //change the array based on user input


#endif			// end of all definition of symbols (classes, variables, etc) in the .h and linked .cpp file