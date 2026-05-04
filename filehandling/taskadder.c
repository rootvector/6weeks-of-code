#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addtask(const char task[200], const char file[100]);

int main(int argc, char *argv[]){
    char task[200];
    char file[100];

    if(argc < 3){
        printf("Usage: %s \"your task to add in file\" filename.txt", argv[0]);
        return -1;
    }

        
    strcpy(task, argv[1]);
    strcpy(file, argv[2]);

    addtask(task, file);


    return 0;
}

void addtask(const char task[200], const char file[100]){
    FILE *fp = fopen(file, "a");

    if(task == NULL)
        printf("there is no task to add\n");
    else
        fprintf(fp, task);
    fprintf(fp, "\n");
    fclose(fp);
}
