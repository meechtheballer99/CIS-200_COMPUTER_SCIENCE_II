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
#include <iostream>
#include "L8functions.h"
#define LNAME_MAX_LENGTH 16 //cin.getline function includes a nullchar so user will only be able to have a length of 16-1 = 15 //same idea for first name max length
#define FNAME_MAX_LENGTH 11
#include <limits.h>
using namespace std;

//global variables below -- needed  to make my code more concise
char userSelection;
clientData userDataInput; //use this variable to get data from the user and write to the file



/////function declarations ----I am using these functions simply to make it easier to read my main and reduce the cout displays-------------

void mainMenu_OptionA(void);
void mainMenu_OptionB(void);


//////function declarations ----


int main()
{
	initiate_blankClientData(userDataInput); //used to initialize all data members to empty file record according to user's choice
	userDecide_initFile_empty(userSelection);
	if (userSelection == 'X') {
		cout << "\n\n..Overwrite credit.dat file command CANCELLED...You have selected to exit the program.....Thank you...\n\n";
		system("pause");
		return 0;
	}
	openingMenu();
	system("pause");
	displayFull_ClientDataFile();
	
	cout << "\n---Select a Main Menu option---\nA: Search Client Record Database and view account information\nB: Edit Client Data Records\nX: Exit Program\n";;
	cout << "User Selection: ";
	cin >> userSelection;
	
	do {
		if (cin.peek() != '\n') { userSelection = 'f'; } //if users input any invalid data or data that is too long for userSelection variable for any of the menu selection prompts they will be sent to the default case for reprompt
		switch (userSelection) {

		case 'a':
		case 'A':
			mainMenu_OptionA();

			break;
		case 'b':
		case 'B':
			mainMenu_OptionB();
			
			break; 
			
		case 'x':
		case 'X':
			//exit from loop and exit program
			break;
		case 'R': //use this case when exiting from a sub menu and returning to main menu or when user has input invalid data and program must return to main menu option selection
			cout << "\n---Select a Main Menu option---\nA: Search Client Record Database and view account information\nB: Edit Client Data Records\nX: Exit Program\n";;
			cout << "User Selection: ";
			cin >> userSelection;
			break;

		default:
			cout << "\n~invalid user input....please select a valid menu option.....returning to main menu...\n";
			system("pause");
			while (cin.peek() != '\n') { 
				cin.clear();
				cin.ignore(); } //delete all char in stream until we hit newchar to satisfy start of loop if statement and then return to case R --> main menu
			userSelection = 'R'; //use the "return to main menu" case R
			
			break;
		}
		if (cin.peek() != '\n') { userSelection = 'f'; } //if users input any invalid data or data that is too long for userSelection variable for any of the menu selection prompts they will be sent to the default case for reprompt
	} while (userSelection != 'x' && userSelection != 'X');
	


	
	cout << "\n\nYou have selected to exit the program.....Thank you...\n\n";
	system("pause");
	return 0;

}




//function definitions---

