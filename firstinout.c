#include "firstinout.h"

/* 
Sources & References
Append to Linked List: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
*/

job* headRef = NULL;
job* jobList = NULL;

job* fifo_hold_queue(job* currentJob) {
    // create and append to the hold queue

    // make sure the job is not connected to anything
    currentJob->next = NULL;
    
    if (!headRef) {
        jobList = currentJob;
    } else if (!jobList->next) {
        jobList->next = currentJob;
    } else {
        headRef = jobList;
        while (jobList->next) {
            jobList = jobList->next;
        }
        jobList->next = currentJob;
        jobList = headRef;
    }
    return jobList;
}
