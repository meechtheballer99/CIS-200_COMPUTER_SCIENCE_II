


//CPU_Controller class CPP file

#include "CPU_Controller.h"




int CPU_Controller::findSmallest_CPUjobQueue(vector<CPU>& CPU_Vec) { //will use a 1-time binary split search to find smallest value //if program runs too slow we can easily add more binary splits
	//use this function to return the element (CPU number) with the smallest job Queue, while also setting the last_recordedSmallest Job queue data member equal to the smallest value to keep track and use in other functions
	
	int lowerElements_searchRange = 0; //use this to search the lower half of the vector during binary search
	int upperElements_searchRange = 0; //use this int to search the upper half of the vector during binary search
	
	//in the below 2 stamenets we will do a binary split and then proceed to search for the lowest value in each half of the CPU vector seprately 

	lowerElements_searchRange = CPUsize / 2; //lower range is the 1st half of the CPUs in the CPU vector
	upperElements_searchRange = CPUsize - lowerElements_searchRange; //upper range is the last half of the CPUs in the CPU vector --> CPUsize - lowerRange == start of 2nd half of the CPU vector
	
	int i = 0;
	int j = upperElements_searchRange; //use these 2 variables for the for-loops

	while (true) { //execute this while loop until a smallest value is found --> upon finding smallest value, one of the for-loops inside of this loop will return and thus exit this funciton 
		for (i = 0; i <= lowerElements_searchRange; i++) { //search the lower elements (lower CPU elements in the CPU vector) for the smallest job queue value //has to be less than or equal to to include that final lower half value

			if (CPU_Vec.at(i).get_CPU_JobQueue_size() < lastRecorded_smallestJobQ_value) {

				lastRecorded_smallestJobQ_value = CPU_Vec.at(i).get_CPU_JobQueue_size(); //set last recorded so that when this function is called again we have a better change of starting closer to the smallest value

				return i; //return the element (CPU number) where the smallest job q value was found
			}


		}

		for (j = upperElements_searchRange; j < CPUsize; j++) { //search the lower elements (lower CPU elements in the CPU vector) for the smallest job queue value

			if (CPU_Vec.at(j).get_CPU_JobQueue_size() < lastRecorded_smallestJobQ_value) {

				lastRecorded_smallestJobQ_value = CPU_Vec.at(j).get_CPU_JobQueue_size(); //set last recorded so that when this function is called again we have a better change of starting closer to the smallest value

				return j; //return the element (CPU number) where the smallest job q value was found
			}


		}

		lastRecorded_smallestJobQ_value++; //this value will increment if neither of the for-loops can find the smallest value; now the last recorded smallest value will be increased to be compared again in the next iteration
	}

}
void CPU_Controller::all_CPUs_process_Job(vector<CPU>& CPU_Vec){

	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		CPU_Vec.at(i).process_Job(); //run all processors in the CPU vector from main by using this function through this loop

	}

}
void CPU_Controller::addJobFrom_arrivalQ_to_CPU(vector<JobType_ABC>& ArrivalQ, vector<CPU>& CPU_Vec, int& CPU_ElementNumber){


	//Special note: jobs added to the arrival q from MAIN were added as: oldest jobs at loewr elements --> newest job at back of vector (upper elements) --> thus jobs added to thequeue when we perform a while loop 
	CPU_Vec.at(CPU_ElementNumber).add_JobToQueue(ArrivalQ.at(ArrivalQ.size() - 1)); //add the job at the end of the ArrivalQ vector to the CPU jobQ --> arrival queue added elements to its queue in --> 0 element == newest job arrival
																					//do the -1 since size of vector includes element 0; ex: size = 5 has elements 0-4; 4 is last element
	
	ArrivalQ.pop_back(); //delete the job at the end of the queue which was just inserted into a CPU

}



