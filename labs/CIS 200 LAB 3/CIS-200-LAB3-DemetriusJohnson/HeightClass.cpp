/*
	*Author: Demetrius Johnson
	*Creation Date: 29 Sept. 2020
	*Modification Date: 7 Oct. 2020
	*Purpose: level 3 class to use for inheritance
*/


/*


3rd class: 

inherits public from 2nd class. It has private int attribute of height. 
One constructor, with an int parameter with default value of 2.  
The constructor displays message “Class created with color ccc, 
length lll, width www, and height hhh”, replacing ccc, lll, www, 
and hhh with the appropriate variable values. Destructor, 
which displays message “Class destroyed with color ccc, length lll, 
width www, and height hhh”, replacing ccc, lll, www, and hhh with the appropriate variable values. 
Create appropriate get and set methods for the attribute. 
Create a PrintMe method that prints “ccc object with lll x www x hhh (volume = vvv)” replacing ccc, lll, www, 
and hhh with the appropriate variable values and vvv with length multiplied by width multiplied by height.

*/

#include <iostream>
#include <string>
#include "HeightClass.h"
using namespace std;


HeightClass::HeightClass(int h) {

	height = h;
	cout << "--HeightClass created with color <" << color << ">, length <" << length << "> width <" << width << ">, and height <" << height << ">.\n\n";
	
} // constructor initializer

int HeightClass::getHeight() { return height; }

void HeightClass::setHeight(int h) { height = h; }

void HeightClass::PrintMe_all_attr() {

	cout << color << " object with length = " << length << ", width = " << width << " and height " << height 
		 << " has volume of " << length << "x" << width << "x" << height << " = " << length*width*height << ".\n\n";

}

HeightClass::~HeightClass() {

	cout << "~HeightClass destroyed with color " << color << ", length " << length << ", width " << width << ", and height " << height << ".\n\n";

}//destructor


