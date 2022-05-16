#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "structure.h"

typedef struct JobRef {
    int tableID;
    struct JobRef* next;
}JobRef;

int list_length(JobRef* head);
void split_list(JobRef* jobList, JobRef** headHalf, JobRef** tailHalf);
JobRef* merge_queue(int** JobTable, JobRef* listX, JobRef* listY);
void sort_queue(int** JobTable, JobRef* jobList);
void sjf_hold_queue(int** JobTable, JobRef* currentJob);
