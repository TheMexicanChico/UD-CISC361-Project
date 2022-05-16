#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct JobRef {
    int tableID;
    struct JobRef *head;
    struct JobRef *tail;
    struct JobRef *next;
}JobRef;

void initialize_queue();
void split_queue(struct JobRef *jobList, int listLen);
void hold_queue(struct JobRef *current_job);