
//CPU CLASS CPP FILE
//D Johnson 
//J Fang
//12-6-2020

#ifndef CPU_H
#define CPU_H
#define nullchar '\0' ///define nullchar character for easy use in program
#include "JobType_ABC.h"
#include <vector>


using namespace std;
class CPU{

protected: //set to protected so that only the CPU_Controller class can access these data members

	vector<JobType_ABC> CPUjobQueue_vector{}; //use this jobQ_vector to store jobs while the processor is in use currently processing a job //initialize vector to size 0
	JobType_ABC currentJob = { nullchar, 0, 0 }; //use this to store the data of the current job that the CPU is working on, initialize it to an empty job
	int currentJobQueue_size = 0; //use this to store/edit/easily recall the current size of the jobQ of the CPU unit (object)
	int clock_CPU_IDLE = 0; //track idle time units of CPU using this clock timer --> need to keep track of this for the log file
	int clock_CPU_RUNTIME = 0; //track the run time units of CPU using this clock timer --> need to keep track of this for the log file
	bool CPU_status_isEmpty = true; //initialzie this variable to true since by default CPU status will start with no jobs; thus it is in the ready state
	bool CPU_jobQ_status_isEmpty = true; //track the status of job q
	int jobsCompleted = 0; //will be used to keep track of the number of jobs completed by the CPU 
	int totalRunTime = 0; //keep track of total processing time of the CPU
	int totalIdleTime = 0; //keep track of total idle time of CPU
	int totalTime_JobsInQ = 0; //track total time jobs are in the job q
	int totalJobs_held_InQueue = 0; //track total number of jobs that got sent and held in the job queue --> need this metric to calculate average time jobs were in queue
	int JobQ_maxsize = 0; //keep track of the largest Job Q on the CPU
	int totalJobsCompleted_A = 0;
	int totalJobsCompleted_B = 0; //keep track of A B and C jobs completed 
	int totalJobsCompleted_C = 0;

public: 

	void process_Job(void);
	bool isCPU_status_Idle(void); //use this function to check if CPU is idle/empty and clear (from private CPU_status data member) and ready for another job --> returns 1 (true) if it is empty, 0 (false) if it is not empty
	bool isCPU_jobQ_status_Empty(void);
	int get_RUNTIME(void);
	int get_IDLETIME(void);
	int get_JobsCompleted(void);
	int get_CPU_JobQueue_size(void);
	int get_totalRUNTIME(void);
	int get_totalIDLETIME(void);
	int get_totalTime_JobsInQ(void);
	int get_totalJobs_HeldInQ(void); 
	int get_avgTime_JobsInQ(void); // == total job queue time / total number of jobs that went to the queue --> this will give you average time jobs were in queue (also known as wait time, or queue time)
	int get_JobQ_maxsize(void);
	int get_totalJobsCompleted_A(void);
	int get_totalJobsCompleted_B(void);
	int get_totalJobsCompleted_C(void);

	JobType_ABC get_CurrJob_Processing(void);
	void add_JobToQueue(JobType_ABC JobToAdd); //this function will add jobs to the job queue --> if processor is empty and the job queue is empty, then the job will automatically be placed on the processor
	//void set_IDLETIME(int time);
	//void set_JobsCompleted(int setJobsCompleted);
	//void set_CPU_JobQueue_size(int setQ_size);
	



};


#endif 