void mainMenu_OptionA(void) {

	cout << "\nMain Menu option A) 'Search Client Record Database and view account information' selected...";
	cout << "\n...Please select an account display action: \n";
	cout << "A)display_single_account#.......B)display_all_accounts.......E) exit_to_main_menu\n";
	cout << "User Selection: ";
	cin >> userSelection;
	do {
		if (cin.peek() != '\n') { userSelection = 'f'; } //if users input any invalid data or data that is too long for userSelection variable for any menu selection prompts they will be sent to the default case for reprompt
		switch (userSelection) {

		case 'a':
		case 'A':
			cout << "Option A selected: display a single account's information.\n";
			cout << "Enter an account # (1-100) that you would like to display, or enter '0' to exit the program: ";
			cin >> userDataInput.accountNumber;
			while (cin.fail() || cin.peek() != '\n' || userDataInput.accountNumber > 100 || userDataInput.accountNumber < 1) {
				//while-loop to protect agaisnt invalid non-numerical input data, invalid (too large or too small) a number size, or any other data that causes cin to fail 
				//while-loop also checks for the 0-case and the case of any valid data, but that is out of the range for a valid account (1-100)
				if (userDataInput.accountNumber == 0 && !cin.fail() && cin.peek() == '\n') {//ensure the !cin.fail() clause is also met so that the default acc num of 0 does not cause this if-statment to execute //also ensure newline is left in the buffer only
					userSelection = 'X'; //use the "exit program case" case X

					return;
				} //exit function and return to main, then since userSelection == 'x' the program will exit using the case X from the switch statement
				else if ((userDataInput.accountNumber > 100 || userDataInput.accountNumber < 0) && cin.peek() == '\n') { //use the && statement to ensure this statement is only executed when a user inputs only valid numerical data that is too large
					cout << "\nInvalid account number. Select an account number in the range 1-100, or input '0' to exit program...\n";
					cin.clear(); //need this and the next statement in the case of a number being input that is too large
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore all final characters before the final newline char (which will also be discarded)
				}
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore all final characters before the final newline char (which will also be discarded)
					cout << "\n\n..~ERROR~..Please input a valid number...\n";
					cout << "Enter an account number (1-100) that you would like to make changes to...Or enter '0' to exit program...\n";
				}
				cout << "User Selection: ";
				cin >> userDataInput.accountNumber;
			}
			cout << "\nAccount #" << userDataInput.accountNumber << " found...displaying account information below....\n";
			displaySingle_ClientDataFile(userDataInput.accountNumber);
			cout << "\n...Please select another account display action: \n";
			cout << "A)display_single_account#.......B)display_all_accounts.......E) exit_to_main_menu\n";
			cout << "User Selection: ";
			cin >> userSelection;


			break;
		case 'b':
		case 'B':
			cout << "Option B selected: display account information for all accounts.\n";
			cout << "....loading all accounts....\n";
			system("pause");
			cout << "...loading complete....displaying all accounts below.....\n\n";
			displayFull_ClientDataFile();
			cout << "\n...Please select another account display action: \n";
			cout << "A)display_single_account#.......B)display_all_accounts.......E) exit_to_main_menu\n";
			cout << "User Selection: ";
			cin >> userSelection;

			break;
		case 'e':
		case 'E':
			cout << "Option E selected: exit to main menu.\n";
			cout << ".......exiting to the Main Menu........\n\n";
			system("pause");

			break;
		default:
			cout << "\n~invalid user input....please select a valid menu option: ";
			cout << "\n...Please select an account display action: \n";
			cout << "A)display_single_account#.......B)display_all_accounts.......E) exit_to_main_menu\n";
			cout << "User Selection: ";
			while (cin.peek() != '\n') {
				cin.clear();
				cin.ignore();
			} //delete all char in stream until we hit newchar to satisfy start of while-loop's if-statement ---> will return here if input is invalid again (whether too long or an option not on the menu)
			cin >> userSelection;
			break;
		}
		if (cin.peek() != '\n') { userSelection = 'f'; } //use this statement incase user enters "ejfdajdsa", since the e will be parsed into userSelection, but we want this case to count as invalid since its not one char entered by user into cin stream
	} while (userSelection != 'e' && userSelection != 'E');
	userSelection = 'R'; //use the "return to main menu" case R


}

