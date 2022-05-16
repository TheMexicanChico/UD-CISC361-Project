#include "shortestjobfirst.h"

/* 
Sources & References
MergeSort for Linked Lists 1: https://www.geeksforgeeks.org/merge-sort-for-linked-list/
MergeSort for Linked Lists 2: https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
MergeSort in Python: https://www.educative.io/edpresso/merge-sort-in-python
Find Length of Linked Lists: https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
Append to Linked List: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
*/

JobRef* headRef = malloc(sizeof(JobRef));
headRef = NULL;
JobRef* jobList = malloc(sizeof(JobRef));

void list_length(JobRef* head) {
    // find the length of a given linked list

    int length = 0;
    JobRef* current = head;

    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

void split_list(JobRef* jobList, JobRef** headHalf, JobRef** tailHalf) { // TODO
    // split the linked list
    
    JobRef* splitX = malloc(sizeof(JobRef));
    JobRef* splitY = malloc(sizeof(JobRef));
    
    splitX = jobList;
    splitY = jobList->next;

    // find the midpoint of the list
    while (splitY) {
        splitY = splitY->next;
        if (splitY) {
            splitX = splitX->next;
            splitY = splitY->next;
        }
    }
    // if the list has an odd length, the extra element goes in the first list
    int listLen = list_length(jobList);
    if (listLen % 2 != 0) {
        splitX = splitX->next;
    }
    
    // headHalf has access from head to midpoint
    *headHalf = jobList;
    // tailHalf has access from midpoint to tail
    *tailHalf = splitX->next;
    // cutoff the head from the tail
    splitX->next = NULL;
}

JobRef* merge_queue(JobRef* listX, JobRef* listY) {
    // recursively sort the lists by burst time
    
    JobRef* smallerBurst = malloc(sizeof(JobRef));

    // if either node is NULL, return the other
	if (!listX) 
		return (listY); 
	else if (!listY) 
		return (listX); 

    // grab the table IDs of the jobs
    int jobX = listX->tableID;
    int jobY = listY->tableID;

	// recursively merging two lists
	if (JobTable[jobX][4] <= JobTable[jobY][4]) {
		smallerBurst = listX; 
		smallerBurst->next = MergeSortedList(listX->next, listY); 
	} 
	else { 
		smallerBurst = listY; 
		smallerBurst->next = MergeSortedList(listX, listY->next); 
	} 
	return smallerBurst;
}

void sort_queue(JobRef** jobList) { 
    // sort the linked list with MergeSort

	if (!(*jobList) || !(*jobList->next)) { 
		return; 
	} 

    JobRef* headHalf = malloc(sizeof(JobRef));
    JobRef* tailHalf = malloc(sizeof(JobRef));

    // split the list
    split_list(*jobList, &headHalf, &tailHalf);

    // recursively sort the two lists
    sort_queue(&headHalf);
    sort_queue(&tailHalf);

    *jobList = merge_queue(headHalf, tailHalf);
}

void sjf_hold_queue(JobRef* currentJob, int initialized) {
    // create, append to, and sort the hold queue

    if (!headRef) {
        jobList = currentJob;
    } else {
        headRef = jobList;
        while (jobList->next) {
            jobList = jobList->next;
        }
        jobList->next = currentJob;
        jobList = headRef;
        sort_queue(&jobList);
    }
}
