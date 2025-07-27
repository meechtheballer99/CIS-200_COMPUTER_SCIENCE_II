

#include "student.h"




//constructor initializer list
student::student(string userInputMajor, int userInputCredits):major(userInputMajor), creditHrsCompleted(userInputCredits) { 

	cout << "\n\t***Constructor called for major '" << major << "' and hours " << creditHrsCompleted << ".***\n"; //this will show in the program how subobjects are created when the constructor is called

}

student::~student() {
	cout << "\n***destrcutor has been called, object and all subobjects destroyed; memory reallocated successfully.***\n";
	system ("pause"); //put in a system pause so that we can see destructor message easily
}


void student::setMajorAndHrs(string userInputMajor, int userInputHrs) { //defined NOT INLINE per instructions
	
	major = userInputMajor;
	creditHrsCompleted = userInputHrs;
}

void student::getMajorAndHrsByRef(string& majorstring, int& creditHrs) { //use this by reference getter function to write to a file
	
	majorstring = major;
	creditHrs = creditHrsCompleted;
}

string student::PrintMe_MajorAndHrs() {
	stringstream ss; //will use streamstring to turn creditHrs integer into a string so that I can use addition of strings operands.
	string creditHrsString;

	ss << creditHrsCompleted;
	ss >> creditHrsString;

	string PRINTstring = "\nI'm a " + major +" and have completed " + creditHrsString + " credit hours.\n";
	return PRINTstring;
}

