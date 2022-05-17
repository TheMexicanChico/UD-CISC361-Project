#ifndef BANKER_H
#define BANKER_H

typedef struct JobRef {
    int tableID;
    int devices;
    struct JobRef *head;
    struct JobRef *tail;
    struct JobRef *next;
}JobRef;

void banker(struct JobRef *current_job)

#endif // BANKER_H
