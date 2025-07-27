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
#include "L8functions.h"
#include <iostream>
#include <iomanip> //use this for table formatting
#include <string>
#define nullchar '\0' ///define nullchar character for easy use in my program
#define clientData_ByteSize sizeof(clientData) //define the byte size of clientData since it will not change for the duration of this program
using namespace std;


void openingMenu(void) {


	cout << "---------------------------------------WELCOME---------------------------------------------\n\n";
	cout << "This program will read and write data to a clientData database binary file 'credit.dat'.\n";
	cout << "Below is the current database of all accounts (1 to 100): \n";




}
void initFile_empty(void) {

	ofstream creditFile_write("credit.dat", ios::out | ios::binary);  //NOTE:if no file exists, you may not be able to open in binary or using any other addtional modes 
												 //must open the uncreated file first using only the default constructor (no additional paramters other than ios::out and the file name),
												 // then close it and reopen (in binary for example) the newly created file. (idk if this is because of a c++ error but it worked as long as i didnt set the int mode (the last parameter)
	if (!creditFile_write.is_open()) {
		cout << "\nunable to open 'credit.dat' file.\n";
	}
	else { cout << "\n~Random Access File 'credit.dat' opened successfully~\n"; }
	clientData blankClient = { 0, "", "", 0.0 }; //use this object to initialize 101 empty account records into the file

	for (int i = 0; i <= 100; i++) {
		blankClient.accountNumber = i; //use this to initliaze all accounts from 0 to 100
		creditFile_write.write(reinterpret_cast<const char*>(&blankClient), clientData_ByteSize); //reinterpret blankClient address as a Char pointer object in order to write data to the file
	}
	creditFile_write.clear(); //clear stream buffer
	creditFile_write.close(); //close the file

}

void userDecide_initFile_empty(char& userSelection) {


	string userChoice;
	cout << "\n~Program Initialization~\n";
	cout << "Enter 'yes' to initiate credit.dat file to empty record and launch the program.";
	cout << "\nEnter 'no' to leave credit.dat file as is and launch the program.\n" << "User option ('yes' or 'no'): ";
	cin >> userChoice;

	if (userChoice == "yes") {
		cout << "\n...User has entered 'yes'....intiating credit.dat binary file to EMPTY records.....wiping file......launching program...(abort program to cancel file wipe)..\n";
		system("pause");
		cout << "\n...credit.dat file wiped successfully....\n\n";
		initFile_empty();
		

	}
	else {

		cout << "\n...User has entered 'no', or user input undetermined...credit.dat binary file will NOT be wiped....launching program...\n";
		system("pause");
		fstream testStream("credit.dat", ios::in | ios::binary | ios::_Nocreate);
		//use fstream variable if user decides no or undetermined input, that way if file is not created it will still be created
		if (!testStream.is_open()) {
			cout << "\n...Launch failed...???unable to open 'credit.dat' file....file does not exist???\n";
			system("pause");
			cout << "\n~Would you like the program to create the file 'credit.dat'? If file is already present but corrupt/undetected, it will be overwritten...~\n";
			cout << "\nEnter the word 'proceed' to proceed with creating the file and launching the program; otherwise, program will exit and NO FILE will be created or overwritten...\n";
			cout << "User Choice: ";
			userChoice.clear();
			cin >> userChoice;
			if (userChoice == "proceed") { 
				cout << "\n\n...File created or corrupt file over written....Opening 'credit.dat' file and launching program....\n\n";
				system("pause");
				initFile_empty(); 
			
			}
			else { userSelection = 'X'; }

			testStream.clear();
			testStream.close();
		}
	}
}

