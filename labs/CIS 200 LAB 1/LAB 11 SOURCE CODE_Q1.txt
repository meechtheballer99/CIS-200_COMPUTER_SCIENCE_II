


/*  
	*Author: Demetrius Johnson
	*Creation Date: 01 April 2020
	*Modification Date: 06 April 2020
	*Purpose: 

	// LAB 11 - CIS 150 - MEECH.cpp

	Question 1
	-------------------------
	In this question, you will create a database with information about US states. 
	You are given usstates.txt which is a file that contains some data about all 50 states.
	Its columns are, respectively: state abbreviation, state name, capital, population, year it became a state, and number of representatives in congress.
	Your job is to design and write a class, to be named State. 
	The class's private attributes should be the above 
	mentioned six data items (use stateAbrv, stateName, capital, population, year, numCongress); the first three should be string, the last three should be int.
	In addition to the above six attributes, which should be private, the class should also contain 
	the usual public methods, access methods (set/get), and utility methods of your choice. 
	An example of utility method (but feel free to implement any other one is a method that returns the number of state residents per representatives.
	You will then write an implementation for the class (state.cpp) that is compatible with the interface, and that contains the code for its methods.
	You will have a total of three files: state.h, state.cpp, and main.cpp.

	Your program should first call a function that reads the data from the file and stores it into a vector or array (your choice) of object of type State.
	Your main program will then present a menu to the user. 
	The menu will consist of the following three options to allow a user to search for information about a given state using your State class:
	1.	Search by state abbreviation (e.g. MI).
	2.	Search by year of statehood (e.g. 1837).
	3.	Exit program.
	   Please enter your choice (1-3):
	Each option in the menu should be executed by a calling function.
	You program, will then output the information in tabulated form:
	State Abrv.    Name     Capital  Population Year #Congress
	MI	        Michigan   Lansing   9923000   1837     14


	In the case of option 2, if there are multiple states that have the same year of statehood, then you program must list all of them (one state per row) as shown below:
	State Abr.   Name      Capital   Population Year #Congress
	CT		 Connecticut Hartford  3591000	1788    5
	GA		 Georgia	   Atlanta   3591000	1788    14
	…
	If a corresponding state is not found in the search, then the following message should be displayed to the user:
		“No state exists with this information.”


	Test cases:

	You need to test your program against the following 4 test cases. Include these test cases in your report along with the corresponding screenshots.
	•	Test option 1 of your menu with any valid state that you’d like
	•	Test option 2 of your menu with 1788 provided as input for the year.
	•	Test option 2 of your menu with 2018 provided as input for the year.
	•	Test option 3 of your menu.



*/


#include "state.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>


using namespace std;

//-------------------------------FUNCTION DECLARATIONS----------------------------------------//
void readStateInfo(ifstream& ifs, vector<State>& stateVec);
vector<State> searchByStatehood(vector <State>& stVec, int year);
vector<State> searchByAbrv(vector <State>& stVec, string abrv);
void displayMenu();
void mainMenu();
void displayTableHeader();
//------------------------------------FUNCTION DELCARATIONS------------------------------------//




int main()
{
	int userChoice, userYearInput;
	string userAbrInput;

	string US_StatesInputFileName = "US_STATES_DATA.txt";
	vector <State> stateVec, searchByAbrVec, searchByStatehoodVec;
	ifstream ifs;


	ifs.open(US_StatesInputFileName);		//open USstates data file necessarry to run the program & ensure file is found/opens
	if (!ifs.is_open()) {
		cout << "There was a problem accessing the input data file to run this program.\n";
		cout << "Please ensure the required data file is in the correct file directory.\n";
		cout << "Program will exit. File not found or corrupt. Thank you.\n";
		return 0;
	}			
	readStateInfo(ifs, stateVec);		 //read state info into vector
	ifs.close();						//cose file after all the data has been successfully read into the States vector

	mainMenu();							//display menu & process input
	do {
		cin >> userChoice;
		switch (userChoice) {
		case 1: //search by abbreviation
			cout << "You have selected menu option 1 (search by abbreviation): \n\n";
			system("pause");
			cout << "Enter a state abbreviation to display its information: ";
			cin >> userAbrInput;
			userAbrInput.at(0) = toupper(userAbrInput.at(0));
			userAbrInput.at(1) = toupper(userAbrInput.at(1));
			searchByAbrVec = searchByAbrv(stateVec, userAbrInput);
			displayTableHeader();
			for (int elementPos = 0; elementPos < searchByAbrVec.size(); elementPos++) {//display found information

				searchByAbrVec.at(elementPos).displayStateInfo();
			}
			if (searchByAbrVec.size() == 0) {//see if vector is empty which means no matches found
				cout << "\n\n************************NO STATE ABBREVIATION FOUND*****************************\n\n";
			}
			searchByAbrVec.clear(); //clear vector for reuse
			displayMenu();
			break;
		case 2: //search by year of statehood
			cout << "You have selected menu option 2 (search by year of statehood): \n\n";
			system("pause");
			cout << "Please enter a year to display information about states of that year's statehood: ";
			cin >> userYearInput;
			searchByStatehoodVec = searchByStatehood(stateVec, userYearInput);
			displayTableHeader();
			for (int elementPos = 0; elementPos < searchByStatehoodVec.size(); elementPos++) { //display found information

				searchByStatehoodVec.at(elementPos).displayStateInfo();
			}
			if (searchByStatehoodVec.size() == 0) {//see if vector is empty which means no matches found
				cout << "\n\n*********************NO STATEHOOD YEARS FOUND**************************\n\n";
			}
			searchByStatehoodVec.clear(); //clear vector for reuse
			displayMenu();
			break;

		default:
			cout << "\n\nYou have selected to exit the program. Thank you for US STATE's-ing with us(:\n\n";
			system("pause");
			return 0;
		}
	} while (userChoice == 1 || userChoice == 2);



	return 0;

}






