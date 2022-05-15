#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "firstinout.h"
#include "structure.h"

// First in, First Out (FIFO)
struct JobRef *jobList;
struct JobRef *sortX;
struct JobRef *sortY;

void initialize_queue() {
    jobList = malloc(sizeof(*jobList));
    jobList->head = jobList;
    jobList->tail = jobList;
    jobList->next = NULL;
}

void split_queue(struct JobRef *jobList, int listLen) {
    sortX = malloc(sizeof(*sortX));
    sortY = malloc(sizeof(*sortY));
    
    if (listLen % 2 == 0) {
        sortX->head = jobList->head;
        for (int i = 0; i < listLen/2; i++) {
            sortX;
        }
        for (int j = listLen/2; j < listLen; j++) {
            
        }
    } else {
        // odd lengths 
    }
}

void hold_queue(struct JobRef *current_job) {
    int listLen = 1;
    if (jobList->head == NULL) {
        initialize_queue(jobList);
    } else {
        listLen++;
        // current_job->tableID->current_queue = 'H';
        jobList->tail->next = current_job;
        current_job->tail = current_job;
        sort_queue(jobList, listLen);
    }
}
