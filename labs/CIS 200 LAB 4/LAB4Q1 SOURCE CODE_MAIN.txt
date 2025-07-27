//

/*

/*
	*Author: Demetrius Johnson
	*Creation Date: 12 Oct 2020
	*Modification Date: 12 Oct 2020
	*Purpose: override Vector function and practice writing a copy constructor using deep copy

*/

//Write methods defined in header fileand use the following “stub” Main to test header file

#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{

	// REQUIRED CODE

	Vector a, b(3), c(3);

	a.print(); 	// outputs []
	b.print(); 	// outputs [ 0 0 0 ]
	c.set(0, -1);        // output error message
	c.set(1, 0);
	c.set(2, 1);
	c.set(3, 2);
	c.set(4, 3);          // outputs error message 
	c.print(); 	// outputs [ 1 2 3 ]

	Vector d(c);
	d.print(); 	 // outputs [ 1 2 3 ]

	d.set(0, 1);
	d.print();	// outputs [ 1 0 3 ]
	c.print(); 	// outputs [ 1 2 3 ]   proves deep copy  

	// ADDITIONAL TEST CASES

	//[Insert your code for YOUR test cases here (below)]

	Vector e(a), f(d), g(5);
	Vector test; 

	test = g; //test overloaded operator=
	test.print(); //should output contents of g
	e.print(); //should output [] since a is empty and e was initialized using a.
	f.print(); //should print same output as d: [ 1 0 3 ]
	g.print(); //should output [ 0 0 0 0 0 ]
	return 0;
}
