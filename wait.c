#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shortestjobfirst.h"
#include "firstinout.h"

struct JobRef *jobList;

void initialize_request() {
    jobList = malloc(sizeof(*jobList));
    jobList->head = jobList;
    jobList->tail = jobList;
    jobList->next = NULL;
}

// Still needs some work
void calculateRequirement(int requirement[][], int maximum[][], int alloted[][]){
    int num_processes;
    int num_resources;
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) { 
            // requirement of instance = maximum instance - alloted instance 
            requirement[i][j] = maximum[i][j] - alloted[i][j];
        }
    } 
}

void isSafe(int processes[], int available[], int maximum[][], int alloted[][]) {
    // boolean
    int [][]requirement = new int[num_processes][num_resources]; 

    // Invoke calculate requirement
    calculateRequirement(requirement, maximum, alloted); 

    // Mark all processes as unfinished 
    bool []finished = new bool[num_processes]; 

    // Stores safe sequence 
    int []safeSequence = new int[num_processes]; 

    // Copy available resources 
    int []cAvail = new int[num_resources]; 
    for (int i = 0; i < num_resources; i++) 
        cAvail[i] = available[i]; 

    // Loop until all processes are not done or system is not in safe state
    int count = 0; 
    while (count < num_processes){ 
        boolean is_safe = false; 
        for (int p = 0; p < num_processes; p++){ 
            // Check if a process is finished then proceed
            if (finished[p] == false){ 
                int j; 
                for (j = 0; j < num_resources; j++) 
                    if (requirement[p][j] > cAvail[j]) 
                        break; 
                    // If all requirements of process were satisfied. 
                if (j == num_resources){ 
                    // Free resources of the current process
                    for (int k = 0 ; k < num_resources ; k++) 
                        cAvail[k] += alloted[p][k]; 

                    // Add this process to safe sequence. 
                    safeSequence[count++] = p; 

                    finished[p] = true; 
                    is_safe = true; 
                } 
            } 
        } 

        // If next safe state process is not found
        if (is_safe == false){ 
            System.out.println("System is not in safe state"); 
            return false; 
        } 
    }

    // If safe then print the possible safe sequence
    System.out.println("System is in safe state.\nPossible safe sequence is: "); 
        for (int i = 0; i < num_processes; i++) 
            System.out.print("P"+safeSequence[i] + " ");
        System.out.print("\n");

        return true; 
} 


/*
void banker(struct JobRef *current_job) {
    int i, j, k;
    //n = 5; // Number of processes
    //m = 3; // Number of resources
    int n = ;
    int m = ;
 
    int max[i][j];
    int alloc[i][j];
    int avail[3] = { 3, 3, 2 }; // Available Resources (Change this)
     
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
         for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
}
*/

void waitQueue(struct JobRef *current_job) {
    if (jobList->head != NULL) {
        if (jobList == NULL) {
            initialize_request(jobList);
        } else {

        }
    } else {

    }
}
