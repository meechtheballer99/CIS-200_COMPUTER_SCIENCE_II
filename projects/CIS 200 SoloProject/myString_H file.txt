
/*
* Author: Demetrius Johnson  --CIS200 UM-DEARBORN --PROF ROBERTMANN
* Creation Date : 26 Oct 2020
* Modification Date : 31 Oct 2020
* Purpose : ***
*/

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <string>
#include <cstdlib>
#define nullchar '\0' //define nullchar character so I can more easily implement the null char character in my code

using namespace std;

class myString
{

private:

	char* dynamicArrayOfChar = new char[1];
	int myStringSize = 0;


public:

	//-------------RULE OF 3-----------------COPY CONSTRUCTOR, DESTRUCTOR, COPY ASSG OPERATOR------------------------//
	~myString(); //destructor
	myString(const myString& myStringCopiedObject); //copy constructor
	myString(const string stdstring); // – you may have a constructor that takes a string parameter
	myString();//default constructor
	myString& operator=(const myString& myStringCopiedObject); //overload =operator for myString parameter
	myString& operator=(const string& stdstring); //overload =operator for string parameter
	myString operator+(const myString& myStringCopiedObject); //overload operator+ ---> has the same functionality as addEnd function //I did this as a bonus as I realized it served same purpose as addEnd

	void resetTo_DefualtConstructor(void); //use this function to reset a string to the default constructor intialization parameters --> size = 0, and charArray only has 1 element = nullchar
	void allocMemAndSetNewSize(const unsigned int newSize); //use this function to easily allocate memory of a new size to a myString object //this function will be used often (as well as resetTo_DefaultConstructor function) in many other functions
	void setElementsEqual(const myString& myStringCopiedObject); //use this function to set elements equal only when the object passed in has a size <= the object calling the function; any remaining elements will remain the same
	void setElementsEqual(const string& stdstring); //overload setElementsEqual function to accept string parameters (polymorphism)

	int sizeOfString(void); //– returns how many characters are in the string(empty string is size zero)
	void addStart(const myString& myStringCopiedObject); // – adds the string in the input parameter to the front of current string
	void addEnd(const myString& myStringCopiedObject); //– adds the string in the input parameter to the end of the current string
	myString partMyString(const unsigned int startPos, const unsigned int length); //– returns as myString that portion from startPos for length given.Handle startPos < 0 & > size; startPos > size returns null string --startPos is INCLUDED in the length
	void replPartString(const myString& myStringCopiedObject, const unsigned int startPos); //– replaces characters starting at startPos with parameter, which may be <, >, or = in size to what is replaced //too large input/negative int will auto add user string to the end of calling object
	void replWholeString(const myString& myStringCopiedObject); //– replaces current string data value with parameter myString
	void replWholeString(const string& stdStringCopiedObject); //– replaces current string data value with parameter string

	
	int compareMyString(const myString& comparedObject); //– compare current value of string with parameter string.Returns 0 if strings match, otherwise return character position(NOT index) where mismatch occurs.If parameter is first alphabetically then return is positive, otherwise negative.

	void initString(void); // – resets / initializes string to null string
	void setString(const myString& userInputmyString); // – assign to myString the parameter myString
	void setString(const string& userInputString); // – assign to myString the parameter string
	char* getString(); //– returns string of data from myString //returning a char* is the same thing as returning a string literal
	void printMyString_Screen(void); //– prints myString data value to the monitor(value only, nothing else)
	bool is_numericString(void); //– returns Boolean telling if data value is an integer or real(signs, decimal point.etc...returns true), or not (if there are any non-numbers/decimals/negative symbol: boolean returns false)
	bool is_alphabeticString(void); //– returns Boolean telling if data value is all alphabetic characters
	
};


/*


You are to create your own version of a string class named myString.

myString will store a string of characters (use dynamic memory – ptr to char)

Include a reference “status variable” to indicate error state.

You will also need to supply the following methods as part of your class:



 ****You may use the C++ string class only for user input and the setString  & getString methods.
 Only size from the string library may be used, and only within setString method.******

Write a main that will test all of functionalities of the myString class, displaying the actions both on the screen and to an output file. Main must use a myString method to write the results to the file.

Create an output file log of actions, which must show action, original value of myString, parameters/results, success/error message. You determine appearance of log file – format into columns for readability  -- and what the error messages will be.



*/









#endif //



