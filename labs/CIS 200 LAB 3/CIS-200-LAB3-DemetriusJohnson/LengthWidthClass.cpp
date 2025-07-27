
/*
	*Author: Demetrius Johnson
	*Creation Date: 29 Sept. 2020
	*Modification Date: 7 Oct. 2020
	*Purpose: level 3 class to use for inheritance
*/

/*

2nd class: 
inherits public from 1st class.  
It has private attributes of length and width, both int. One constructor, with int parameters with default values of 3 and 5. 
The constructor displays message “Class created with color ccc, length lll, and width www”, replacing ccc, lll, 
and www with the appropriate variable values. Destructor, which displays message “Class destroyed with color ccc, length lll, and width www”, 
replacing ccc, lll, and www with the appropriate variable values.  
Create appropriate get and set methods for the two attributes. 
Create a PrintMe method that prints “ccc object with lll x www (area = aaa)” replacing ccc, lll, 
and www with the appropriate variable values and aaa with length multiplied by width.

*/

#include <iostream>
#include <string>
#include "ColorClass.h"
#include "LengthWidthClass.h"
using namespace std;


LengthWidthClass::LengthWidthClass(int l, int w) {

	length = l;
	width = w;

	cout << "--LengthWidthClass created with color <" << color << ">, length <" << length << "> and width <" << width << ">.\n\n";


}// constructor initializer and useable as a default constructor

LengthWidthClass::LengthWidthClass(const LengthWidthClass& OriginalObject) : ColorClass(OriginalObject) { //copy constructor specifying that the base-class constructor to be called should be the base-class copy constructor as well

	length = OriginalObject.length;
	width = OriginalObject.width;

	cout << "--LengthWidthClass created with color <" << color << ">, length <" << length << "> and width <" << width << ">.\n\n";
}

void LengthWidthClass::setLength(int l) {
	length = l;
}

void LengthWidthClass::setWidth(int w) {
	width = w;
}

int LengthWidthClass::getLength() { return length; }

int LengthWidthClass::getWidth() { return width; }

void LengthWidthClass::PrintMe_all_attr() {

	cout << color << " object with length = " << length << " and width = " << width << " has area of " << length << "x" << width << " = " << length * width << ".\n\n";
}

LengthWidthClass::~LengthWidthClass() {

	cout << "~LengthWidthClass destroyed with color " << color << ", length " << length << ", and width " << width << ".\n\n";

} //destructor
	