void CPU_Controller::set_CPUsize(int size) { CPUsize = size; }
int CPU_Controller::get_CPUsize(void) { return CPUsize; }
int CPU_Controller::getSum_allJobsInQueue_CPUs(vector<CPU>& CPU_Vec) {

	int sum_AllJobs_inQueue = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		sum_AllJobs_inQueue += CPU_Vec.at(i).get_CPU_JobQueue_size(); //go to each CPU during this loop and add its jobQ size to the sum of allJobs variable to find total number of jobs in the job q for all Processors 

	}

	return sum_AllJobs_inQueue;
}
int CPU_Controller::getSum_allJobsCompleted_CPUs(vector<CPU>& CPU_Vec) {

	int sum_AllJobsCompleted = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		sum_AllJobsCompleted += CPU_Vec.at(i).get_JobsCompleted(); //go to each CPU during this loop and add its jobs_completed value to the sum of allJobs variable to find total number of jobs compeleted for all Processors 

	}

	return sum_AllJobsCompleted;

}
int CPU_Controller::getSum_allJobsCompleted_CPUs_A(vector<CPU>& CPU_Vec) {


	int completed = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		completed += CPU_Vec.at(i).get_totalJobsCompleted_A();
	}

	return completed; //return total jobs completed

}
int CPU_Controller::getSum_allJobsCompleted_CPUs_B(vector<CPU>& CPU_Vec) {


	int completed = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		completed += CPU_Vec.at(i).get_totalJobsCompleted_B();
	}

	return completed; //return total jobs completed

}
int CPU_Controller::getSum_allJobsCompleted_CPUs_C(vector<CPU>& CPU_Vec) {


	int completed = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		completed += CPU_Vec.at(i).get_totalJobsCompleted_C();
	}

	return completed; //return total jobs completed

}
int CPU_Controller::getSum_totalTimeJobsInQueue_CPUs(vector<CPU>& CPU_Vec) {

	int totalTime = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		totalTime += CPU_Vec.at(i).get_totalTime_JobsInQ();
	}

	return totalTime; //return total time job queue was occupied

}
int CPU_Controller::getSum_totalAmount_JobsHeldInQueue_CPUs(vector<CPU>& CPU_Vec) {

	int JobsHeld = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		JobsHeld += CPU_Vec.at(i).get_totalJobs_HeldInQ();
	}

	return JobsHeld; //return total jobs held in Q
}
int CPU_Controller::getSum_totalTimeProcessing_CPUs(vector<CPU>& CPU_Vec) {

	int totProcTime = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		totProcTime += CPU_Vec.at(i).get_totalRUNTIME();
	}

	return totProcTime; //return total processing time
}
int CPU_Controller::getSum_totalIdleTime_CPUs(vector<CPU>& CPU_Vec){

	int totIdleTime = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		totIdleTime += CPU_Vec.at(i).get_totalIDLETIME();
	}

	return totIdleTime; //return total idle time


}
int CPU_Controller::getSum_total_Run_Idle_time(vector<CPU>& CPU_Vec) {

	return getSum_totalIdleTime_CPUs(CPU_Vec) + getSum_totalTimeProcessing_CPUs(CPU_Vec);

}
int CPU_Controller::getTotalAverage_TimeJobsInQueue_CPUs(vector<CPU>& CPU_Vec) {

	int totAvg = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		totAvg += CPU_Vec.at(i).get_avgTime_JobsInQ();
	}

	return totAvg; //return total avg wait time


}
int CPU_Controller::getCurrAverage_CPUs_queueSize(vector<CPU>& CPU_Vec){

	return (getSum_allJobsInQueue_CPUs(CPU_Vec) / CPUsize); //return average


}
int CPU_Controller::get_All_CPUs_inUse(vector<CPU>& CPU_Vec) {

	int sum_CPUs_inUse = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		if (CPU_Vec.at(i).isCPU_status_Idle() == false) {//if status is not idle (idle status ==false) then we will enter this if-statement and increment the sum

			sum_CPUs_inUse++; 

		}

	}

	return sum_CPUs_inUse; //return sum of CPUs currently in use


}
int CPU_Controller::get_MaxJobs_inQueue(vector<CPU>& CPU_Vec) {

	int Max_ofAll = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		if (CPU_Vec.at(i).get_JobQ_maxsize() > Max_ofAll) {//compare current max to max of the CPU element of the loop iteration number

			Max_ofAll = CPU_Vec.at(i).get_JobQ_maxsize();

		}

	}

	return Max_ofAll; //return max

}
int CPU_Controller::getSum_MaxJobs_inQueue(vector<CPU>& CPU_Vec){

	int sumMax = 0;
	for (int i = 0; i < CPUsize; i++) { //must make i < size since the CPU vector includes the 0 element in the size

		sumMax += CPU_Vec.at(i).get_JobQ_maxsize();
	}

	return sumMax; //return summed max


}