void inputClientData(clientData& userInputClientData, char updateOption) { //selection option paramter used F = firstname L = lastname B = balance
																		   //used to determine which part of the account to update when calling the function

	int accountNum_Holder = userInputClientData.accountNumber; //use this to reset userInputClientData fields to empty --> but only keep the accountNumber field the same 
	//I need to reset the data fields and keep account num the same so that left over old data is not left in the fields for whenever userInputClientData uses this function again to update another field
	int fileMemLoc = (userInputClientData.accountNumber) * clientData_ByteSize; //use this variable to write to proper location in the file 
	//make fileMemLoc equal to the account number because we will start writing at the location directly after account number which is also the correct location of the 
	//account number since 0 is included in the byte count (the 0 unit_byte_size/0th byte in the file at the start position)		
				

	clientData originalData; //use this to get the data currently stored in the file at the specified user account number location (memory location)
	initiate_blankClientData(originalData);
	ifstream creditFile_read("credit.dat", ios::in | ios::binary);
	creditFile_read.seekg(userInputClientData.accountNumber * clientData_ByteSize, ios::beg); //start at the 0 position (start) of the file and move forward accountNum times to reach the point in the file storing the information of specified acct num

	creditFile_read.read(reinterpret_cast<char*>(&originalData), clientData_ByteSize); //read data of given byte_size into originalData struct using a char* pointer
							//The function has parameters to point to the data with a char* pointer, which is why originalData reference address has to be cast as a char* pointer
	creditFile_read.clear();
	creditFile_read.close(); //close the stream..no longer needed; we have successfully acquired the data current stored for user-specified account
	if (updateOption == 'L') { //if data field is not empty string, then we need to update the originalData with this new information sent by the user via userDataInput variable
		strcpy_s(originalData.lastName, userInputClientData.lastName); //use the string copy function since the last name data member (and also the first name member) are char arrays --otherwise you get lvalue error
	}
	if (updateOption == 'F') { //if data field is not empty string, then we need to update the originalData with this new information sent by the user via userDataInput variable
		strcpy_s(originalData.firstName, userInputClientData.firstName); //use the string copy function since the last name data member (and also the first name member) are char arrays --otherwise you get lvalue error
	}
	if (updateOption == 'B') { //if data field is not null, then we need to update the originalData with this new information sent by the user via userDataInput variable
		originalData.balance = userInputClientData.balance;
	}
	//after the above 3 if clauses, then originalData has been updated with the appropriate information sent from the user via userInputClientData variable that is passed into this function
	//now we can use originalData to update the file with the new data that will be its originalData, and we can also reset userInputClientData and only keep its account number
	initiate_blankClientData(userInputClientData);//resetting data
	userInputClientData.accountNumber = accountNum_Holder; //keeping the original account number from user

	ofstream creditFile_write("credit.dat", ios::out | ios::binary | ios::_Nocreate);  //NOTE:if no file exists, you may not be able to open in binary or using any other addtional modes 
												 //must open the uncreated file first using only the default constructor (no additional paramters other than ios::out and the file name),
												 // then close it and reopen (in binary for example) the newly created file. (idk if this is because of a c++ error but it worked as long as i didnt set the int mode (the last parameter)
	if (!creditFile_write.is_open()) {
		cout << "\nunable to open 'credit.dat' file.\n";
	}
	else { cout << "\n~Random Access File 'credit.dat' opened successfully~\n"; }


	creditFile_write.seekp(fileMemLoc, ios::beg); //start from beginning of file and move to the memory location specified by fileMemoryLocation
	creditFile_write.write(reinterpret_cast<const char*>(&originalData), clientData_ByteSize);
	
	bool testbool = creditFile_write.bad(); //used for debugging
	//cout << testbool;
	creditFile_write.clear(); //clear stream buffer
	creditFile_write.close(); //close the file

}

