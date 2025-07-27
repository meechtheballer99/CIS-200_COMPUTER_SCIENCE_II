/*
1st class: has one private attribute, color, which is a string, and another which is a pointer to an int. 
One constructor, with a string parameter with default value “Purple”. The constructor will create a new int and assign it to the pointer variable,
then give it value    -13. The constructor displays message “Class created with color ccc”, replacing ccc with the color variable.
Destructor, which displays message “Class destroyed with color ccc and number nnn”,
replacing ccc with the color variable and nnn with the value the pointer points to, and deleting the pointer.
Also create appropriate get and set methods for color.  You’ll have to write a copy constructor for the class as well as overloading operator=.
Have the copy constructor increase the value the new pointer points to by 1 (only the copy will increase,
not the original) and display message “Class created with color ccc and number nnn”,
replacing ccc with the color variable and nnn with the value the pointer points to.

*/

#include <iostream>
#include <string>
using namespace std;

#ifndef COLORCLASS_H
#define COLORCLASS_H

class ColorClass {

protected:
	string color;

public:

	int* intPtr;

	ColorClass& operator=(const ColorClass &OriginalObject); //define overload function for =operator since the object contains a pointer, to ensure memory locations don't overlap
	ColorClass(const ColorClass &OriginalObject); //use a copy constructor for object duplication since the object has subobjects of type pointer
	ColorClass(string userColor = "Purple"); // constructor initializer / default constructor since all object members have default intiailization values
	~ColorClass(); //destructor
	
	void setColor(string userColor);
	string getColor();

	

};

#endif 