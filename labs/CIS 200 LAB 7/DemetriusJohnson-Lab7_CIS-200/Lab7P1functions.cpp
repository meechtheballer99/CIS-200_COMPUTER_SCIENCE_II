/*
* Author: Demetrius Johnson
* Creation Date : 26 Oct 2020
* Modification Date : 26 Oct 2020
* Purpose : .cpp file for program 1 (lab 7) functions
*/

#include "Lab7P1functions.h"



void main_Menu(const int & arraySize) {

	cout << "---------------------------------------------WELCOME-------------------------------------------\n";
	cout << "This Program will perform a linear search through an array of size " << arraySize<< " for a given key (integer) provided by the user.\n";
	cout << "\nEnter an integer value to see if your key value is contained in one of the elements of the array: ";
	
}



int recursiveLinearSearch(int int_Array[], int userKey, const int array_Size, bool& methodStatus) {

	int elementCounter = 0;

	if (int_Array[elementCounter] == userKey) { //Best Case scenario; check to see if first element contains userKey

		methodStatus = true;

		return(0); //number of recursive calls is 0 since only MAIN called this first function and the key was found in the first element of the array
	}

	while (int_Array[elementCounter] == NULL) {// set counter to next element position to be compared to userKey
		elementCounter++;
	}

	if (elementCounter < array_Size && int_Array[elementCounter] == userKey) { //Base Case; check to see if element contains userKey; first statement in the if statement is to make sure we do not go out of scope of the array size

		methodStatus = true;

		return(0); //return 0; so all returns will be +1, and here when/if we reach base case we get +0 ...so: (0+1) <--(base case) +1 +1 +1 +1..etc...+1<---(first recursive call)
	}//base case returns 0...next case returns 0+1...next case returns 1+1...next case returns 2+1.....next case --> 3+1 --> 4+1....etc...until you reach original MAIN call

	if (elementCounter < array_Size && int_Array[elementCounter] != userKey) { //; first statement in the if statement is to make sure we do not go out of scope of the array size

		methodStatus = false;
		int_Array[elementCounter] = NULL; //change the array value to NULL so that the next recursive function call will skip this element and search the next element

		return(recursiveLinearSearch(int_Array, userKey, array_Size, methodStatus) + 1); //when method status is false and userKey not found, add one to the return value to increment recursive calls
	}
	

	return 0; //if userKey is not found after searching all elements/and serves as protection return just in case the above if-statements fail to return an integer

}


void loadArrayElements(int int_Array[], const int arraySize) {

	int elementVal;

	for (elementVal = 0; elementVal < arraySize; elementVal++) {

		int_Array[elementVal] = elementVal;

	}

}

void methodStatusMessage(bool& finalMethodStatus, int& userKey, int& recursiveCalls) {

	if (finalMethodStatus == true) {

		cout << "\nThe linear search WAS ABLE to find your key '" << userKey <<  "' in the array.\n";
		cout << "The number of recursive calls to the linearSearch funtion until your key was found is: " << recursiveCalls;
		cout << "\nYour key was found at element " << recursiveCalls + 1; //+1 because number of recursive calls will always be 1 less than the element position where it was found since the first function call is not recursive and is called/first element searched from the MAIN call


	}

	else //method status is false
	{
		cout << "The linear search WAS UNABLE to find the user key '" << userKey << "'; userKey not found.\n";
		cout << "The number of recursive linearSearch function calls before returning to MAIN is: " << recursiveCalls;



	}

}

/* //TEST FUNCTION //ENDED UP NOT USING IT WHEN I FIGURED OUT WHAT I SHOULD DO TO BE MORE EFFICIENT AND KEEP THE PARAMETERS THAT THE ASSIGNMENT REQUIRED
int linearRecusriveFunction(int int_Array[], const int& array_Size, int & recursiveIncrementer, int &userKey, bool & methodStatus){

	if (int_Array[recursiveIncrementer] != userKey) {

		methodStatus = false;
		recursiveIncrementer++;
		return (1);

	}
	else {

		methodStatus = true;
		recursiveIncrementer++;
		return (1);


	}


}
*/