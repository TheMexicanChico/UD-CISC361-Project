#include "shortestjobfirst.h"

struct JobRef *jobList;
struct JobRef *sortX;
struct JobRef *sortY;

void initialize_queue() {
    jobList = malloc(sizeof(*jobList));
    jobList->head = jobList;
    jobList->tail = jobList;
    jobList->next = NULL;
}

void sort_queue(struct JobRef *jobList, int listLen) {
    sortX = malloc(sizeof(*sortX));
    sortY = malloc(sizeof(*sortY));
    
    if (listLen % 2 == 0) {
        sortX->head = jobList->head;
        for (int i = 0; i < listLen/2; i++) {
            sortX;
        }
        for (int j = listLen/2; j < listLen; j++) {

        }
    }
}

void hold_queue_sjf(struct JobRef *current_job) {
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
