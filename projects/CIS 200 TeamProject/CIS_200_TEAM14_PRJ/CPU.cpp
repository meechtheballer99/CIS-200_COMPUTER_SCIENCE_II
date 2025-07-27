
//CPU CLASS HEADER FILE

#include "CPU.h"


void CPU::process_Job(void){ //special note: remember to use the private data members -- don't use set and get methods within the class since it is easier for the program to access the class members rather than call another function


	if (CPU_status_isEmpty == true && CPU_jobQ_status_isEmpty == true && currentJob.jobType == nullchar) { // CPU is idle; so increment idle clock and total idle time

		clock_CPU_IDLE++;
		totalIdleTime++;
		return; //exit function --> no need to check below statements and waste execution time since there is nothing on the processor or in the job queue
	}
	if(CPU_status_isEmpty == true && CPU_jobQ_status_isEmpty == false && currentJob.jobType == nullchar){ //enter this statement if the CPU is currently processing nothing --> get a new job and place it on processor from job q
	
		currentJob = CPUjobQueue_vector.at(CPUjobQueue_vector.size() - 1); //get the last element from the vector since we set the add_to_jobq function to add the newest arrivals to the front of the vector //-1 since size of vector included 0
		CPUjobQueue_vector.pop_back(); //delete job from the queue
		currentJobQueue_size--; //decrement job q size since we've added one to the CPU for processing
		if(currentJobQueue_size == 0) { CPU_jobQ_status_isEmpty = true; } //check to see if after taking the job from job Q if the job Q is now empty --> if it is then set the status to empty= true
		CPU_status_isEmpty = false; //job will be placed on the processor; thus, cpu is not empty/free
	}

	if (currentJob.processingTime != 0) { //use this loop as long as there is a job on the processcor --> processingTime != 0
		currentJob.processingTime--; //decrement the process time of the current job that the CPU is processing
		clock_CPU_RUNTIME++; //increment the runtime since the another job's processing unit has been processed by 1 time unit
		totalRunTime++; //increment total runtime
		clock_CPU_IDLE = 0; //ensure that since a process has been completed on the processcor that idle time is at 0
	}
	if (currentJob.processingTime == 0 && currentJob.jobType != nullchar) { //execute this loop when processing time of a valid job reaches 0 --> now the job is finished processing
		
		if (currentJob.jobType == 'A') { totalJobsCompleted_A++; }
		if (currentJob.jobType == 'B') { totalJobsCompleted_B++; } //use these 3 statments to track job types completed
		if (currentJob.jobType == 'C') { totalJobsCompleted_C++; }

		CPU_status_isEmpty = true; //change status of CPU to empty state if the current job reaches 0 for processing time (thus it is done processing)
		currentJob = { nullchar, 0, 0 }; //use this to reset the job to empty Job since the current job has now been fully processed
		jobsCompleted++; //increment number of jobs completed by this CPU object
		clock_CPU_RUNTIME = 0; //reset runtime clock timer

	} 
	if (CPU_jobQ_status_isEmpty == false) { //use this to check and track the time jobs are in job Q --> do this after every time a job is processed

		totalTime_JobsInQ++;
		if (currentJobQueue_size > JobQ_maxsize) { JobQ_maxsize = currentJobQueue_size; } //use this to keep track of largest job Q recorded during the running program --> if size of q is 0, no need to execute this loop which is why we placed it inside of the outer if loop

	}

}
bool CPU::isCPU_status_Idle(void){

	if (CPU_status_isEmpty == true) {	return true;}
	else { return false; }

}
bool CPU::isCPU_jobQ_status_Empty(void){

	if (CPU_jobQ_status_isEmpty == true) { return true; }
	else { return false; }

}


int CPU::get_RUNTIME(void) { return clock_CPU_RUNTIME; }
int CPU::get_IDLETIME(void) { return clock_CPU_IDLE; }
int CPU::get_JobsCompleted(void) { return jobsCompleted; }
int CPU::get_CPU_JobQueue_size(void) { return currentJobQueue_size; }
int CPU::get_totalRUNTIME(void) { return totalRunTime; }
int CPU::get_totalIDLETIME(void) { return totalIdleTime; }
int CPU::get_totalTime_JobsInQ(void) { return totalTime_JobsInQ; }
int CPU::get_totalJobs_HeldInQ(void) { return totalJobs_held_InQueue; }
int CPU::get_avgTime_JobsInQ(void) { 
	
	if (totalJobs_held_InQueue == 0) { return 0; } //catch divide by 0 case
	
	return (totalTime_JobsInQ / totalJobs_held_InQueue); 
} 
int CPU::get_JobQ_maxsize(void) { return JobQ_maxsize; }
int CPU::get_totalJobsCompleted_A(void) { return totalJobsCompleted_A; }
int CPU::get_totalJobsCompleted_B(void) { return totalJobsCompleted_B; }
int CPU::get_totalJobsCompleted_C(void) { return totalJobsCompleted_C; }
JobType_ABC CPU::get_CurrJob_Processing(void) { return currentJob; }
void CPU::add_JobToQueue(JobType_ABC JobToAdd) {

	CPUjobQueue_vector.insert(CPUjobQueue_vector.begin(), JobToAdd); //add the new job at the beginning of the job queue (at the front of the vector) //in this way the oldest (first to enter queue) jobs added to the vector will be processed first 
																	 //by doing this we can also take advantage of the pop_back function of the vector class since jobs at the end of the vector are taken out first when sent to CPU
	
	if (CPU_status_isEmpty == true && CPU_jobQ_status_isEmpty == true && currentJob.jobType == nullchar) { //enter this statement if the CPU is currently processing nothing

		currentJob = CPUjobQueue_vector.at(CPUjobQueue_vector.size() - 1); //get the last element from the vector since we set the add_to_jobq function to add the newest arrivals to the front of the vector //-1 since size of vector includes 0
		CPUjobQueue_vector.pop_back(); //delete job from the queue
		CPU_status_isEmpty = false; //job will be placed on the processor; thus, cpu is not empty/free
		return; //exit funcion --> nothing else to do if this if-statment executes
	}

	totalJobs_held_InQueue++; //number of jobs held in queue is incremented --> need this metric to help calculate average queue time == totaltime jobs in que / total jobs held in queue
	currentJobQueue_size++; //increment current job queue size 
	totalTime_JobsInQ++; //increment the total job q time since not all jobs made it out of the queue and into the processor if you get past the above if-statement in this function
	CPU_jobQ_status_isEmpty = false;

}
