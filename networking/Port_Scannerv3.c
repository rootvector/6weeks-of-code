/* SIMPLE PORT SCANNER /
/ Date: Fri Jun  5 10:22:07 PM +05 2026 /
/ copyright: rootvector (https://github.com/rootvector)*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <ctype.h>

#define DEF_PORTS 1000
#define DEF_SCAN "SOCK_STREAM"
#define UDP_SCAN "SOCK_DGRAM"

void usage(const char *scanner);

int tcpscan(int start, int end, char target[16]);
int udpscan(int start, int end, char target[16]);

int main(int argc, char *argv[]){
char target[16] = "";
char scantype[12] = DEF_SCAN;
int flag;
int start = 1, end = DEF_PORTS;

system("clear");  
printf("ROOTVECTOR PORT SCANNER\n");  
if(argc < 3){  
    usage(argv[0]);  
    return -1;  
}else {  
    for(int i=1; i < argc; i++){  
        if((strcmp(argv[i], "-h"))==0){  
            usage(argv[0]);  
            return -1;  
        }else if((strcmp(argv[i], "-p")) == 0){  
            if(argc >= i+3){  
                ((start = atoi(argv[i+1])) == 0)? start = 1 : printf("");  
                ((end = atoi(argv[i+2])) == 0)? end = DEF_PORTS : printf("");  
                if(start > end){  
                    int temp = start;  
                    start = end;  
                    end = temp;  
                }  
            }  
        }else if((strcmp(argv[i], "-t")) == 0){  
            struct sockaddr_in sa;  
            if(argc >= i+2){  
                if(inet_pton(AF_INET, argv[i+1], &(sa.sin_addr)) != 1){  
                    printf("Invalid Ip Address\n");  
                    return -1;  
                }else{  
                    strcpy(target, argv[++i]);  
                }  
            }  
        }else if((strcmp(argv[i], "-type")) == 0){  
            if(argc >= i+2){  
                strcpy(scantype, argv[++i]);  
            }  
        }  
    }  
}  

if((strcmp(target, ""))==0){  
    printf("Please Provide  Target..!\n");  
    usage(argv[0]);  
    return -1;  
}  
  
printf("\nCommand: ");  
for(int i=0; i<argc; i++){  
    printf("%s ", argv[i]);  
}  
  
printf("\nstart %d\tEnd %d\ttarget %s\tscantype %s\tARGC %d\n", start, end, target, scantype, argc);  
printf("\n\n");  

if((strcmp(DEF_SCAN, scantype)) == 0){  
    flag = tcpscan(start, end, target);  
}else if((strcmp(UDP_SCAN, scantype)) == 0){  
    flag = udpscan(start, end, target);  
}else{  
    printf("Scantype is invalid..\n");  
}  
return 0;

}

void usage(char scanner[10]){

printf("Usage: %s -p START ENDPORT -t TARGET -type SOCK_STREAM/SOCK_DGRAM\n\n"  
            "OPTIONS\n"  
            "\t-h : get help page.\n"  
            "\t-p : specify START and ENDPORTS for scan in range.\n"  
            "\t\tDefault Ports for scan is %d\n"  
            "\t-t : target for scan\n\n"  
            "\t-type : TCP/UDP scan.\n"  
            "\t\tSOCK_STREAM for TCP and SOCK_DGRAM for UDP\n"  
            "\t\t(Default Scan type is %s)\n\n"  
            "EXAMPLE\n"  
            "\t%s -p 20 100 -t 127.0.0.1 -type SOCK_STREAM\n\n"  
            , scanner, DEF_PORTS, DEF_SCAN, scanner);

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
    memset(&addr, 0, sizeof(addr));  

    addr.sin_family = AF_INET;  
    addr.sin_port = htons(st);  
    addr.sin_addr.s_addr = inet_addr(target);  

    res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));  
   // printf("IP %0x8\n", addr.sin_addr.s_addr);  
    if(res == 0){  
        printf("\t%4d \tOPEN\n", st);  
    }  

   close(sockfd);   
   st++;  
}

return 0;
}

int udpscan(int start, int end, char target[16]){
printf("START UDP SCAN FOR %s\n\n", target);

int st = start;  
int res;  

printf("\tPORT\tSTATE\n");  
while(st <= end){  
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  

    if(sockfd < 0){  
        perror("Socket Error ");  
        return -1;  
    }  

    struct sockaddr_in addr;  
    memset(&addr, 0, sizeof(addr));  

    addr.sin_family = AF_INET;  
    addr.sin_port = htons(st);  
    addr.sin_addr.s_addr = inet_addr(target);  

    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));  

    const char *payload = "ping";  

    send(sockfd, payload, strlen(payload), 0);  
    usleep(100000);  
      
    char buffer[BUF_SIZE];  
    res = recv(sockfd, buffer, sizeof(buffer), MSG_DONTWAIT);  
   // printf("IP %0x8\n", addr.sin_addr.s_addr);  

    if(!(res < 0 && errno == ECONNREFUSED)){  
        printf("\t%4d \tOPEN\n", st);  
    }else{  
        //printf("\t%4d \tCLOSED\n", st);  
    }  

   close(sockfd);   
   st++;  
}  
return 0;

}
