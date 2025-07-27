// TestingAndTimeComplexityAlgorithmAnalysis_DemetriusJohnson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void function(int n)
{
	int j_counter = 0;
	int i_counter = 0;
	cout << "\nn = " << n << endl;
	cout << "i-j\n";
	for (int i = n; i > 0; i/= 2) {
		
		for (int j = 0; j < i; j++) {
			//loop body
			cout << i << "-" << j;
			//cout << j;
			printf("  j-loop-iteration\n");
			j_counter++;
		}
		if (i == 1)
			cout << "total j-loops executed = " << j_counter << endl;
		i_counter++;
	}
	cout << "total i-loops executed = " << i_counter << endl;
	cout << "Total executions = " << i_counter + j_counter;
}


int main()
{
	
	
	function(1);
	printf("\n\n");
	function(2);
	printf("\n\n");
	function(3);
	printf("\n\n");
	function(4);
	printf("\n\n");
	function(5);
	printf("\n\n");
	function(6);
	printf("\n\n");
	function(7);
	printf("\n\n");
	function(8);
	printf("\n\n");
	function(9);
	printf("\n\n");
	function(10);


	return 0;
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