void mainMenu_OptionB(void) {
	
		cout << "\nMain Menu option B) 'Edit Client Data Records' selected...(note: editing account number of an account is not allowed.\nYou may only switch to an account to edit its other data.)\n\n";
		cout << "Enter an account number (1-100) that you would like to make changes to...Or enter '0' to exit program...\n";
		cout << "User Selection: ";
		cin >> userDataInput.accountNumber;
		while (cin.fail() || cin.peek() != '\n' || userDataInput.accountNumber > 100 || userDataInput.accountNumber < 1) {
		//while-loop to protect agaisnt invalid non-numerical input data, invalid (too or too small large) a number size, or any other data that causes cin to fail 
		//while-loop also checks for the 0-case and the case of any valid data, but that is out of the range for a valid account (1-100)
			if (userDataInput.accountNumber == 0 && !cin.fail() && cin.peek() == '\n') {//ensure the !cin.fail() clause is also met so that the default acc num of 0 does not cause this if-statment to execute //also ensure newline is left in the buffer only
				userSelection = 'X'; //use the "exit program case" case X

				return;
			} //exit function and return to main, then since userSelection == 'x' the program will exit using the case X from the switch statement
			else if ((userDataInput.accountNumber > 100 || userDataInput.accountNumber < 0) && cin.peek() == '\n') { //use the && statement to ensure this statement is only executed when a user inputs only valid numerical data that is too large
				cout << "\nInvalid account number. Select an account number in the range 1-100, or input '0' to exit program...\n";
				cin.clear(); //need this and the next statement in the case of a number being input that is too large
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore all final characters before the final newline char (which will also be discarded)
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore all final characters before the final newline char (which will also be discarded)
				cout << "\n\n..~ERROR~..Please input a valid number...\n";
				cout << "Enter an account number (1-100) that you would like to make changes to...Or enter '0' to exit program...\n";
			}
			cout << "User Selection: ";
			cin >> userDataInput.accountNumber;
		}
		cout << "\nAccount# " << userDataInput.accountNumber << " found; here is the current information for the selected account:\n";
		displaySingle_ClientDataFile(userDataInput.accountNumber);
		cout << "\n...Please select an option for any updates or changes you would like to make to the account: \n";
		cout << "A)update_lastName.......B)update_firstName.......C)update_account_credit_balance.....D)switch_account#.....E) exit_to_main_menu\n";
		cout << "User Selection: ";
		cin >> userSelection;
		
	do {
		if (cin.peek() != '\n') { userSelection = 'f'; } //if users input any invalid data or data that is too long for userSelection variable for any menu selection prompts they will be sent to the default case for reprompt
		switch (userSelection) {

		case 'a':
		case 'A':
			cout << "Option A selected: update last name on the account.\nNote, lastName can be only a max of 15 characters; anything over will be truncated.\n";
			cout << "Enter a new/updated last name for account# " << userDataInput.accountNumber << ": ";
			
			while (cin.peek() == '\n') { //get rid of any lingering newline char from the cin stream so that cin.getline will function properly --> if a newline char is left in buffer then cin.getline function will be skipped
				cin.clear(); //use this in order to make sure that if state is reset and the good bit flag is set/bad bit reset //can be caused from other userinputs that were too long or did not match for the input variable
				cin.ignore(); 
			}
			cin.getline(userDataInput.lastName, LNAME_MAX_LENGTH); //truncate any user input that goes over 16 since this is the size of our charArray in our struct for lastName;
													//get up to 16 - 1 characters in the cin istream object and assign it to lastName (since cin.getline function will make last char nullchar)
			inputClientData(userDataInput, 'L'); //use this function to update credit.dat file at specified user accountNumber location to update account information with specified user information
			cout << "....Last Name updated successfully...here is the updated account number information for the currently selected account: ";
			displaySingle_ClientDataFile(userDataInput.accountNumber);
			cout << "\n...Please select an option for any additional updates or changes you would like to make to the current account:\n";
			cout << "A)update_lastName.......B)update_firstName.......C)update_account_credit_balance.....D)switch_account#......E) exit_to_main_menu\n";
			cout << "User Selection: ";
			if (cin.fail()) {//clear error state flags from possibly truncated/or too-short user input from above cin.getline //also clear buffer
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}
			cin >> userSelection;


			break;
		case 'b':
		case 'B':
			cout << "Option B selected: update first name on the account.\nNote, firstName can be only a max of 10 characters; anything over will be truncated.\n";
			cout << "Enter a new/updated first name for account# " << userDataInput.accountNumber << ": ";
			while (cin.peek() == '\n') { //get rid of any lingering newline char from the cin stream so that cin.getline will function properly
				cin.clear(); //use this in order to make sure that if state is reset and the good bit flag is set/bad bit reset //can be caused from other userinputs that were too long or did not match for the input variable
				cin.ignore();
			}
			cin.getline(userDataInput.firstName, FNAME_MAX_LENGTH); //truncate any user input that goes over 11 since this is the size of our charArray in our struct for firstName;
													//get up to 11 - 1 characters in the cin istream object and assign it to firstName (since cin.getline function will set last char to nullchar)
													//Note*: cin.getline() function automatically uses c-style string mechanics, so it will make the char array a null-terminated char array (last char is made to be nullchar '\0' 
													//So, the cin.getline() function will get sizeofstream - 1 characters that the user inputs into the stream; 
													//for example: cin.getline(charArray, 5) --> if user inputs "hello", which is correctly a max of 5 characters, but the function will input 'h' 'e' 'l' 'l' '\0' since last char must be null terminated of a c-style string (char array)
			inputClientData(userDataInput, 'F'); //use this function to update credit.dat file at specified user accountNumber location to update account information
			cout << "....First Name updated successfully...here is the updated account number information for the currently selected account: ";
			displaySingle_ClientDataFile(userDataInput.accountNumber);
			cout << "\n...Please select an option for any additional updates or changes you would like to make to the current account:\n";
			cout << "A)update_lastName.......B)update_firstName.......C)update_account_credit_balance.....D)switch_account#......E)exit_to_main_menu\n";
			cout << "User Selection: ";
			if (cin.fail()) {//clear error state flags from possibly truncated/or too-short user input from above cin.getline //also clear buffer
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}
			cin >> userSelection;

			break;
		case 'c':
		case 'C':
			cout << "Option C selected: update Credit Balance on the account.\n";
			cout << "Enter the new balance for the account# " << userDataInput.accountNumber << ": ";
			cin >> userDataInput.balance; //input user number into data member that hold's the clientRecord account data
			while (cin.fail() || cin.peek() != '\n' || userDataInput.balance > numeric_limits<float>::max()) {//while loop to protect agaisnt invalid non-numerical input data

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore all final characters before the final newline char (which will also be discarded)
				cout << "\n\n..~ERROR~..Please input valid number data only...\n..Note: max/min value for balance must not be greater/less than +/- " << numeric_limits<float>::max() << "..\n";
				cout << "Enter the new balance for the account# " << userDataInput.accountNumber << ": ";
				cin >> userDataInput.balance;
			}
			inputClientData(userDataInput, 'B'); //use this function to update credit.dat file at specified user accountNumber location to update account information selected
			cout << "....Account Balance updated successfully...here is the updated account number information for the currently selected account: ";
			displaySingle_ClientDataFile(userDataInput.accountNumber);
			cout << "\n...Please select an option for any additional updates or changes you would like to make to the current account:\n";
			cout << "A)update_lastName.......B)update_firstName.......C)update_account_credit_balance.....D)switch_account#......E)exit_to_main_menu\n";
			cout << "User Selection: ";
			cin >> userSelection;
			
			

			break;
		case 'd':
		case 'D':
			cout << "Option D selected: switch accounts.\n";
			cout << "Enter a new account# for which you would like to make changes (enter 0 to exit program): ";
			cin >> userDataInput.accountNumber; //input user selected account number from user so that any updates will go to the proper file location in credit.dat for updates
			while (cin.fail() || cin.peek() != '\n' || userDataInput.accountNumber > 100 || userDataInput.accountNumber < 1) {
				//while-loop to protect agaisnt invalid non-numerical input data, invalid (too or too small large) a number size, or any other data that causes cin to fail 
				//while-loop also checks for the 0-case and the case of any valid data, but that is out of the range for a valid account (1-100)
				if (userDataInput.accountNumber == 0 && !cin.fail() && cin.peek() == '\n') {//ensure the !cin.fail() clause is also met so that the default acc num of 0 does not cause this if-statment to execute //also ensure newline is left in the buffer only
					userSelection = 'X'; //use the "exit program case" case X

					return;
				} //exit function and return to main, then since userSelection == 'x' the program will exit using the case X from the switch statement
				else if ((userDataInput.accountNumber > 100 || userDataInput.accountNumber < 0) && cin.peek() == '\n') { //use the && statement to ensure this statement is only executed when a user inputs only valid numerical data that is too large
					cout << "\nInvalid account number. Select an account number in the range 1-100, or input '0' to exit program...\n";
					cin.clear(); //need this and the next statement in the case of a number being input that is too large
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore all final characters before the final newline char (which will also be discarded)
				}
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore all final characters before the final newline char (which will also be discarded)
					cout << "\n\n..~ERROR~..Please input a valid number...\n";
					cout << "Enter an account number (1-100) that you would like to make changes to...Or enter '0' to exit program...\n";
				}
				cout << "User Selection: ";
				cin >> userDataInput.accountNumber;
			}
			cout << "\n.....switching accounts.......accounts switched successfully....here is the currently selected account: ";
			displaySingle_ClientDataFile(userDataInput.accountNumber);
			cout << "\n...Please select an option for any additional updates or changes you would like to make to the current account: \n";
			cout << "A)update_lastName.......B)update_firstName.......C)update_account_credit_balance.....D)switch_account#......E)exit_to_main_menu\n";
			cout << "User Selection: ";
			cin >> userSelection;

			break;
		case 'e':
		case 'E':
			cout << "Option E selected: exit to main menu.\n";
			cout << ".......exiting to the Main Menu........\n\n";
			
			break;
		default:
			cout << "\n~invalid user input....please select a valid menu option: ";
			system("pause");
			cout << "\nHere is the currently selected account: ";
			displaySingle_ClientDataFile(userDataInput.accountNumber);
			cout << "\n...Please select an option for any updates or changes you would like to make to the current account: \n";
			cout << "A)update_lastName.......B)update_firstName.......C)update_account_credit_balance.....D)switch_account#......E)exit_to_main_menu\n";
			cout << "User Selection: ";
			while (cin.peek() != '\n') {
				cin.clear();
				cin.ignore();
			} //delete all char in stream until we hit newchar to satisfy start of while-loop's if-statement ---> will return here if input is invalid again (whether too long or an option not on the menu)
			cin >> userSelection;
			break;
		}
		if (cin.peek() != '\n') { userSelection = 'f'; } //if users input any invalid data or data that is too long for userSelection variable for any menu selection prompts they will be sent to the default case for reprompt
	} while (userSelection != 'e' && userSelection != 'E');
	userSelection = 'R'; //use the "return to main menu" case R from the while loop in MAIN

}

