#include "structure.h"

// getting node from the hold queues, wait queue, or CPU
job* headRef = NULL;
job* waitQueue = NULL;

job* wait_queue(job* currentJob) {

    // make sure the job is not connected to anything
    currentJob->next = NULL;
    
    if (!headRef) {
        waitQueue = currentJob;
    } else if (!waitQueue->next) {
        waitQueue->next = currentJob;
    } else {
        headRef = waitQueue;
        while (waitQueue->next) {
            waitQueue = waitQueue->next;
        }
        waitQueue->next = currentJob;
        waitQueue = headRef;
    }
    return waitQueue;
}
