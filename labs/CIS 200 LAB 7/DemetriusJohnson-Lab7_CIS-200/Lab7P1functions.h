
/*
* Author: Demetrius Johnson
* Creation Date : 26 Oct 2020
* Modification Date : 26 Oct 2020
* Purpose : header for program 1 (lab 7) functions
*/


#ifndef LAB7P1FUNCTIONS_H
#define LAB7P1FUNCTIONS_H
#include <iostream>
using namespace std;


void main_Menu(const int & arraySize); 
int recursiveLinearSearch(int int_Array[], int userKey, const int array_Size, bool& methodStatus); //use this LinSearch function to search linearally (sequentially) through each element of the array for user value
void loadArrayElements(int int_Array[], int size);									//use this to load array elements, with each element containing a value of its corresponding element value
void methodStatusMessage(bool& finalMethodStatus, int& userKey, int& recursiveCalls); //use this function to print a message based on whether the LinSearch function was able to find user value
#endif // 