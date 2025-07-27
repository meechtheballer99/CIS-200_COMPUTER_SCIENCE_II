
/*
* Author: Demetrius Johnson  --CIS200 UM-DEARBORN --PROF ROBERTMANN
* Creation Date : 26 Oct 2020
* Modification Date : 31 Oct 2020
* Purpose : ***
*/



#include "myString.h"


//-------------RULE OF 3-----------------COPY CONSTRUCTOR, DESTRUCTOR, COPY ASSG OPERATOR-------THE BIG 3-----------------//

myString::~myString(){

	delete[] dynamicArrayOfChar;
	cout << "\n\t\t~myString destructor has been called...array char[] deleted....destroying object~\n";

}//destructor
myString::myString(const myString& myStringCopiedObject){
	if (myStringCopiedObject.myStringSize == 0) { //check to make sure that any object initialized with another object with an empty char array will simply cause function to act as defualt constructor
		this->dynamicArrayOfChar[this->myStringSize] = nullchar;
		return;
	}
	else { //else make the object have all the same members --> same size of char array with all the same elements
		this->allocMemAndSetNewSize(myStringCopiedObject.myStringSize); // use allocFunction to set new size and to allocate new memory of the new size
		this->setElementsEqual(myStringCopiedObject);
	}
} //copy constructor
myString::myString(const string stdstring) {

	if (stdstring.size() == 0) { //if string is empty string, then just need to keep size to 0 and set the default (new char[1]) "0" element to nullchar
		this->dynamicArrayOfChar[this->myStringSize] = nullchar;
		return;
	}

	else {
		this->allocMemAndSetNewSize(stdstring.size());//set new size and allocate memory of the new size
		this->setElementsEqual(stdstring);
	}
	return;
} // – you may have a constructor that takes a string parameter
myString::myString() {

	this->dynamicArrayOfChar[this->myStringSize] = nullchar;

}//default constructor
myString& myString::operator=(const myString& myStringCopiedObject) {
	if (myStringCopiedObject.myStringSize == 0) { //check to make sure that any object initialized with another object with an empty char array will simply cause function to act as defualt constructor
		this->resetTo_DefualtConstructor();
		return *this;
	}
	else { //else make the object have all the same members --> same size of char array with all the same elements
		this->allocMemAndSetNewSize(myStringCopiedObject.myStringSize); // use allocFunction to set new size and to allocate new memory of the new size
		this->setElementsEqual(myStringCopiedObject);
	}

	return *this;
} //overload operator= for myString parameter
myString& myString::operator=(const string& stdstring) {
	if (stdstring.size() == 0) { //if string is empty string, then just need to keep size to 0 and set the "0" element (really element 1) to nullchar
		this->resetTo_DefualtConstructor();
		return *this;
	}

	else {
		this->allocMemAndSetNewSize(stdstring.size()); //set new size and allocate memory of the new size
		this->setElementsEqual(stdstring);
	}
	return *this;
} //overload =operator for string parameter
myString myString::operator+(const myString& myStringCopiedObject) {
	myString myStringReturnObject = *this; //copy the calling object so that we will not affect it
	myStringReturnObject.addEnd(myStringCopiedObject); //take the copy of the calling object and add the passed object elements on the end
	return myStringReturnObject; //return the modified copied version of the calling object
}//overload operator+ ---> has the same functionality as addEnd function
void myString::resetTo_DefualtConstructor(void) {

	this->myStringSize = 0;
	delete[] this->dynamicArrayOfChar;
	this->dynamicArrayOfChar = new char[1];
	this->dynamicArrayOfChar[this->myStringSize] = nullchar;

}//use this function to reset a string to the default constructor intialization parameters --> size = 0, and charArray only has 1 element = nullchar
void myString::allocMemAndSetNewSize(const unsigned int newSize) {
	if (newSize > 1024) {//use this as protection to ensure a string that is too large is not created
		this->resetTo_DefualtConstructor();
		return;
	}
	this->myStringSize = newSize; //automatically set the size member value to the size of the new memory that will be allocated for this object
	delete[] this->dynamicArrayOfChar;//delete previous allocated memory so we can reallocate new memory of the appropriate size
	this->dynamicArrayOfChar = new char[this->myStringSize + 1]; //+1 so that we can input nullchar at end of char array
	this->initString(); //use this loop to initialize all elements to nullchar
	this->dynamicArrayOfChar[this->myStringSize] = nullchar; //set last element to nullchar to determine end of the charArray/string after the last useable element
	return;

}//use this function to easily allocate memory of a new size to a myString object
void myString::setElementsEqual(const myString& myStringCopiedObject){

	for (int count = 0; count < myStringCopiedObject.myStringSize; count++) { //use for loop in order to copy all array elements 
																			  //use copied object size in loop so we can still use function even when copied object 
																			  //has smaller size than size of object calling the function

		this->dynamicArrayOfChar[count] = myStringCopiedObject.dynamicArrayOfChar[count];
	}
}//use this function to set elements equal only when the object passed in has a size <= the object calling the function; any remaining elements will remain the same
void myString::setElementsEqual(const string& stdstring) {

	for (int count = 0; count < this->myStringSize; count++) { //use for loop in order to copy all array elements

		this->dynamicArrayOfChar[count] = stdstring.at(count);
	}
}//overload setElementsEqual function to accept string parameters (polymorphism)

