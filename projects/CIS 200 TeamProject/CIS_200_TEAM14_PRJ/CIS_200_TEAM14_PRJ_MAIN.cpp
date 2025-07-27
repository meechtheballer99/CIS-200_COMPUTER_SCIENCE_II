// CIS_200_TEAM14_PRJ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Demetrius Johnson 
//Jingzhou Fang

//special note: We will use vectors for this project; even though a linked list is better to use when you have to delete elements from the container at the front of the list (element 0);
//however, our vector will remain relatively small and so it will have an affect on the Big 0 time complexity (number of executions) of our project, but not enough in our judgement to use a linked list; we will use the ease of std vector class
//In the future, we could easily revamp this program and replace any vectors and all vector functionality with a more efficient linked list

//Another note: if any jobs in arrivalQueue match the clock they will move to a CPU to be processed --> if no CPU is available they will move into the jobQueue

/*

Primary Logic (Clock Manager):

  1) Check data file for any arrival times that match the clock and add it to the ArrivalQ vector

  2) Flush the arrivalQueue vector --> send all jobs from arrival Queue to the CPU Vector to be processed (or to the CPU(s) with the smallest JobQ)

  3) Run all processors

  4) incremenet clock manager

  5) repeat 1-4

*/


#include "ReadFromFile.h"
using namespace std;

