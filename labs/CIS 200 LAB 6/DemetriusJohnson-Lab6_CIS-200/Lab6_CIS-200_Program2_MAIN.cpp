// DemetriusJohnson-Lab6_CIS-200.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

	*Author: Demetrius Johnson
	*Creation Date: 20 Oct 2020
	*Modification Date: 20 Oct 2020
	*Purpose:  *******


Program 2

Given storeMonthlySales[NUM_STORES][NUM_MONTHS][NUM_DEPTS] is a three-dimensional array of floating point values.
Write a C++ function, printMonthlySales, to calculate and print the total value of sales during a specific month by 
each department and in each store plus totals by store and department and overall sales.
The return type of the function is void and the function must have 2 input parameters: Sales array and the month the user specified (edit for correct month values!).  
The constants NUM_STORES, NUM_MONTHS, and NUM_DEPTS must be accessed globally by defining the following global variables:

#define NUM_DEPTS  2    	or const in NUM_DEPTS = 2;
#define NUM_STORES 2		or const int NUM_STORES = 2;
#define NUM_MONTHS 12	or const int NUM_MONTHS = 12;

The array Sales is initialized by the following statement within main():
float storeMonthlySales[NUM_STORES][NUM_MONTHS][NUM_DEPTS] =
{ 	 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2,
             2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2,
             3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1, 4.2,
             2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2
};

Output:                                 Sales for month of value (where value represents “January”, “March”, etc.)
                                                                 Dept #                      Dept #                           Store Total
                                               Store #         value                        value                             row value sum
                                               Store #         value                        value                             row value sum
                                               Dept Total   col value sum                       col value sum                 total overall sales

User enters a new month as many times as they wish and run printMonthlySales against the new month value.
Validate user input (“y” or “n”) when asking if the user wants to enter a new set of values.

In you test case table, please include “February” as a valid test case. You have to test with “February”.

Notes: Remember for multi-dimensional arrays that the right-most index is columns and the next-left index is rows.  
If you think of a book with 500 pages and each page is 24 rows by 80 columns then the array is declared as char book[500][24][80].



*/




#include <iostream>

using namespace std;



int main()
{	
	cout << "Hello World!\n";
}
