/* simple banner graber in c 
 * date: Sat Jun 13 05:19:36 PM +05 2026
 * copyright: rootvector (https://github.com/rootvector)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 4096

void usage(const char tool);


int main(int argc, char *argv[]){
    char target[INET_ADDRSTRLEN];
    int start = 1, end = 1000;

    struct sockaddr_in vaddr;

    printf("Argv[1]: %s\tArgv[2]: %s\n", argv[1], argv[2]);
    if(argc < 3){
        usage(argv[0]);
        exit(0);
    }
    printf("ROOTVECTOR BANNER GRABBER\n\n");
    for(int i = 1; i <= argc; i++){
        if(!(strcmp(argv[i], "-h")) || !(strcmp(argv[i], "--help"))){
            usage(argv[0]);
            exit(0);
        }else if(!(strcmp(argv[i], "-t")) || !(strcmp(argv[i], "--target"))){
            if(i+2 <= argc){
                //if((inet_pton(AF_INET, argv[2], &(vaddr.sin_addr)) != 1))
                     //   printf("Please Provide Valid IP Address..!\n\n");
            }
        }

    }

    printf("Taget: %s\n", target);

    return 0;
}

void usage(const char tool){
    printf("Usage: %s -t target -p port\n\n"
            "OPTIONS\n"
            "\t-h [--help]   : get help page.\n"
            "\t-t [--target] : target ip for grab banners\n"
            "\t-p [--port]   : port to grab banner (default scans for 1000 starting ports)\n"
            "\t\t\tyou can provide a single port or range of ports to grab banner\n\n"
            "EXAMPLES\n"
            "\t%s -t 10.10.10.10 -p 20 100\n"
            "\t%s -t 0.0.0.0 -p 80\n"
            "\t%s --target 127.0.0.1\n\n", tool, tool, tool, tool);
}
