#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "structure.h"

int list_length(job* head);
void split_list(job* jobList, job** headHalf, job** tailHalf);
job* merge_queue(int** JobTable, job* listX, job* listY);
void sort_queue(int** JobTable, job* jobList);
void sjf_hold_queue(int** JobTable, job* currentJob);
