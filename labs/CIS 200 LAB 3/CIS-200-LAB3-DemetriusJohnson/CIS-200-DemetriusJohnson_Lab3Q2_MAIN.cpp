/*
	*Author: Demetrius Johnson
	*Creation Date: 29 Sept. 2020
	*Modification Date: 7 Oct. 2020
	*Purpose: Main function for testing and using inhertiance using 3 classes
*/


#include <iostream>
#include <string>
#include "HeightClass.h"

using namespace std;

void testFunction(HeightClass HC);


int main(){

	ColorClass C1;
	ColorClass C2(C1);
	ColorClass C3("Orange");
	//ColorClass C4;
	//C4 = C3;

	LengthWidthClass LW1;
	LengthWidthClass LW2(LW1);
	//LengthWidthClass LW3 = LW2;
	LengthWidthClass LW4(9, 10);
	//cout << LW1.length << LW2.length << LW3.length << LW4.length;

	HeightClass HC1;
	//HeightClass HC2;
	HeightClass HC3(HC1);
	HeightClass HC4(232);


	HeightClass thing1;
	HeightClass thing2;

	thing1.PrintMe_all_attr();
	thing2.PrintMe_all_attr();
	LW1.PrintMe_all_attr();
	LW2.PrintMe_all_attr();
	LW4.PrintMe_all_attr();
	HC1.PrintMe_all_attr();
	HC3.PrintMe_all_attr();
	HC4.PrintMe_all_attr();

	testFunction(thing2);

	thing1.PrintMe_all_attr();
	thing2.PrintMe_all_attr();
	return 0;
}

void testFunction(HeightClass HC1) {

	HeightClass HC2 = HC1;

	HC1.PrintMe_all_attr();
	HC2.PrintMe_all_attr();
}