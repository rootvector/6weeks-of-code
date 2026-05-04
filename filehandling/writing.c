#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp = fopen("sample.txt", "w");
    if(fp == NULL){
        ferror(fp);
        return -1;
    }
    
    fprintf(fp, "this is a text\n");
    fprintf(fp, "this is next line\n");

    fclose(fp);
    return 0;
}
