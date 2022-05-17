#include "structure.h"

// getting node from the hold queues, wait queue, or CPU
job* readyHeadRef = NULL;
job* readyQueue = NULL;

job* ready_queue(job* currentJob) {

    // make sure the job is not connected to anything
    currentJob->next = NULL;
    // 82 = R for ready queue
    currentJob->queue = 82;
    
    if (!readyHeadRef) {
        readyQueue = currentJob;
    } else if (!readyQueue->next) {
        readyQueue->next = currentJob;
    } else {
        readyHeadRef = readyQueue;
        while (readyQueue->next) {
            readyQueue = readyQueue->next;
        }
        readyQueue->next = currentJob;
        readyQueue = readyHeadRef;
    }
    return readyQueue;
}
