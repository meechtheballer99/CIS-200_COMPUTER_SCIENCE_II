/*
////Program 2.


	*Author: Demetrius Johnson
	*Creation Date: 12 Oct 2020
	*Modification Date: 12 Oct 2020
	*Purpose: write a recursive function to calculate the the sqr root of a number using series approximation



Write a function to calculate the square root of a float number with the following interface :

	double squareRoot(double x)
{
	// assert that x is not negative
	...

}

The function should return an approximation to sqrt(x) using series approximation.
Let x0 = x / 2.  Then x¬n + 1 = (xn + x / xn) / 2.  Keep computing terms until the difference between xn and xn + 1 is less than 0.0001.
In addition, if the input variable x is negative, your function should stop the execution via the assert() function, which is a built - in C++ function.
You need to add a function call to assert() at the beginning of the above function to guarantee the precondition of this function is correct.

In your main function, design it to request the user to enter as many numbers as they want(continue to enter values ? "y" or "n").
Test cases must include values 3, 0, and -3, as well as others you think are appropriate.

The specifics of the assert message shown depends on the specific implementation in the compiler, 
but it should include : the <bool exp> whose assertion failed, the name of the source file, 
and the line number where it happened.A usual expression format is :

Assertion failed : <bool exp> file filename, line line number

#include <cassert>

void print_number(int myInt) {
	assert(myInt > 5);

	This sample snippet will abort when myInt has value of 5 or less because myInt > 5 evaluates to false.
*/

#include <iostream>


using namespace std;


int main() {














	return 0;

}