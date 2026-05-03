#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/xscan.h"
void search(){
    printf("this is search function: \n");
}

int main(int argc, char *argv[]){
    int c;
    FILE *fp;
    while(argc--){
        while(argv[1]){
            if((c=getchar()) == '-'){
                c = getchar();
                if(c=='s')
                    search();
            }
            printf("This is word..!");
        }
    }
    /*if(argc == 1){
        stream_copy(stdin);
        return 0;
    }
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        perror(argv[1]);
        return 1;
    }
    stream_copy(fp);
    fclose(fp);

    char *buffer = (char *) calloc(100, sizeof(char));
    while((c=getchar())!=EOF){
        print_byte(&c);
//        strcpy(buffer++, (char *)c);
    }
    hex(buffer);
    free(buffer);*/
    return 0;
}
