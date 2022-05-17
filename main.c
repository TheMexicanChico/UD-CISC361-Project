// Partners: Abel Juarez, Alex Rusin, Ren Ross

#include "structure.h"
#include "shortestjobfirst.c"
#include "firstinout.c"
#include "readyqueue.c"

int main() {
//https://stackoverflow.com/questions/13499866/read-from-text-file-only-numbers-in-c
    char symb ;
    unsigned char symb1;
    FILE *file;
    int arr[6];
    char temp[3];
    int count = 0;
    int arrCount = 0;
    config c;
    int memory;
    int devices;
    int time;
    char letter = 'C';
    file = fopen("i1.txt","rt");
    int jobCounter = 0;
    while ((symb=getc(file))!=EOF)
        {
        symb1= (unsigned char) symb;
         if(symb1 >= '0' && symb1 <='9'){
            temp[count] = symb1;
            count++;
        }else{
            if(count > 0){
                int l;
                sscanf(temp, "%d", &l);
                arr[arrCount] = l;
                arrCount++;
                count = 0;
                memset(temp, 0, sizeof(temp));
            }   
        }
        if(symb1 == 'A' || ((symb1 =='Q')&&(letter != 'C')) || symb1 == 'L' || ((symb1 == 'D') && (arrCount != 2))){
            for(int i = 0; i< arrCount; i++){
                //printf("%d", arr[i]);
            }
            printf("\n");
            arrCount = 0;
            if(letter == 'C'){ 
                c.arrivalTime = arr[0];
                c.memory = arr[1];
                c.devices = arr[2];
                c.quantumTime = arr[3];
                time = c.arrivalTime;
                memory = c.memory;
                devices = c.devices;
                memset(arr, 0, 6);
                letter = symb1;
            }else if(letter == 'A'){
                job j = {arr[1], arr[0], arr[5], arr[2], arr[3], arr[4]};
                job* jobCreated;
                if (j.memory <= c.memory){
                    if(j.memory > memory){
                        if(j.priority == 1){
                            fifo_hold_queue(jobCreated);
                        }else{
                            // TODO
                        }
                    }
                    if (j.devices <= c.devices){
                        //send to ready queue
                        memory -= j.memory;
                    } else{
                        // TODO
                    }
                }
                memset(arr, 0, 6);
                letter = symb1;
            }else if(letter == 'Q'){
                memset(arr, 0, 6);
                letter = symb1;
            }else if(letter == 'L'){
                memset(arr, 0, 6);
                letter = symb1;
            }else if(letter == 'D'){
                printf("At time %d:\n Current Available Main Memory = %d\n Current Devices = %d", time, memory,devices);
                time++;
            }
        }
        }
    fclose (file); 
    for(int i=0;i<jobCounter;i++){
        for(int j = 0; j <= 5; j++){
            //printf("%d ", jobTable[i][j]);
        }
        //printf("\n");
    }
    //printf("%d", c.arrivalTime);
}


// when reading in jobs, first one with allowed memory allocation goes right to ready queue
void get_job(job* jobReady, config c) {
    int qTime = c.quantumTime;
    // 67 = C for running on the CPU
    jobReady->queue = 67;
    
    while (qTime) {
        qTime -= 1;
        // 
        jobReady->burstTime -= 1;
        if (jobReady->burstTime == 0) {
            // terminate job
        } 
    }
    // context switch
    if (jobReady->burstTime > 0) {
        // 82 = "R" for ready queue
        jobReady->queue = 82;
        jobReady = ready_queue(jobReady);
    }
}