
/*  *Author: Demetrius Johnson
	*Creation Date: 20 Sept. 2020
	*Modification Date: 20 Sept. 2020
	*Purpose: *****

	Question 3:

	Starting with the shortest possible C++ program, 
	have it display to the console the name of the executable 
	that is running and how many arguments it has.

	
*/

 
//NOTE: by defualt, the main function has defualt member functions that includes:
// 1) the number of arguments, and 
// 2)a pointer to an array of character strings that contain the arguments, one per string. The value argv[argc] is a null pointer.

#include <iostream>
using namespace std;
									//argc is the number of arguments the program has
int main(int argc, char* argv[]) // argv[0] is the name of the program (string) , After that till argv[argc-1] every element (strings) is command-line arguments.
{
	cout << "Name of executbale running...(argv[0]):\n\n" << "...\n\n" << argv[0] << endl << "..." << endl << endl;  //This will give you the exe name
	cout << "Number of arguments passed by user (argc) (including default .EXE filename argument): " << argc << endl << endl;
	cout << endl << "Total arguments is " << argc << "; only the defualt .EXE user filename parameter is used in this program. Thank you(:. \nProgram will Exit...\n\n";
}