int myString::sizeOfString(void){
	return this->myStringSize;
} //– returns how many characters are in the string(empty string is size zero)
void myString::addStart(const myString& myStringCopiedObject){
	int newCharArraySize = this->myStringSize + myStringCopiedObject.myStringSize; //get length of calling object added to the passed object
	int zeroCounter = 0; //use this counter to start iteration at the 0 element of an array

	if (newCharArraySize == this->myStringSize) { //if newCharArraySize stay same length then passed object's size == 0, then just exit function; 
												  //the myString object which called the function will be untouched
		return;
	}
	else {
		myString myStringHolder = *this; //hold original values of the calling object
		this->allocMemAndSetNewSize(newCharArraySize);//set new length of this-> object and allocate new memory
		this->setElementsEqual(myStringCopiedObject); //use this function to add copied object charArray elements at the front of this-> object's charArray
		for (int remCount = myStringCopiedObject.myStringSize; remCount < this->myStringSize; remCount++) { //use this loop to add remainder of original object's elements 
																											//start at the index size = size of copied object
			this->dynamicArrayOfChar[remCount] = myStringHolder.dynamicArrayOfChar[zeroCounter]; 
			zeroCounter++;												
		}
		return;
	}

} // – adds the string in the input parameter to the front of current string
void myString::addEnd(const myString& myStringCopiedObject){
	int newCharArraySize = this->myStringSize + myStringCopiedObject.myStringSize; //get length of calling object added to the passed object
	int zeroCounter = 0; //use this counter to start iteration at the 0 element of an array
	
	if (newCharArraySize == this->myStringSize) { //if newCharArraySize stay same length then passed object's size == 0, then just exit function; 
												  //the myString object which called the function will be untouched
		return;
	}
	else {
		myString myStringHolder = *this; //hold original values of the calling object
		this->allocMemAndSetNewSize(newCharArraySize);//set new length of this-> object and allocate new memory
		this->setElementsEqual(myStringHolder); //use this function to add original-object charArray elements at the front of this-> object's charArray
		for (int remCount = myStringHolder.myStringSize; remCount < this->myStringSize; remCount++) { //use this loop to add remainder of copied object's elements to end of this->object's element 
																											//start at the index size = size of original object
			this->dynamicArrayOfChar[remCount] = myStringCopiedObject.dynamicArrayOfChar[zeroCounter]; //use zero counter to start at element 0 of copied obj to add its elements at the end of this->object
			zeroCounter++;
		}
		return;
	}
	 

} //– adds the string in the input parameter to the end of the current string
myString myString::partMyString(const unsigned int startPos, const unsigned int length){ //use unsigned int so that if a negative value is input,
																						 //it will be converted into a very large number and caught by one of the if statements
	if (startPos < 0 || startPos > this->myStringSize) { //if startPos is an invalid number (-# or too large), return a null myString since there is nothing after startPos to part
		cout << "**partMyString returned a null string -->check your inputs; elements start at 0 and end at length-1**\n";
		myString myString_null;
		return myString_null;
	}
	if (length > (this->myStringSize - startPos) || length == 0) { //length cannot be > myStringSize - startposition; this is because we start parting string AT startPos and end before total length of string in the loop below
												//(myStringSize - startPos) = LargestLengthPossible
												//remember***elements start at element 0; for EX: size of 6 has elements 0-5 --> element '6' will be out of range
												//if length == 0 then user is asking to part a 0 length and thus will return an empty string
		cout << "**partMyString returned a null string -->check your inputs; elements stat at 0 and end at length-1**\n";
		myString myString_null;
		return myString_null;
	}

	myString partOfmyString;
	int zeroCounter = 0; //use this zero counter to set element values of new partString that correspond to element segment of the original object
	partOfmyString.allocMemAndSetNewSize(length); //set size and allocate memory for the length given
	for (int count = startPos; count < (startPos + length); count++) { //use for loop in order to copy all array elements, starting at given startPos; note that startPos is included in the length
																	 										   
		partOfmyString.dynamicArrayOfChar[zeroCounter] = this->dynamicArrayOfChar[count];
		zeroCounter++;
	}

	return partOfmyString;
} //– returns as myString that portion from startPos for length given.Handle startPos < 0 & > size; startPos > size returns null string --startPos is INCLUDED in the length
void myString::replPartString(const myString& myStringCopiedObject , const unsigned int startPos) {//if a number too large is input (or a a negative which will convert to a large positive																						   
																								   //then this function will automatically add the passed object's string to the end of the calling object's string
	myString myStringHolder;
	unsigned int startPosCounter = startPos; //use unsigned into to ensure any negatives will omit and become a large postive value
	if (startPos >= this->myStringSize) {
		startPosCounter = this->myStringSize - 1; //change the counter position so that when it iterates it will default to end of the string
	}//this clause will ensure if user inputs a negative value or an invalid start position, then the start position will defualt to adding user passed string on the end of calling object

	int determineNewSize = this->myStringSize - startPosCounter; //first we use this int variable to get the size remaining of the original string if you start at a given position
	if (determineNewSize >= myStringCopiedObject.myStringSize) { //if remaining size is >= the string to input into the original string from the start position, then no new size needed for the original object
		myStringHolder = *this; //setMyStringHolder to the calling object to be manipulated; no size change needed in this case to input the user segment string from myStringCallingObject
	}
	else { //if the segment size string is larger than what remains after start Pos of the original string, 
		   //then simply add startPos to the segment size string that will be input to get a sufficient size and assign it to the object's new size
		determineNewSize = startPosCounter + myStringCopiedObject.myStringSize;
		myStringHolder.allocMemAndSetNewSize(determineNewSize); //set new size
		myStringHolder.setElementsEqual(*this); //set elements equal to calling object while retaining the new size needed to input the user string segment from myStringCopiedObject
	}
	

	for (int zeroCounter = 0; zeroCounter < myStringCopiedObject.myStringSize; zeroCounter++) {

		myStringHolder.dynamicArrayOfChar[startPosCounter] = myStringCopiedObject.dynamicArrayOfChar[zeroCounter];
		startPosCounter++;
	}

	*this = myStringHolder; //finally, change this-> object's to the new replaced/partially replaced string

} //– replaces characters starting at startPos with parameter, which may be <, >, or = in size to what is replaced
void myString::replWholeString(const myString& myStringCopiedObject){

	*this = myStringCopiedObject;

} //– replaces current string data value with parameter string
void myString::replWholeString(const string& stdStringCopiedObject) {

	*this = stdStringCopiedObject;

} //– replaces current string data value with parameter string


