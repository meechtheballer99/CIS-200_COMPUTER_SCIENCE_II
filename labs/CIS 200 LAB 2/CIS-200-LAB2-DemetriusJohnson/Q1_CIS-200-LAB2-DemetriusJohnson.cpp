
/*  *Author: Demetrius Johnson
	*Creation Date: 20 Sept. 2020
	*Modification Date: 22 Sept. 2020
	*Purpose: *****

	Question 1:

	Use the following code snippet as the basis for a program to test all possible combinations of pointer manipulation.
	Each of the 10 combinations must be tested separately since the pointer may move and array values may be changed:

	int X[] = { 3, 7, 11, 17, 23 };
	int * xPtr = & X[2];
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;

	cout << "Array content prior to pointer manipulation\n";
	// replace AAA in the following statement with selection from list of 10 pointer actions below, one at a time
	cout << AAA << endl;
	cout << endl << "Array content after ptr manipulation" << endl;
	cout << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << xPtr << " : " << *xPtr << endl;


	Generate a concise summary report explaining the result of each of these pointer actions when inserted in place of AAA above.
	The report must identify if any array values were changed and, if the pointer moved, where and when it moved.

	*xPtr++
	(*xPtr)++
	*(xPtr)++
	*(xPtr++)
	*(++xPtr)
	*++xPtr
	(*++)xPtr
	++*xPtr
	++ (*xPtr)
	(++*)xPtr
	
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{

	//Use the following code snippet as the basis for a program to test all possible combinations of pointer manipulation.
		//Each of the 10 combinations must be tested separately since the pointer may move and array values may be changed :

	int X[] = { 3, 7, 11, 17, 23 };
	int* xPtr = &X[2];

	cout << "There exists the array int X[] = { 3, 7, 11, 17, 23 }; and a pointer int* xPtr = &X[2]\n";
	cout << "\nThe address location of X[2] is " << &X[2] << " and that location is storing the value " << X[2] << endl << endl;
	cout << "Here is the array content prior to pointer 'xPtr' manipulation:\n";
	cout << X[0] << ' ' << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << X[4] << "...xPtr is storing address: " << xPtr << " which is an integer of value: " << *xPtr << endl;
	// replace AAA in the following statement with selection from list of 10 pointer actions below, one at a time
	cout << "\nNow below there will be a manipulation on pointer xPtr...\n";
	cout << "Pointer Manipulation: ++(*xPtr) -->  " << (xPtr)++ << endl;
	cout << endl << "Finally, here is the array content after xPtr manipulation:" << endl;
	cout << X[0] << ' ' << X[1] << ' ' << X[2] << ' ' << X[3] << ' ' << X[4] << "...xPtr is storing address: " << xPtr << " which is an integer of value: " << *xPtr << endl;
	cout << "\nThe address location of X[2] is " << &X[2] << " and that location is storing the value " << X[2] << endl << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
