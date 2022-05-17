#include "structure.h"

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
       c[i].burstTime=0;
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