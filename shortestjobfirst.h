#ifndef SHORTESTJOBFIRST_H
#define SHORTESTJOBFIRST_H

int list_length(job* head);
void split_list(job* sjfQueue, job** headHalf, job** tailHalf);
job* merge_queue(job* listX, job* listY);
void sort_queue(job* sjfQueue);
job* sjf_hold_queue(job* currentJob);

#endif // SHORTESTJOBFIRST_H