void displayFull_ClientDataFile(void){

	int outputHeader_menuCounter = 1; //use this counter in order to determine when to output the display table's header so that it is easy for a user to read/identify labels when they scroll down the list
	clientData readClient;
	ifstream creditFile_read("credit.dat", ios::in | ios::binary);
	if (!creditFile_read.is_open()) {
		cout << "\nunable to open 'credit.dat' file.\n";
	}
	else { cout << "\n~Random Access File 'credit.dat' opened successfully~\n"; }

	cout << setprecision(2) << fixed; //using iomanip I set the precision to 2 and set it fixed so that all future outputs of floats or doubles will have 2 decimal places, even if its value is 0 --> 0.00
	cout << "-Acct_#-" << setw(30) << "-lastName-" << setw(30) << "-firstName-" << setw(31) << "-Acct_Balance-" << endl << endl; //initiate top of table labeling

	creditFile_read.seekg(clientData_ByteSize, ios::beg); //use this to skip the 0 position of the file and then skip the 0 position bytesize index since the 0 index is not where the database starts for this program
	for (int i = 1; i <= 9; i++) {// I separated the loops solely for neatness purposes for the output table when the values get larger in place value
		//start at i == 1 because we will make account 1 at position 1, not position 0 (the 0 byte position) of the file
		creditFile_read.read(reinterpret_cast<char*>(&readClient), clientData_ByteSize); //read data of given byte_size into readClient struct using a char* pointer
								//The function has parameters to point to the data with a char* pointer, which is why readClient reference address has to be cast as a char* pointer
		cout << readClient.accountNumber << setw(35);
		cout << readClient.lastName << setw(30);
		cout << readClient.firstName << setw(31);
		cout << readClient.balance << endl;
		cout << "---" << setw(35) << "------------------" << setw(30) << "----------------" << setw(31) << "---------------" << endl;
		outputHeader_menuCounter++;
	}
	
	for (int j = 10; j <= 99; j++) {// I separated the loops solely for neatness purposes for the output table when the values get larger in place value
		creditFile_read.read(reinterpret_cast<char*>(&readClient), clientData_ByteSize); //read data of given byte_size into readClient struct using a char* pointer
								//The function has parameters to point to the data with a char* pointer, which is why readClient reference address has to be cast as a char* pointer
		cout << readClient.accountNumber << setw(35);
		cout << readClient.lastName << setw(30);
		cout << readClient.firstName << setw(30);
		cout << readClient.balance << endl;
		cout << "---" << setw(35) << "------------------" << setw(30) << "----------------" << setw(31) << "---------------" << endl;
		outputHeader_menuCounter++;
		if (outputHeader_menuCounter % 15 == 0) {//output table header labeling again every 20 lines
			cout << endl << "-Acct_#-" << setw(30) << "-lastName-" << setw(30) << "-firstName-" << setw(31) << "-Acct_Balance-" << endl << endl; //initiate top of table labeling
		}
	}
	
	// I separated the loops solely for neatness purposes for the output table when the values get larger in place value
	creditFile_read.read(reinterpret_cast<char*>(&readClient), clientData_ByteSize); //read data of given byte_size into readClient struct using a char* pointer
							//The function has parameters to point to the data with a char* pointer, which is why readClient reference address has to be cast as a char* pointer
	cout << readClient.accountNumber << setw(35);
	cout << readClient.lastName << setw(30);
	cout << readClient.firstName << setw(29);
	cout << readClient.balance << endl;
	cout << "---" << setw(35) << "------------------" << setw(30) << "----------------" << setw(31) << "---------------" << endl;
	
	
	creditFile_read.clear();
	creditFile_read.close();



}

void displaySingle_ClientDataFile(int accountNum) {
	clientData readClient;
	ifstream creditFile_read("credit.dat", ios::in | ios::binary);
	if (!creditFile_read.is_open()) {
		cout << "\nunable to open 'credit.dat' file.\n";
	}
	else { cout << "\n~Random Access File 'credit.dat' opened successfully~\n"; }

	cout << setprecision(2) << fixed; //using iomanip I set the precision to 2 and set it fixed so that all future outputs of floats or doubles will have 2 decimal places, even if its value is 0 --> 0.00
	cout << endl << "-Acct_#-" << setw(30) << "-lastName-" << setw(30) << "-firstName-" << setw(31) << "-Acct_Balance-" << endl << endl; //initiate top of table labeling

	creditFile_read.seekg(accountNum * clientData_ByteSize, ios::beg); //start at the 0 position (start) of the file and move forward accountNum times to reach the point in the file storing the information of specified acct num
	
	creditFile_read.read(reinterpret_cast<char*>(&readClient), clientData_ByteSize); //read data of given byte_size into readClient struct using a char* pointer
							//The function has parameters to point to the data with a char* pointer, which is why readClient reference address has to be cast as a char* pointer
	cout << readClient.accountNumber << setw(35);
	cout << readClient.lastName << setw(30);
	cout << readClient.firstName << setw(31);
	cout << readClient.balance << endl;
	cout << "---" << setw(35) << "------------------" << setw(30) << "----------------" << setw(31) << "---------------" << endl;
	
	creditFile_read.clear();
	creditFile_read.close();


}

void initiate_blankClientData(clientData& CD) {

	CD = { 0, "", "", 0.0 };


}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

