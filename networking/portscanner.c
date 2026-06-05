/* SIMPLE PORT SCANNER */
/* Date: Fri Jun  5 10:22:07 PM +05 2026 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define DEF_PORTS 1000
#define BUF_SIZE 1000
#define DEF_SCAN "SOCK_STREAM"
#define UDP_SCAN "SOCK_DGRAM"

int tcpscan(int start, int end, char target[16]);
int udpscan(int start, int end, char target[16]);

int main(int argc, char *argv[]){
    char *buffer = (char*) malloc(BUF_SIZE);
    char *target = (char*) malloc(16);
    char *scantype = (char *) malloc(12);
    int flag;
    int start, end;

    printf("ROOTVECTOR PORT SCANNER\n");
    if(argc < 3){
        printf("Usage: %s START ENDPORT TARGET SOCK_STREAM/SOCK_DGRAM\n\n"
                "Default Ports for scan is %d\n"
                "Default Scan type is %s\n\n", argv[0], DEF_PORTS, DEF_SCAN);
        return -1;
    }
    start = atoi(argv[1]);
    end = atoi(argv[2]);
    strcpy(target, argv[3]);
    (argc == 5)? strcpy(scantype, argv[4]) : strcpy(scantype, DEF_SCAN);
    printf("CMD: %s %d %d %s %s\n\n", argv[0], start, end, target, (argc == 5) ? scantype : DEF_SCAN);
   // printf("start %d\nEnd %d \ntarget %s\nscantype %s\nARGC %d\n", start, end, target, scantype, argc);

    if(argc == 5){
        if((strcmp(DEF_SCAN, argv[4])) == 0){
            flag = tcpscan(start, end, target);
        }else if((strcmp(UDP_SCAN, argv[4])) == 0){
            flag = udpscan(start, end, target);
        }
    }else{
        tcpscan(start, end, target);
    }


    free(buffer);
    free(target);
    free(scantype);
    return 0;
}

int tcpscan(int start, int end, char target[16]){
    printf("START TCP SCAN FOR %s\n\n", target);
    int st = start;
    int res;

    printf("\tPORT\tSTATE\n");
    while(st <= end){
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if(sockfd < 0){
            perror("Socket Error ");
            return -1;
        }

        struct sockaddr_in addr;

        addr.sin_family = AF_INET;
        addr.sin_port = htons(st);
        addr.sin_addr.s_addr = inet_addr(target);

        res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
       // printf("IP %0x8\n", addr.sin_addr.s_addr);
        if(res < 0 && errno == ETIMEDOUT){
            perror("Connection Error ");
            return -1;
        }else if(res == 0){
            printf("\t%4d \tOPEN\n", st);
        }

       close(sockfd); 
       st++;
    }

}

int udpscan(int start, int end, char target[16]){
    printf("START UDP SCAN FOR %s\n\n", target);

}
