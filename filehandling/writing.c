#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    fp = fopen("sample.txt", "a");
    if(fp == NULL){
        ferror(fp);
        return -1;
    }
    int i=1;
    while(argc-- > 0){
        fprintf(fp, argv[i]);
        i++;
    }

    fprintf(fp, "\n");

    fclose(fp);
    return 0;
}
