#include "firstinout.h"

/* 
Sources & References
Append to Linked List: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
*/

JobRef* headRef = malloc(sizeof(JobRef));
headRef = NULL;
JobRef* jobList = malloc(sizeof(JobRef));

void fifo_hold_queue(JobRef* currentJob, int initialized) {
    // create and append to the hold queue

    if (!headRef) {
        jobList = currentJob;
    } else {
        headRef = jobList;
        while (jobList->next) {
            jobList = jobList->next;
        }
        jobList->next = currentJob;
        jobList = headRef;
    }
}
