

#ifndef CREDITFILERANDW_H
#define CREDITFILERANDW_H
#include "L8functions.h"
#include <iostream>
#include <fstream>
using namespace std;


class creditFileRandW
{

public:

	ifstream creditFile_read;
	ofstream creditFile_write;

	void openCreditFile_read(void);
	void openCreditFile_write(void);
	void clearAndClose_creditFile_read(void);
	void clearAndClose_creditFile_write(void);










};

#endif // !1