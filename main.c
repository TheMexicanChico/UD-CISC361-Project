#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.c"
#include <ctype.h>
#include <math.h>
#define M1 130
#define M2 20
int main()
{
    char line[M2][M1];
    char doname[30];
    int k=0;
    int no=0;
    FILE *file = fopen("i.txt", "r");
    //char ch;

    file = fopen("i.txt", "r");



    while(fgets(line[k],M1,file)){
        line[k][strlen(line[k])-1]='\0';
        k++;
    }
    no=k;
    for(k=0;k<no;++k)
    {
        printf("%s\n", line[k]);
    }
        printf("\n");

    for(int i = 0; i< k; i++){
        //printf("%c", line[i][0]);
        if(line[i][0] == 'C'){
            int count = 0;
            int arrCount = 0;
            int l;
            int size = 5;
            int arr[4];
            char first[size];
            char second[size];
            char third[size];
            char fourth[size];
            for(int j=0; j <= 3; j++){
                char temp[4];
                int c = j;
                while(isdigit(line[i][c])){
                    temp[count] = line[i][c];
                    count++;
                    c++;
                }
                printf("%s", temp);
                j = c;
                
                if(line[i][j] = ' '){
                    sscanf(temp, "%d", &i);
                    arr[arrCount] = l;
                    arrCount++;
                    count = 0;
                    
                }
                }
            for(int p= 0; p < 5; p++){
                printf("%d", arr[p]);
            }
            }
        else if(line[i][0] == 'A'){
            for(int j=0; j != '\0'; j++){
                int c[2];
            }
        }
    }
    
fclose(file);

return 0;

}



    /*while ((ch = fgetc(file)) != EOF)
    {
        if(ch == 67){

            
            }   
        }
    }
    */