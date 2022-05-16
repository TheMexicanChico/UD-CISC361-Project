#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct JobRef {
    int tableID;
    struct JobRef* next;
}JobRef;

void fifo_hold_queue(JobRef* currentJob);
