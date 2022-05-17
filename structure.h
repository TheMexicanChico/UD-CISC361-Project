#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
   char queue[2];
   struct job* next;
}job;

typedef struct request {
   int timeStamp;
   int jobID;
   int devices;
}request;

typedef struct release {
   int timeStamp;
   int jobID;
   int devices; 
}release;

void initialize_config(config c[], int size);
void initialize_Job(job c[], int size);
void initialize_request(request c[], int size);
void initialize_release(release c[], int size);