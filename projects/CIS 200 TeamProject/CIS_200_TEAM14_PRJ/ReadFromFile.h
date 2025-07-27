//Read from file class HEADER FILE
//D Johnson
//J Fang


#ifndef READFROMFILE_H
#define READFROMFILE_H
#include "JobType_ABC.h"
#include "CPU_Controller.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h> //use this library for functions such as rand() number function
#include <iomanip> //use this for table formatting
#define JobType_ABC_ByteSize sizeof(JobType_ABC) //define the byte size of JobType_ABC since it will not change for the duration of this program
using namespace std;

class ReadFromFile
{

private:

	int totalJobsArrived_A = 0;
	int totalJobsArrived_B = 0;
	int totalJobsArrived_C = 0;
	int totalJobsArrived = 0;

public: 
	void openingMenu(void); //use this for opening menu of program
	void re_initFile_newDataSet(void); //use this to initialize the data file that this program uses
	void userDecide_re_initFile(void); //use this to give user decision about program initialization concerning the data file that the program uses 
	void displaySnippet_dataFile(void); //use this to display a snippet size specified by the user to see what is in the currently loaded data file for the program and ensure it is formatted properly and as expected
	int jobsReadFromFile(void); //use this to display how many jobs are currently stored in the data file that the program uses
	void AddTo_Queue_FromFile(vector<JobType_ABC>& arrvivalQueue_vector, int& counter_JobsReadFromFile_seekInFile); //use this function to read jobs from the data file into the arrivalQueue vector that is in MAIN
	int peekFile_nextJob_arrivalTime(int& counter_JobsReadFromFile_seekInFile); //use this function to check and return the arrival time of the next job in the data file so that we can approriately decide wether to add it to the arrivalQueue that is in MAIN
	int userDecide_setNumberOf_CPUs(vector<CPU>& CPU_vector); //use this function to establish the number of CPUs that the program will utilize --> will size the CPU_vector that is in MAIN based on user decision

	int get_TotalArrivals_A(void);
	int get_TotalArrivals_B(void); //use these functions to return the total arrivals of each job type
	int get_TotalArrivals_C(void);
	int get_totalArrivals(void); //get the total job arrivals
};

#endif 
