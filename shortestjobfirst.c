#include "shortestjobfirst.h"

/* 
Sources & References
MergeSort for Linked Lists 1: https://www.geeksforgeeks.org/merge-sort-for-linked-list/
MergeSort for Linked Lists 2: https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
MergeSort in Python: https://www.educative.io/edpresso/merge-sort-in-python
Find Length of Linked Lists: https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
Append to Linked List: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
*/

job* sjfHeadRef = NULL;
job* sjfQueue = NULL;

int list_length(job* head) {
    // find the length of a given linked list

    int length = 0;
    job* current = head;

    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

void split_list(job* sjfQueue, job** headHalf, job** tailHalf) { // TODO
    // split the linked list
    
    job* splitX = sjfQueue;
    job* splitY = sjfQueue->next;
    
    // find the midpoint of the list 
    //^ Y incremented twice, X incremented once
    //^ X stops at midpoint (or one before it for odd length)
    while (splitY) {
        splitY = splitY->next;
        if (splitY) {
            splitX = splitX->next;
            splitY = splitY->next;
        }
    }
    // if the list has an odd length, the extra element goes in the first list
    int listLen = list_length(sjfQueue);
    if (listLen % 2 != 0) {
        splitX = splitX->next;
    }
    
    // headHalf has access from head to midpoint
    *headHalf = sjfQueue;
    // tailHalf has access from midpoint to tail
    *tailHalf = splitX->next;
    // cutoff the head from the tail
    splitX->next = NULL;
}

job* merge_queue(job* jobX, job* jobY) {
    // recursively sort the lists by burst time
    
    job* shorterJob;

    // if either node is NULL, return the other
	if (!jobX) {
        return (jobY); 
    } else if (!jobY) {
		return (jobX); 
    }

    // recursively merging two lists based on burst time
	if (jobX->burstTime <= jobY->burstTime) {
		shorterJob = jobX; 
		shorterJob->next = merge_queue(jobX->next, jobY); 
	} else { 
		shorterJob = jobY; 
		shorterJob->next = merge_queue(jobX, jobY->next); 
	} 
	return shorterJob;
}

void sort_queue(job* sjfQueue) { 
    // sort the linked list with MergeSort

    // cannot sort less than two nodes
	if (!(sjfQueue) || !(sjfQueue->next)) { 
		return; 
	} 

    job* headHalf;
    job* tailHalf;

    // split the list
    split_list(sjfQueue, &headHalf, &tailHalf);

    // recursively sort the two lists
    sort_queue(headHalf);
    sort_queue(tailHalf);

    sjfQueue = merge_queue(headHalf, tailHalf);
}

job* sjf_hold_queue(job* currentJob) {
    // create, append to, and sort the hold queue

    // make sure the job is not connected to anything
    currentJob->next = NULL;
    // 72 = H for holding queue
    currentJob->queue = 72;
    
    if (!sjfHeadRef) {
        sjfQueue = currentJob;
    } else if (!sjfQueue->next) {
        sjfQueue->next = currentJob;
    } else {
        sjfHeadRef = sjfQueue;
        while (sjfQueue->next) {
            sjfQueue = sjfQueue->next;
        }
        sjfQueue->next = currentJob;
        sjfQueue = sjfHeadRef;
        sort_queue(sjfQueue);
    }
    return sjfQueue;
}
