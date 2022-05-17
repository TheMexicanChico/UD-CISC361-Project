#ifndef SHORTESTJOBFIRST_H
#define SHORTESTJOBFIRST_H
#include "structure.h"

int list_length(job* head);
void split_list(job* jobList, job** headHalf, job** tailHalf);
job* merge_queue(job* listX, job* listY);
void sort_queue(job* jobList);
job* sjf_hold_queue(job* currentJob);

#endif // SHORTESTJOBFIRST_H
