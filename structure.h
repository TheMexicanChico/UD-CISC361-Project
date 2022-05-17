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
/*
typedef struct request {
   int timeStamp;
   int jobID;
   int devices;
   struct request* next;
}request;

typedef struct release {
   int timeStamp;
   int memory;
   int jobID;
   int devices; 
   struct release* next;
}release;
*/
void initialize_config(config* head, int size);
void initialize_Job(job* head, int size);
void initialize_request(request* head, int size);
void initialize_release(release* head, int size);