//function definitions---

	/* ---USED FOR TESTING/STUDYING---
cout << endl << endl << sizeof(userDataInput);  //cout --> 36
cout << endl << endl << sizeof(userSelection);  //cout --> 1			//notice how the size of each data type can vary (but in this instance, their memory address size is only 4 bytes as shown below
float testfloat = 44;
cout << endl << endl << sizeof(testfloat);		//cout --> 4

cout << endl << endl << sizeof(&userDataInput); //cout --> 4
cout << endl << endl << sizeof(&userSelection); //cout --> 4		//notice here how the size of each of the address locations are the same size (4 bytes)
cout << endl << endl << sizeof(&testfloat);		//cout --> 4		//for the most part, the size of any pointer/address

char* ptrChar = new char;
float* ptrFloat = new float;
clientData* testADTptr = new clientData;

cout << endl << endl << sizeof(testADTptr);		//cout --> 4		//ptr variables have thes same size even though they are of diff type (not always true on other systems)
cout << endl << endl << sizeof(ptrChar);		//cout --> 4
cout << endl << endl << sizeof(ptrFloat);		//cout --> 4

//address location of the ptr themselves also are the same size as that of the address location of the other ptr variables and the other nonptr variable's address locations regardless of type
cout << endl << endl << sizeof(&testADTptr);		//cout --> 4
cout << endl << endl << sizeof(&ptrChar);		//cout --> 4
cout << endl << endl << sizeof(&ptrFloat);		//cout --> 4

// address size differ when you dereference the ptrs; the size of memory used to store the actual data varies....
cout << endl << endl << sizeof(*testADTptr);	//cout --> 36
cout << endl << endl << sizeof(*ptrChar);		//cout --> 1
cout << endl << endl << sizeof(*ptrFloat);		//cout --> 4

int* p = new int(65);
int* q = new int(65);
char* ch = reinterpret_cast<char*>(p);
char* testcharPtr = reinterpret_cast<char*>(q);
char* testcharPtr2 = new char('A');
int testint_address = 3;
cout << endl;
cout << &testint_address << endl; //cout --> 00CFFAD4 //so you see here even though this integer isn't associated with a pointer, its address location is the same 
													 //size as that of what an int pointer points to (but the ptr size itself is always 4 bytes for all data types --at least for this system)
cout << *p << endl;		//cout --> 65
cout << *ch << endl;	//cout --> A
cout << *testcharPtr << endl; //cout --> A
cout << p << endl;		//cout --> 00C13808			//as you can see, int ptr points to a much larger address (and thus byte size) than the ch ptr; int > char.
cout << ch << endl;		//cout --> A
cout << testcharPtr << endl; //cout --> A
cout << testcharPtr2 << endl; //cout --> A²²²²
cout << &testcharPtr << endl;//cout --> 009FFDE8

//so the byte size of ptr's themselves are/can be a different size than the size of the data they point to.
//a char ptr is 4 bytes (for this system/app which is 32bit), but it points to a char that has a size of only 1 byte


Size of char : 1 byte
Size of int : 4 bytes
Size of short int : 2 bytes
Size of long int : 8 bytes
Size of signed long int : 8 bytes
Size of unsigned long int : 8 bytes
Size of float : 4 bytes
Size of double : 8 bytes
Size of wchar_t : 4 bytes

SPECIAL NOTE:
cin >> will parse all char in stream ignoring the leading whitespaces and newline characters -- then it gets all input up until another whitespace or newline char
getline and cin.getling will get all input until it reaches a newline char, which it also discards that newline char or the selected delemeter char
*SPECIAL NOTE* :
//char testchar[6] = "hello"; note to initialize char array to "hello" you must have a char array of size 6, not 5, since the = operator is overloaded so that the last char is given nullchar
*/