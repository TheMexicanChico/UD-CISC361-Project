#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct JobRef {
    int tableID;
    struct JobRef* next;
}JobRef;

void list_length(JobRef* head);
void split_list(JobRef* jobList, JobRef** headHalf, JobRef** tailHalf);
JobRef* merge_queue(JobRef* listX, JobRef* listY);
void sort_queue(JobRef** jobList);
void sjf_hold_queue(JobRef* currentJob);