int myString::compareMyString(const myString& comparedObject){

	int elementPosReturn = 0;
	for (int count = 0; count <= this->myStringSize; count++) { //set count to iterate up to <= because at the end of my charArray there is a null character to denote the end.
																//This actually helped make this code much easier, as there is another element (set to nullchar) that's 1 greater than the sizeParameter of myString
																//So when it hits nullchar and the other myString is not nullchar, then even if up to that point they were
																//equal strings, the function still works correctly to indicate that either +/- (parameter is less or more alphabetically )
																//that the next char posititon for one of the strings (not index, ie. element 0 == position 1) still contains a non-null character.
																//nullchar is the smallest character, so if you hit null first on the parameter object then return will be positive; 
																//negative if null is hit first on calling object. And obviously if both strings are equal then they will hit nullchar at the same position so return will be 0

		if (this->dynamicArrayOfChar[count] != comparedObject.dynamicArrayOfChar[count]) {
			
			if (comparedObject.dynamicArrayOfChar[count] > this->dynamicArrayOfChar[count]) {

				return (elementPosReturn + 1); //return a positive number if the compared objects value is first alphabetically

			}
			else {
				return ((elementPosReturn + 1) * -1); //otherwise current object is first alphabetically so retun a negative value
			}

		}
		else {
			elementPosReturn++;
		}
	}
	
	return 0; //if we make it here, then that means the strings match and thus we must return a 0.

	//– compare current value of string with parameter string. Returns 0 if strings match, otherwise return character position(NOT index) where mismatch occurs.
//If parameter is first alphabetically then return is positive, otherwise negative.
} 
void myString::initString(void){

	for (int count = 0; count < this->myStringSize; count++) {//use this loop to initialize all elements to nullchar
		this->dynamicArrayOfChar[count] = nullchar;
	}

} // – resets / initializes string to null string
void myString::setString(const myString& userInputmyString){

	*this = userInputmyString;

	// – assign to myString the parameter string; Only size from the string library may be used, and only within setString method.
//You may use the C++ string class only for user input and the setString  & getString methods. 
} 
void myString::setString(const string& userInputString) {

	*this = userInputString;

	// – assign to myString the parameter string; Only size from the string library may be used, and only within setString method.
//You may use the C++ string class only for user input and the setString  & getString methods. 
} 
char* myString::getString(){//returning a char* is the same thing as returning a string literal since a string literal is a char array (and char arrays are a contiguous segment of pointers to type char)

	return this->dynamicArrayOfChar;

} //– returns string of data from myString
void myString::printMyString_Screen(void){

	cout << this->dynamicArrayOfChar;

} //– prints myString data value to the monitor(value only, nothing else)
bool myString::is_numericString(void){

	for (int count = 0; count < this->myStringSize && this->dynamicArrayOfChar[count] != nullchar; count++) { //use for loop to check all elements until a letter is found
																			 
		if (isalpha(this->dynamicArrayOfChar[count])) { //if any element is a non number/decimal/negative symbol, then boolean will return false
			return false;
		}
	}

	return true; //returns true only if there are no alphabetic characters in the string
} //– returns Boolean telling if data value is an integer or real(signs, decimal point.etc...returns true), or not (if there are any non-numbers/decimals/negative symbol: boolean returns false)
bool myString::is_alphabeticString(void){

	for (int count = 0; count < this->myStringSize && this->dynamicArrayOfChar[count] != nullchar; count++) { //use for loop to check all elements until a letter is found

		if (!isalpha(this->dynamicArrayOfChar[count])) { //if any element is a number/decimal/negative symbol, then boolean will return false
			return false;
		}
	}

	return true; //returns true only if all elements are alphabetic

} //– returns Boolean telling if data value is all alphabetic characters



