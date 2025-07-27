#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class student {

private:
	string major;
	int creditHrsCompleted;

public:

	student(string userInputMajor = "General Studies" , int userInputCredits = -1); // constructor initializer
	~student();
	void setMajorAndHrs(string, int); //setter function NOT INLINE per instructions

	void getMajorAndHrsByRef(string& majorstring, int& creditHrs); //use this by reference getter function to write to a file

	string getMajor() const {return major;} //INLINE per instructions------getter functions

	int studentgetHRS() const {return creditHrsCompleted;} //INLINE per instructions ^^^^^^^^^^^

	string PrintMe_MajorAndHrs(); //made it return a string per instructions 
	
};

#endif 