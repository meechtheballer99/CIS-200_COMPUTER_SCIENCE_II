



#ifndef CPU_CONTROLLER_H
#define CPU_CONTROLLER_H
#include "CPU.h"

class CPU_Controller :
    private CPU //use this derived class as a CPU controller in order to perform functions on the CPU objects --> this way we can keep our MAIN nice and clean and easy to follow/read and leave the messy functions in this class
    //use the private filter since we only want this class to have access to the protected and public members of its base class --> that means you cannot declare an object of this class and access any of the derived classes attributes
{

private: 

    int lastRecorded_smallestJobQ_value = 0; //store the last smallest value recorded from the findSmallest function --> that way the function will finish execution faster if we can keep track of the most recent smallest value
    int CPUsize = 0; //use this varibale to store the size of the CPU vector so that we dont have to call the vector.size function everytime we need the size of it to use it in this class's functions
    

public:

    int findSmallest_CPUjobQueue(vector<CPU>& CPU_Vec); //use this function as a search algorithm to find the CPU with the smallest jobQueue so that when jobs are added to the CPU they can be added most efficiently //will use binary search algorithm
    void all_CPUs_process_Job(vector<CPU>& CPU_Vec); //this CPU_Controller function will cause all processcors in the CPU_vec from main to run a process on their job --> each processor will decrement jobs if they have one
    void addJobFrom_arrivalQ_to_CPU(vector<JobType_ABC>& ArrivalQ,vector<CPU>& CPU_Vec, int& CPU_ElementNumber); //use this function to add jobs from arrival queue vector to the sepecified CPU


    void set_CPUsize(int size);
    int get_CPUsize(void);
    int getSum_allJobsInQueue_CPUs(vector<CPU>& CPU_Vec); //use this function to get (current queue size) the summation of the number of jobs on all the job Queues of all CPU units in the CPU vector
    int getSum_allJobsCompleted_CPUs(vector<CPU>& CPU_Vec); //use this function to get the summation of the number of jobs completed of all CPU units in the CPU vector
    int getSum_allJobsCompleted_CPUs_A(vector<CPU>& CPU_Vec); //use this function to get the summation of the number of jobs completed of all CPU units in the CPU vector for job type A
    int getSum_allJobsCompleted_CPUs_B(vector<CPU>& CPU_Vec); //use this function to get the summation of the number of jobs completed of all CPU units in the CPU vector for job type B
    int getSum_allJobsCompleted_CPUs_C(vector<CPU>& CPU_Vec); //use this function to get the summation of the number of jobs completed of all CPU units in the CPU vector for job type C
    int getSum_totalTimeJobsInQueue_CPUs(vector<CPU>& CPU_Vec); //use this function to get the summation of total time of jobs in job queue of all CPU units in the CPU vector
    int getSum_totalAmount_JobsHeldInQueue_CPUs(vector<CPU>& CPU_Vec); //use this function to get the summation of the total number of jobs that was held in the job queue for all CPUs in the CPU vector
    int getSum_totalTimeProcessing_CPUs(vector<CPU>& CPU_Vec); //use this function to get the summation of total time jobs were being processed of all CPU units in the CPU vector
    int getSum_totalIdleTime_CPUs(vector<CPU>& CPU_Vec); //use this function to get the summation of total time idle time of all CPU units in the CPU vector
    int getSum_total_Run_Idle_time(vector<CPU>& CPU_Vec); //use this function to get the summation of both all idle and all processing time of all CPUs
    int getTotalAverage_TimeJobsInQueue_CPUs(vector<CPU>& CPU_Vec); //get the total average time of jobs in queue for all CPUs
    int getCurrAverage_CPUs_queueSize(vector<CPU>& CPU_Vec); //use this function to find the current average size of the job queues of all processors
    int get_All_CPUs_inUse(vector<CPU>& CPU_Vec); //use this to return the total number of CPUs currently processing a job
    int get_MaxJobs_inQueue(vector<CPU>& CPU_Vec); //returns the largest CPU queue size recorded during duration of the program --> this means that this function will find the CPU that has the largest max_queue value
    int getSum_MaxJobs_inQueue(vector<CPU>& CPU_Vec); // use this to return the sum of all max jobs from all CPUs

};



#endif //