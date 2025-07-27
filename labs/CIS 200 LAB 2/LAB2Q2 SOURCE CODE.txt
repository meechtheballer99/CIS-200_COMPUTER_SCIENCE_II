
/*  *Author: Demetrius Johnson
	*Creation Date: 20 Sept. 2020
	*Modification Date: 23 Sept. 2020
	*Purpose: Learn how pointer and arrays work and how to take advantage of offsetting them

	Question 2:

	Create an array of 100 integers, randomly generated to be in the range of -50 to +72.  
	1.	Using standard array notation, print all values in the array on one line, separated by a space
	2.	Using array offset notation, print all values in the arrayfrom last index to first, on one line, each separated by a space
	3.	Using pointer notation, print all negative values on one line, separated by a space
	4.	Using pointer offset notation, print all positive values on one line, separated by a space

	Reminder:
	array notation		myArray[ x ];
	array offset notation	*(myArray + x);
	pointer notation	* integerArrayPtr;
	pointer offset notation	*(integerArrayPtr + x);

	
*/


#include <iostream>
#include <ctime>		 //need this library to use inside of srand function to generate random numbers based on the time..a better way to get random numbers
#include <cstdlib>		//need this library for random number function

using namespace std;

int main()
{
	srand(time(NULL)); //set seed based on time so the algorithm for the psuedorandom numbers never calculates same values based on same seed upon program execution

	int arrayOneHunRanNum[100];
	int randomNum = 0;
	int integerCounter;
	int* integerArrayPtr = arrayOneHunRanNum;
	

	cout << "Print array using standard array subscript notation 'myArray[]': \n\n";

	for (integerCounter = 0; integerCounter < 100; integerCounter++) {
		

		randomNum = (rand() - (RAND_MAX / 2)); //get a random positive or negative number
		while (randomNum < -50 || randomNum > 72) { //use this loop to ensure that the random number is between -50 and 72.
			randomNum = (rand() - (RAND_MAX / 2));

		}


		arrayOneHunRanNum[integerCounter] = randomNum; //input random number into the array at the current element.

		cout << arrayOneHunRanNum[integerCounter] << " ";
	}

	cout << endl << endl << endl << "Print array using array offset notation *(my Array + x): \n\n"; //use offset notation to print array
	for (integerCounter = 0; integerCounter < 100; integerCounter++) {

		cout << *(arrayOneHunRanNum + integerCounter) << " ";

	}

	cout << endl << endl << endl << "Print all NEGATIVE values in the array using pointer notation *integerArrayPtr: \n\n";

	for (integerCounter = 0; integerCounter < 100; integerCounter++) { //0 is neither positive or negative so it is excluded for the next two cout's.

		if(*(integerArrayPtr = &arrayOneHunRanNum[integerCounter]) < 0) //use this so that the following line of code only execeutives if the element in the array is a negative value
		cout << *(integerArrayPtr = &arrayOneHunRanNum[integerCounter]) << " "; //in this line, we set pointer equal to address location of each element in the array, then dereference it to get and print its value

	}
	integerArrayPtr = arrayOneHunRanNum; //reinitialize poiinter to point to first memory location segment at element 0 of the array.

	cout << endl << endl << endl << "Print all POSITIVE values in the array using pointer offset notation *(integerArrayPtr + x): \n\n";

	for (integerCounter = 0; integerCounter < 100; integerCounter++) {

		if (*(integerArrayPtr + integerCounter) > 0) //use this so that the following line of code only execeutives if the element in the array is a positive value
			cout << *(integerArrayPtr + integerCounter) << " "; //in this line, we increment the address of the pointer which automatically increments to the next element of the array to which it points

	}
	
	cout << endl << endl << endl << "The Program has finished. Thank you(: \n\n\n";




	return 0;

}

