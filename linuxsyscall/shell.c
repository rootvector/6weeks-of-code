/* simple shell in c
 * date: Sat Sep 12 02:31:09 AM +05 2026
 * copyright: rootvector (https://github.com/rootvector)
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>       // for wait function
#include <fcntl.h>          // for file operations
#include <sys/stat.h>

#define BUF_SIZE 1024
#define HISTORY_FILE_PATH "/home/kali/.myshell_history"

int handle_redirect(char *args[]);

int main(int argc, char *argv[]){
    char command[BUF_SIZE] = "";
    char buffer[BUF_SIZE] = "";
    bool check_exit = false;
    int interactive = 1;

    if(argc > 1){
        // First arg is the name of the script
        if(freopen(argv[1], "r", stdin) == NULL){
            fprintf(stderr, "can't read from script file %s\n", argv[1]);
            fprintf(stderr, "Exiting.\n");
            exit(1);
        }
        interactive = 0;
        
    }
    while(!check_exit){
        if(interactive) printf("$ ");
        fflush(stdout);
        if(fgets(command, BUF_SIZE, stdin) == NULL){
            break;
        }
        strcpy(buffer, command);
        command[strcspn(command, "\n")] = '\0';

        // Split buf into args
        char *args[20];
        int nargs = 0;

        args[nargs] = strtok(command, " ");
        while(args[nargs] != NULL){
            args[++nargs] = strtok(NULL, " ");
        }
        // Opening a file 

        int history_fd = open(HISTORY_FILE_PATH, O_WRONLY | O_CREAT | O_APPEND, 0664);
        if(history_fd == -1){
            perror("History file does not open\n");
        }

        // writting inside a file

        snprintf(buffer, sizeof(command), "%s\n", command);
        ssize_t byteswritten = write(history_fd, buffer, strlen(buffer));
        if(byteswritten == -1){
            perror("Error: while writing command in history file\n");
        }

        // closing a file

        close(history_fd);

        if((strcmp(command, "exit")) == 0){
            check_exit = true;
            puts("\nGood bye..!\n");
            exit(0);
        }
        if((strcmp(command, "history")) == 0){
            FILE *history_fd = fopen(HISTORY_FILE_PATH, "r");
            if(history_fd == NULL){
                fclose(history_fd);
                perror("History file does not open\n");
            }
            
            char *line = NULL;
            int line_count = 1;
            ssize_t readbytes;
            ssize_t len = 0;

            while((readbytes = getline(&line, &len, history_fd)) != -1){
                printf("%d %s", line_count, line);
                line_count++;
            }
            printf("\n");
            free(line);
            fclose(history_fd);
            continue;
        }
        

        pid_t pid = fork();
        if(pid > 0){
            // We are the parent
            wait(NULL);
        }else{
            if(strlen(command) > 0){
                // Runing a command
                if(handle_redirect(args) == -1){
                    fprintf(stderr, "Could not redirect\n");
                    exit(1);
                }

                execvp(args[0], args);
                fprintf(stderr, "Could not exec %s\n", command);
                printf("\n");
            }
        }
    }

    return 0;
}


int handle_redirect(char *args[]){

    for(int i=0; args[i] != NULL; i++){
        if(strcmp(args[i], ">") == 0){
            if(freopen(args[i+1], "w", stdout) == NULL) return -1;
            args[i] = NULL;
            return 1;
        }else if(strcmp(args[i], ">>") == 0){
            if(freopen(args[i+1], "a", stdout) == NULL) return -1;
            args[i] = NULL;
            return 1;
        }
   }

    return 0;
}
