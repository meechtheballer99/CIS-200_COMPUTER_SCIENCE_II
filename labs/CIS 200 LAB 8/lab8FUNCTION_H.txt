// DemetriusJohnson-Lab8_CIS-200.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*

Given:
struct clientData {
   int accountNumber;
   char lastName[ 16 ];		// c-style string, not string
   char firstName[ 11 ];
   float balance;
};

Create a random access file of 101 records named “credit.dat” using these code segments in a function to initialize the file to empty records:
ofstream creditFile( "credit.dat", ios::out);
clientData blankClient = { 0, "", "", 0.0 };

for ( int i = 0; i <= 100; i++ )
   creditFile.write( reinterpret_cast<const char *>( &blankClient ), sizeof( clientData ) );
creditFile.close();
<ostream> member function write - outputs a fixed number of bytes beginning at a specific location in memory to the specific stream (file).

The write function expects the first argument of type const char *, hence the use of
reinterpret_cast <const char *> to convert the address of blankClient to const char *.
The second argument of write is an integer specifying the number of bytes to be written. Thus the use of sizeof( clientData ).
Since size will never change it must be declared as a constant variable; sizeof must only appear once in your program: for the constant declaration.

The first entry in the file will be skipped so that record 1 is at position 1 and not position 0.

Write data into the file [minimum of 15 records, not in 15 consecutive account numbers] getting all data from the user.
Truncate user input if it is too long for the data field.
Read data from the file. Loop, asking user for an account number to find (range 1 to 100, 0 to end input. (error message if not a valid account number and try again).
Print out all data fields for this account.
Update an account. Loop, asking user for an account number to update (error message if not a valid account number and try again) or 0 to quit (do several updates).
Update firstname, lastname, or balance (but NOT accountNumber).
Print out all records that do not have accountNumber of 0, formatting output into columns (label columns).


*/

#ifndef L8FUNCTIONS_H
#define L8FUNCTIONS_H
#include<fstream> //include fstream class for file input and output stream objects



struct clientData {

	//DATA MEMBERS
	int accountNumber;
	char lastName[16];
	char firstName[11];
	float balance;
};

void openingMenu(void);
void initFile_empty(void);
void userDecide_initFile_empty(char& userSelection );
void displayFull_ClientDataFile(void);
void displaySingle_ClientDataFile(int accountNum);
void inputClientData(clientData& userInputClientData, char updateOption);
void initiate_blankClientData(clientData& CD);


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#endif // !1