// DemetriusJohnson-Lab7_CIS-200.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*


*	*Author: Demetrius Johnson
	*Creation Date: 26 Oct 2020
	*Modification Date: 26 Oct 2020
	*Purpose:  *******
 

Program 1:

You are to create a recursive function to perform a linear search through an array. -->(search every element in the array until a matching value (key) is found)

How Program Works

o	Program has array size of 5000
o	Load values into the array, equal to its index value. Index 5 has value 5, index 123 has value 123.
o	Pass array, key, and size to the recursive function:
o	int recursiveLinearSearch(int array[],int key, const int size, bool & methodStatus)
o	User enters key to search for, recursive function calls itself until the key is found (methodStatus is true), 
print out the key and number of function calls when control is returned to the main
o	Handle situation of key not found (return number of function calls AND methodStatus of false) – print not found message and number of calls in the main
o	Function returns a count of how many recursive calls were made
o	Value returned is the number of calls made to that point, that is, 
when item is found the value returned is 1 with preceding functions adding 1 to the return value until the actual number of recursive function calls are counted).
o

Determine smallest key value that causes stack-overflow to occur, even if you need to make array larger than 5000.

Test cases need to include (not limited to) biggest possible key value, “not found” message, and a stack overflow condition.






*/

#include <iostream>
#include <string>
#include "Lab7P1functions.h"
#define ARRAY_SIZE 4000

using namespace std;



int main()
{

  
	int integer_Array[ARRAY_SIZE]; //array has elements 0 to ARRAY_SIZE - 1 (ex: array size is 5000, then array contains elements 0-4,999 = 5,000 values since 0 is a value itself
	int userKey = 0; //will be used to get user-entered key to be searched for
	bool linSearchMethodStatus = false; //the state will be TRUE if the key is found and FALSE if the key is not yet found or not found at all; will determine which message is printed
	int numRecursiveCalls = 0; //will be used to output how many times the linearSearch function calls itself by catching the returned value of the linearSearch Function
	char userEntry = 'y';

	loadArrayElements(integer_Array, ARRAY_SIZE); //load array elements with corresponding values to the element value (ex: element 0 stores the value 0)
	main_Menu(ARRAY_SIZE);
	cin >> userKey;				//get user key to search for
	numRecursiveCalls = recursiveLinearSearch(integer_Array, userKey, ARRAY_SIZE, linSearchMethodStatus);
	methodStatusMessage(linSearchMethodStatus, userKey, numRecursiveCalls);

	//use the below code to search for another key
	cout << "\n\nWoud you like to search for another value in the array? type y for yes, or any other key to exit: ";
	cin >> userEntry;
	while (userEntry == 'y') {

		loadArrayElements(integer_Array, ARRAY_SIZE); //reload the array 

		cout << "Enter another userKey value (integer value) that you would like to search for in the array: ";
		cin >> userKey;

		numRecursiveCalls = recursiveLinearSearch(integer_Array, userKey, ARRAY_SIZE, linSearchMethodStatus);
		methodStatusMessage(linSearchMethodStatus, userKey, numRecursiveCalls);

		cout << "\n\nWoud you like to search for another value in the array? type y for yes, or any other key to exit: ";
		cin >> userEntry;
	}
	//use this loop to make testing search function for values in the array (and find the stack overflow point) easier

	return 0;
}





