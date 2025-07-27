#include <iostream>
#include <string>
#include "LengthWidthClass.h"
using namespace std;

#ifndef HEIGHTCLASS_H
#define HEIGHTCLASS_H

class HeightClass : public LengthWidthClass{

protected:
	int height;

public:

	HeightClass(int h = 2); // constructor initializer
	int getHeight();
	void setHeight(int h);
	void PrintMe_all_attr();
	~HeightClass(); //destructor

};

#endif 