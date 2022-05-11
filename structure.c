#include <stdio.h>
#include <limits.h>
#include "structure.h"


typedef struct config {
   int arrivalTime;
   int memory;
   int devices;
   int quantumTime;
}config;

typedef struct job {
   int jobID;
   int priority;
   int arrivalTime;
   int memory;
   int devices;
   int runTime;
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

// Sample code, not done yet [Just an idea]
void initialize_config(config c[], int size) {
   for(int i=0; i<size; i++){
       c[i].arrivalTime=0;
       c[i].memory=0;
       c[i].devices=0;
       c[i].quantumTime=0;
   }
}

void initialize_Job(job c[], int size) {
   for(int i=0; i<size; i++){
       c[i].jobID=0;
       c[i].priority=0;
       c[i].arrivalTime=0;
       c[i].memory=0;
       c[i].devices=0;
       c[i].runTime=0;
   }
}

void initialize_request(request c[], int size) {
   for(int i=0; i<size; i++){
       c[i].timeStamp=0;
       c[i].jobID=0;
       c[i].devices=0;
   }
}

void initialize_release(release c[], int size) {
   for(int i=0; i<size; i++){
      c[i].timeStamp=0;
      c[i].jobID=0;
      c[i].devices=0;
   }
}