int main()
{
    cout << "\nProgram by: Demetrius Johnson && Jingzhou Fang --UM DEARBRON F2020 SEMESTER --PROF ROBERT MAN CIS 200\n";
    int counter_logFile = 0;
    int CPUtotalTime_Idle_Running = 0;
    int nextArrivalTime_inFile = 0; //use this variable to store what is peeked as the next arrival time of the next job in the file
    int CPUvec_smallestJobQ = 0; //use this variable for storing the smallest jobq in the CPU vector
    int counter_CurrJobsReadFromFile = 0; //use this variable in order to keep track of the number of jobs that has been read from the data file --> this value will also be used to manipulate the pointer in a file stream variable reading the data file
    int counter_ClockManager_TimeUnit = 0; //use this as the clock management variable in order to track and perform clock cycles
    int counter_JobsCompleted_Total = 0; //use this to keep track of the total jobs completed by all processors in order that the clockManager Loop has a basis for which to exit and stop iterating through the while-loop
    int totalJobs_inCurrLoadedDatFile = 0; //use this variable to store the total number of jobs read from the data file used for the program --> we will use this variable to determine when we will exit the clockManager loop
    int size_of_CPU_vec = 0; //use this to store the size of CPU vector in order to use this variable by reference in some of the functions that will be used in this program in order to boost program performance
    vector<JobType_ABC> arrivalQueue_vector{}; //reading from file into this vector the next jobs that are wating for the matching clock value in order to enter the jobQueue_vector
    vector<CPU> CPU_vector; //use this vector to set the number of CPU's the program will use based on user input at initialization of program; size of this vector will not change for the duration of this program
    ReadFromFile RFF; //delcare ReadFromFile variable for use of the duration of this program to handle reading the data file 
    CPU_Controller CPU_C; //use this object which is a derived object of the base class CPU --> need this class to perform algorithms on the CPU_vector such as adding jobs, checking status, and using functions to distribute jobs to the CPUs jobQueue vector

    RFF.userDecide_re_initFile();
    RFF.openingMenu();
    RFF.displaySnippet_dataFile();
    size_of_CPU_vec = RFF.userDecide_setNumberOf_CPUs(CPU_vector); //store CPU size in this variable
    CPU_C.set_CPUsize(size_of_CPU_vec); //set the CPUsize data member in CPU_controller for use in the class functions
    totalJobs_inCurrLoadedDatFile = RFF.jobsReadFromFile(); //establish total number of jobs that are in the data file to be processed --> will use this value for the loop in order to exit the loop once all jobs have been processed
    
    ofstream LogFileStream("Logfile.txt"); //open log file and use below statements to make sure it opens and creates a new log file successfully
    if (!LogFileStream.is_open()) {
        cout << "\n~Logfile Failed to create and open~\n";
        system("pause");
    } //ensure logfile is open
    else {
        cout << "\n~New Logfile Opened Successfully~...\n";
        system("pause");
    } //if open then let the user know opened successfully
    LogFileStream << "\nProgram by: Demetrius Johnson && Jingzhou Fang --UM DEARBRON F2020 SEMESTER --PROF ROBERT MAN CIS 200\n";
  
    /**/
    while (counter_JobsCompleted_Total < totalJobs_inCurrLoadedDatFile) { //use this clockManager loop to execeute 1 iteration of 1 clock cycle unit 
                                                                          ////loop until all jobs in the file have been read and processed --> based on data file and user input






        //CLOCK SEQUENCE 1: Check data file for any arrival times that match the clock and add it to the ArrivalQ vector
        nextArrivalTime_inFile = RFF.peekFile_nextJob_arrivalTime(counter_CurrJobsReadFromFile);
        while (nextArrivalTime_inFile == counter_ClockManager_TimeUnit && counter_ClockManager_TimeUnit != 0) { //if the next job's arrival time is equal to the clockManager, then use this loop to input the job(s) into the arrivalQ_vector

            RFF.AddTo_Queue_FromFile(arrivalQueue_vector, counter_CurrJobsReadFromFile); //this function will add the job(s) to the ArrivalQ vector and increment the jobsRead from file counter accordingly
            nextArrivalTime_inFile = RFF.peekFile_nextJob_arrivalTime(counter_CurrJobsReadFromFile); //set next arrival time to be compared to clock manager again
        }


        //CLOCK SEQUENCE 2: Flush the arrivalQueue vector --> send all jobs from arrival Queue to the CPU Vector to be processed (or to the CPU(s) with the smallest JobQ)
        while (arrivalQueue_vector.size() != 0) {

            CPUvec_smallestJobQ = CPU_C.findSmallest_CPUjobQueue(CPU_vector); //algorithm in this function will find the smallest jobQ out of all the CPUs
            CPU_C.addJobFrom_arrivalQ_to_CPU(arrivalQueue_vector, CPU_vector, CPUvec_smallestJobQ);
        }

        //CLOCK SEQUENCE 3: Process all jobs on all CPUs --> all CPUs will decrement processes and add jobs from their jobQ accordingly and track their processing metrics
        CPU_C.all_CPUs_process_Job(CPU_vector);
        counter_JobsCompleted_Total = CPU_C.getSum_allJobsCompleted_CPUs(CPU_vector);


        //CLOCK SEQUENCE 4: Increment clock manager

        counter_ClockManager_TimeUnit++; //increment the clockManager after this loop executes so we know which clock time unit is iterating during the next loop iteration

        //use the below statment to pause program to see current metrics for 500 time units and for 9500 time units
        CPUtotalTime_Idle_Running = CPU_C.getSum_total_Run_Idle_time(CPU_vector);

        if (

            (CPUtotalTime_Idle_Running > 495 && CPUtotalTime_Idle_Running < 505)

            || (CPUtotalTime_Idle_Running > 9995 && CPUtotalTime_Idle_Running < 10005)  //use these ranges to get at or close to 500 time units and 10,000 time units

            || (counter_JobsCompleted_Total == totalJobs_inCurrLoadedDatFile) //output final table


            )
        {
            //OUTPUT CURRENT METRICS
            cout << "\n------------------------------------------------------------------------------";
            cout << "\nClockManagement--CYCLE NUMBER--: <" << counter_ClockManager_TimeUnit << ">";
            cout << "\nNumber of processor(s) being used : <" << size_of_CPU_vec << ">";
            cout << "\nCurrent total queue size : <" << CPU_C.getSum_allJobsInQueue_CPUs(CPU_vector) << ">";
            cout << "\nAverage CPU_queue size : <" << CPU_C.getCurrAverage_CPUs_queueSize(CPU_vector) << ">";
            cout << "\nMaximum jobs in one CPU_queue : <" << CPU_C.get_MaxJobs_inQueue(CPU_vector) << ">";
            cout << "\nAverage time in CPU_queue : <" << CPU_C.getTotalAverage_TimeJobsInQueue_CPUs(CPU_vector) << ">" << " time_units";
            cout << "\nTotal time jobs in CPU_queue : <" << CPU_C.getSum_totalTimeJobsInQueue_CPUs(CPU_vector) << ">" << " time_units" << endl;
            cout << "\nTotal number of jobs A arrived : <" << RFF.get_TotalArrivals_A() << ">";
            cout << "\nTotal number of jobs B arrived : <" << RFF.get_TotalArrivals_B() << ">";
            cout << "\nTotal number of jobs C arrived : <" << RFF.get_TotalArrivals_C() << ">";
            cout << "\nTotal number of jobs arrived : <" << RFF.get_totalArrivals() << ">" << endl;
            cout << "\nTotal number of jobs A completed : <" << CPU_C.getSum_allJobsCompleted_CPUs_A(CPU_vector) << ">";
            cout << "\nTotal number of jobs B completed : <" << CPU_C.getSum_allJobsCompleted_CPUs_B(CPU_vector) << ">";
            cout << "\nTotal number of jobs C completed : <" << CPU_C.getSum_allJobsCompleted_CPUs_C(CPU_vector) << ">";
            cout << "\nTotal jobs completed : <" << CPU_C.getSum_allJobsCompleted_CPUs(CPU_vector) << ">" << endl;
            cout << "\nTotal time CPU(s) were processing : <" << CPU_C.getSum_totalTimeProcessing_CPUs(CPU_vector) << ">" << " time_units";
            cout << "\nTotal time CPU(s) were idle : <" << CPU_C.getSum_totalIdleTime_CPUs(CPU_vector) << ">" << " time_units";
            cout << "\nTotal time CPU(s) time_Idle + time_Running = Total CPU time : <" << CPU_C.getSum_total_Run_Idle_time(CPU_vector) << ">" << " time_units";
            cout << "\nProcessing time to Idle time Ratio --> ProcessTime:Idle time --> PT/IT = " //use this information to determine the growth or decay of this ratio --> we can compare ratio size at certain job completetion levels for diff num of CPUs
                << CPU_C.getSum_totalTimeProcessing_CPUs(CPU_vector) << "/" << CPU_C.getSum_totalIdleTime_CPUs(CPU_vector) << " = ";
            if (CPU_C.getSum_totalIdleTime_CPUs(CPU_vector) != 0) {

                cout << (double)(CPU_C.getSum_totalTimeProcessing_CPUs(CPU_vector)) / (double)(CPU_C.getSum_totalIdleTime_CPUs(CPU_vector)); //use type casting since int/int will not give you remainder or any ratio less than 1
            }
            else { cout << "~undetermined~ --> divide by 0"; } //catch divide by 0 case
            cout << "\n+++++++++++++++++++++---------------------------------++++++++++++++++++++++++";
            cout << "\n------------------------------------------------------------------------------";


            system("pause");
        }




        //LOG FILE OUTPUT INFORMATION
        LogFileStream << "\nClockManagement Cycle Time " << counter_ClockManager_TimeUnit << ": ";
        for (counter_logFile = 0; counter_logFile < size_of_CPU_vec; counter_logFile++) {

            LogFileStream << endl;
            LogFileStream << "CPU " << counter_logFile << ":: Queue: " << CPU_vector.at(counter_logFile).get_CPU_JobQueue_size()
                << "; Idle Time: " << CPU_vector.at(counter_logFile).get_IDLETIME()
                << "; Processing Time: " << CPU_vector.at(counter_logFile).get_RUNTIME()
                << "; Current Job >Type: " << CPU_vector.at(counter_logFile).get_CurrJob_Processing().jobType
                << "; >ArrivalTime: " << CPU_vector.at(counter_logFile).get_CurrJob_Processing().arrivalTime
                << "; >RemainingProcessTime: " << CPU_vector.at(counter_logFile).get_CurrJob_Processing().processingTime;
        }

        //LOG FILE OUTPUT METRICS TO LOG FILE
        if (

            (CPUtotalTime_Idle_Running > 495 && CPUtotalTime_Idle_Running < 505)

            || (CPUtotalTime_Idle_Running > 9995 && CPUtotalTime_Idle_Running < 10005)  //use these ranges to get at or close to 500 time units and 10,000 time units

            || (counter_JobsCompleted_Total == totalJobs_inCurrLoadedDatFile) //output final table


            )
        {
            LogFileStream << "\n------------------------------------------------------------------------------";
            LogFileStream << "\nClockManagement--CYCLE NUMBER--: <" << counter_ClockManager_TimeUnit << ">";
            LogFileStream << "\nNumber of processor(s) being used : <" << size_of_CPU_vec << ">";
            LogFileStream << "\nCurrent total queue size : <" << CPU_C.getSum_allJobsInQueue_CPUs(CPU_vector) << ">";
            LogFileStream << "\nAverage CPU_queue size : <" << CPU_C.getCurrAverage_CPUs_queueSize(CPU_vector) << ">";
            LogFileStream << "\nMaximum jobs in one CPU_queue : <" << CPU_C.get_MaxJobs_inQueue(CPU_vector) << ">";
            LogFileStream << "\nAverage time in CPU_queue : <" << CPU_C.getTotalAverage_TimeJobsInQueue_CPUs(CPU_vector) << ">" << " time_units";
            LogFileStream << "\nTotal time jobs in CPU_queue : <" << CPU_C.getSum_totalTimeJobsInQueue_CPUs(CPU_vector) << ">" << " time_units" << endl;
            LogFileStream << "\nTotal number of jobs A arrived : <" << RFF.get_TotalArrivals_A() << ">";
            LogFileStream << "\nTotal number of jobs B arrived : <" << RFF.get_TotalArrivals_B() << ">";
            LogFileStream << "\nTotal number of jobs C arrived : <" << RFF.get_TotalArrivals_C() << ">";
            LogFileStream << "\nTotal number of jobs arrived : <" << RFF.get_totalArrivals() << ">" << endl;
            LogFileStream << "\nTotal number of jobs A completed : <" << CPU_C.getSum_allJobsCompleted_CPUs_A(CPU_vector) << ">";
            LogFileStream << "\nTotal number of jobs B completed : <" << CPU_C.getSum_allJobsCompleted_CPUs_B(CPU_vector) << ">";
            LogFileStream << "\nTotal number of jobs C completed : <" << CPU_C.getSum_allJobsCompleted_CPUs_C(CPU_vector) << ">";
            LogFileStream << "\nTotal jobs completed : <" << CPU_C.getSum_allJobsCompleted_CPUs(CPU_vector) << ">" << endl;
            LogFileStream << "\nTotal time CPU(s) were processing : <" << CPU_C.getSum_totalTimeProcessing_CPUs(CPU_vector) << ">" << " time_units";
            LogFileStream << "\nTotal time CPU(s) were idle : <" << CPU_C.getSum_totalIdleTime_CPUs(CPU_vector) << ">" << " time_units";
            LogFileStream << "\nTotal time CPU(s) time_Idle + time_Running = Total CPU time : <" << CPU_C.getSum_total_Run_Idle_time(CPU_vector) << ">" << " time_units";
            LogFileStream << "\nProcessing time to Idle time Ratio --> ProcessTime:Idle time --> PT/IT = " //use this information to determine the growth or decay of this ratio --> we can compare ratio size at certain job completetion levels for diff num of CPUs
                << CPU_C.getSum_totalTimeProcessing_CPUs(CPU_vector) << "/" << CPU_C.getSum_totalIdleTime_CPUs(CPU_vector) << " = ";
            if (CPU_C.getSum_totalIdleTime_CPUs(CPU_vector) != 0) {

                LogFileStream << (double)(CPU_C.getSum_totalTimeProcessing_CPUs(CPU_vector)) / (double)(CPU_C.getSum_totalIdleTime_CPUs(CPU_vector)); //use type casting since int/int will not give you remainder or any ratio less than 1
            }
            else { LogFileStream << "~undetermined~ --> divide by 0"; } //catch divide by 0 case
            LogFileStream << "\n+++++++++++++++++++++---------------------------------++++++++++++++++++++++++";
            LogFileStream << "\n------------------------------------------------------------------------------";

        }
    }
    LogFileStream.clear();
    LogFileStream.close(); //clear and close the file stream when program finishes execution
    
    cout << "\n\n~All jobs processed__ExitingProgram__Thank You...";
    system("pause");

    return 0;


}









/* //this block is used for testing only***
   JobType_ABC testJob;
   ifstream testStream("JobDatabase.dat", ios::in | ios::binary);
   if (!testStream.is_open()) {
       cout << "\nunable to open 'JobDatabase.dat' file.\n";
   }
   else { cout << "\n~Random Access File 'JobDatabase.dat' opened successfully~\n"; }
   testStream.seekg(4149*JobType_ABC_ByteSize, ios::beg);
   testStream.read(reinterpret_cast<char*>(&testJob), JobType_ABC_ByteSize);
   cout << endl <<  testJob.arrivalTime << endl;
   cout << testStream.eof() << endl;
   testStream.close();
   */