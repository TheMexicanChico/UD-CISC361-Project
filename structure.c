#include "structure.h"

void initialize_config(config* head, int size) {
   int arrivalTime, memory, devices, quantumTime;
   for(int i=0; i<size; i++){
       arrivalTime=head->arrivalTime;
       memory=head->memory;
       devices=head->devices;
       quantumTime=head->quantumTime;
   }
}

void initialize_Job(job* head, int size) {
   job* headRef = head;
   job* currentJob;
   int arrivalTime, memory, devices, jobID, priority, memory, runtime;
   while(head){
      currentJob->jobID=head->jobID;
      currentJob->priority=head->priority;
      currentJob->arrivalTime=head->arrivalTime;
      currentJob->memory=head->memory; // ?
      currentJob->devices=head->devices;
      currentJob->runTime=head->runTime;
   }

}

void initialize_request(job* requestJob, int size) {
   config* configFile; // remove this after config is initialized 

   configFile->devices += requestJob->devices;

   // quantum interrupted
   if (configFile->quantumTime <= 0) {

   } else {

   }
}

void initialize_release(job* releaseJob, int size) {
   config* configFile; // remove this after config is initialized 

   // quantum interrupted
   int t = 0;
   if (configFile->quantumTime <= configFile->) {
      t = t + configFile->quantumTime;
      configFile->devices += releaseJob->devices;
      //releaseJob->next = releaseJob->jobID;
   } else {
      t = t + ;
      waitTime = t -
      
      //releaseJob->next = releaseJob->jobID;
      //releaseJob->arrivalTime += configFile->quantumTime;
      //releaseJob-> = NULL;
   }
   // everytime someting 
   // wait queue disrrutption 

}