/* simple shell in c
 * date: Sat Sep 12 02:31:09 AM +05 2026
 * copyright: rootvector (https://github.com/rootvector)
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024


int main(int argc, char *argv[]){
    char buffer[BUF_SIZE];
    bool exit = false;

    while(!exit){
        printf("$ ");
        fflush(stdout);
        if(fgets(buffer, sizeof(BUF_SIZE), stdin) == 0){
            break;
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        if((strcmp(buffer, "exit")) == 0){
            exit = true;
            puts("\nGood bye..!\n");
            continue;
        }
        if(strlen(buffer) > 0){
            system(buffer);
        }
    }

    return 0;
}