//------------------------------------FUNCTION DEFINITIONS BELOW THIS LINE------------------------------------//



void readStateInfo(ifstream& ifs, vector<State>& stateVec){
	
	State tmpState;
	string dataLineFromInputFile;
	string stateAbrv, stateName, capital; 
	stringstream ss;						//temporary storage variables for ss parsing to store data in tempState object
	int population, year, numCongress;     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	int fileCheckDataLineCounter = 0;
	char delimiter = ',', delimiterReplaceVar = ' ';
	char two_wordNamesSpacing = ' ', replaceSpaceChar = '_';
		while (!ifs.eof())
		{

			getline(ifs, dataLineFromInputFile, '\n');			//read other inputs on a given line using getline	
			for (int counter = 0; counter < dataLineFromInputFile.size(); counter++) { //chage all spaces to '_' for ss use
				if (dataLineFromInputFile.at(counter) == two_wordNamesSpacing) {
					dataLineFromInputFile.at(counter) = replaceSpaceChar;
				}

			}
			for (int counter = 0; counter < dataLineFromInputFile.size(); counter++) { //chage all commas to spaces for ss use
				if (dataLineFromInputFile.at(counter) == delimiter) {
					dataLineFromInputFile.at(counter) = delimiterReplaceVar;
				}

			}
			ss << dataLineFromInputFile;		//output dataline to string stream
			ss >> stateAbrv >> stateName >> capital >> population >> year >> numCongress; //input from string stream into variables
			ss.clear(); //clear ss buffer for usage in the next iteration of the loop
			for (int counter = 0; counter < stateAbrv.size(); counter++) { //change any '_' back to space ' '
				if (stateAbrv.at(counter) == replaceSpaceChar) {
					stateAbrv.at(counter) = two_wordNamesSpacing;
				}
			}

		
		for (int counter = 0; counter < stateName.size(); counter++) { //change any '_' back to space ' '
			if (stateName.at(counter) == replaceSpaceChar) {
				stateName.at(counter) = two_wordNamesSpacing;
			}

			}
			for (int counter = 0; counter < capital.size(); counter++) { //change any '_' back to space ' '
				if (capital.at(counter) == replaceSpaceChar) {
					capital.at(counter) = two_wordNamesSpacing;
				}

			}
			//use tmpState.<method> and passing variables into the object through the method------------
			tmpState.setStateAbrv(stateAbrv);
			tmpState.setStateName(stateName);
			tmpState.setCapital(capital);
			tmpState.setPopulation(population);
			tmpState.setYear(year);
			tmpState.setNumCongress(numCongress);
			//------------------------------------------------------------------------------------------
			stateVec.push_back(tmpState);	//add the object to the vector
			fileCheckDataLineCounter = stateVec.size();  //set dataline counter to State vector size to ensure 50 lines of data is read
		}

		cout << "\nFileChecker: (the number of datalines (states) read from program files is: " << fileCheckDataLineCounter << ")\n";
		if (getline(ifs, dataLineFromInputFile, ',')) { cout << "no errors"; } //file read error checkers
}


vector<State> searchByAbrv(vector <State>& stVec, string abrv)
{

	vector<State> abrFoundVector;
	
	for (int elementPos = 0; elementPos < stVec.size(); elementPos++) {
		if (stVec.at(elementPos).getStateAbrv() == abrv) {
			abrFoundVector.push_back(stVec.at(elementPos));
		}
	}
	return abrFoundVector;
}


vector<State> searchByStatehood(vector <State>& stVec, int year)
{
	vector<State> yearFoundVector;

	for (int elementPos = 0; elementPos < stVec.size(); elementPos++) {
		if (stVec.at(elementPos).getYear() == year) {
			yearFoundVector.push_back(stVec.at(elementPos));
		}
	}
	return yearFoundVector;
}



//------DISPLAY MENUS--------------//
void displayMenu()
{
	cout << "----------------------------------------------------------------------------------------------\n";
	cout << "You have returned to the main menu; Please select another option: \n";
	cout << "1.	Search by state abbreviation(e.g.MI).\n"
		<<	"2.	Search by year of statehood(e.g. 1837).\n"
		<<	"3.	Exit program.\n\n"
		<< "Please enter your choice(1 - 3) : ";





}
void mainMenu()
{

	cout << "---------------------------------WELCOME TO THE US STATES INFORMATION PROGRAM-------------------------\n"
			<< "This program outputs state information based on the following menu choices selected by the user.\n"
			<< "It will provide:\n\n state abbreviation\n state name\n capital\n population\n year it became a state\n and number of representatives in congress\n\n";
	cout << "MENU OPTIONS: \n\n";
	cout << "1.	Search by state abbreviation(e.g.MI).\n"
			<< "2.	Search by year of statehood(e.g. 1837).\n"
			<< "3.	Exit program.\n\n"
			<< "Please enter your choice(1 - 3) : ";




}
void displayTableHeader()
{
	//Display table header:
	cout << endl;

	cout << right << setw(20) << "State Abr." << setw(20) << "Name" << setw(20) << "Capital"
		<< setw(20) << "Population" << setw(11) << "Year" << setw(15) << "#Congress" << endl;

	cout << endl;

}