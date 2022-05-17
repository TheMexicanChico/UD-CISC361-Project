#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "shortestjobfirst.h"
#include "firstinout.h"

struct JobRef *jobList;

void banker(struct JobRef *current_job) {
    int i, j, k;
    //n = 5; // Number of processes
    //m = 3; // Number of resources
    int n = 0;
    int m = 0;
 
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
