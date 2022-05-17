#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct config {
   int arrivalTime;
   int memory;
   int devices;
   int quantumTime;
}config;

typedef struct job {
   int jobID;
   int arrivalTime;
   int priority;
   int memory;
   int devices;
   int burstTime;
   int queue;
   struct job* next;
}job;

void initialize_config(config* head, int size);
void initialize_Job(job* head, int size);
void initialize_request(job* requestJob, int size);
void initialize_release(job* releaseJob, int size);

#endif // STRUCTURE_H
