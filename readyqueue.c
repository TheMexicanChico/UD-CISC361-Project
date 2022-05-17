#include "structure.h"

// getting node from the hold queues, wait queue, or CPU
job* headRef = NULL;
job* readyQueue = NULL;

job* ready_queue(job* currentJob) {

    // make sure the job is not connected to anything
    currentJob->next = NULL;
    
    if (!headRef) {
        readyQueue = currentJob;
    } else if (!readyQueue->next) {
        readyQueue->next = currentJob;
    } else {
        headRef = readyQueue;
        while (readyQueue->next) {
            readyQueue = readyQueue->next;
        }
        readyQueue->next = currentJob;
        readyQueue = headRef;
    }
    return readyQueue;
}
