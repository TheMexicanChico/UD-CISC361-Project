#include "firstinout.h"

/* 
Sources & References
Append to Linked List: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
*/

job* fifoHeadRef = NULL;
job* fifoQueue = NULL;

job* fifo_hold_queue(job* currentJob) {
    // create and append to the hold queue

    // make sure the job is not connected to anything
    currentJob->next = NULL;
    // 72 = H for holding queue
    currentJob->queue = 72;
    
    if (!fifoHeadRef) {
        fifoQueue = currentJob;
    } else if (!fifoQueue->next) {
        fifoQueue->next = currentJob;
    } else {
        fifoHeadRef = fifoQueue;
        while (fifoQueue->next) {
            fifoQueue = fifoQueue->next;
        }
        fifoQueue->next = currentJob;
        fifoQueue = fifoHeadRef;
    }
    return fifoQueue;
}
