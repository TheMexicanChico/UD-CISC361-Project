#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct JobRef {
    int tableID;
    int devices;
    struct JobRef *head;
    struct JobRef *tail;
    struct JobRef *next;
}JobRef;

void banker(struct JobRef *current_job)