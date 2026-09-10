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

#define BUF_SIZE 1024
#define MIN 0
#define MAX 65535
#define WELL_KNOWN_PORTS 1023
void usage(const char tool[10]);

void grab_banner(const char target[INET_ADDRSTRLEN], const int port);
void grab_banners(const char target[INET_ADDRSTRLEN], const int start, const int end);

int main(int argc, char *argv[]){
    char target[INET_ADDRSTRLEN];
    int start = MIN;
    int end = WELL_KNOWN_PORTS, port = 0;

    struct sockaddr_in vaddr;

    if(argc < 3){
        usage(argv[0]);
        exit(0);
    }else if(argc == 2){
        if(!(strcmp(argv[1], "-h")) || !(strcmp(argv[1], "--help"))){
            usage(argv[0]);
            exit(0);
        }
    }

    printf("ROOTVECTOR BANNER GRABBER\n\n");
    for(int i = 1; i < argc; i++){
        if(!(strcmp(argv[i], "-t")) || !(strcmp(argv[i], "--target"))){
            if(i+2 <= argc){
                if((inet_pton(AF_INET, argv[i+1], &(vaddr.sin_addr)) != 1)){
                    printf("Please Provide Valid IP Address..!\n\n");
                    exit(0);
                }
                else
                    strcpy(target, argv[++i]);
            }
        }else if(!(strcmp(argv[i], "-p")) || !(strcmp(argv[i], "--port"))){
            if(i+3 == argc){
                if((start = atoi(argv[++i])) == 0){
                    printf("Please Provide Ports to scan..!\n");
                    exit(0);
                }
                if((end = atoi(argv[++i])) == 0){
                    printf("Please Provide End Port to Scan..!\n");
                    exit(0);
                }

                if(start > end){
                    int temp = start;
                    start = end;
                    end = temp;
                }

                if(MIN <= start && end <= MAX)
                    ;
                else{
                    printf("Ports: %d-%d\n", start, end);
                    printf("Port must be in range of (%d-%d)\n", MIN, MAX);
                    exit(0);
                }
            }else if(i+2 == argc){
                    if((port = atoi(argv[++i])) < 0){
                        printf("Please Provid a Single Port to scan..!\n");
                        exit(0);
                    }
                    if(MIN <= port && port <= MAX)
                        ;
                    else{
                        printf("Port: %d\n", port);
                        printf("Port must be in range of (%d-%d)\n", MIN, MAX);
                        exit(0);
                    }
                }
        }


    }

    printf("Taget: %s\nPorts Range: %d/%d\nPORT: %d\n", target, start, end, port);
    if(port >= 0 && start == 0 && end == WELL_KNOWN_PORTS)
        grab_banner(target, port);
    else if(port == 0 && MIN <= start && end <= MAX){
        printf("\nGRABBING BANNERS FOR %s:%d/%d\n\n", target, start, end);
        grab_banners(target, start, end);
       // for(; start++ < end;){
          //  grab_banners(target, start, end);
        //}
    }

    printf("\n\ngithub: https://github.com/rootvector\n\n");
    return 0;
}

void usage(const char tool[10]){
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


void grab_banner(const char target[INET_ADDRSTRLEN], const int port){
    printf("\nGRABBING BANNER FOR %s:%d\n\n", target, port);
    struct sockaddr_in addr;
    int sockfd;
    int addrlen = sizeof(addr);
    char ping[] = "GET / HTTP/1.1\r\n"
        "Host: 127.0.0.1\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 4096\r\n";
    char buffer[BUF_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if(sockfd < 0){
            perror("Socket");
            exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(target);

    if((connect(sockfd, (struct sockaddr*)&addr, sizeof(addr))) < 0){
            printf("Not listening for %s:%d\n", target, port);
            perror("Connect");
            exit(0);
    }
    printf("Port: %d was Open\n", port);

    if((recv(sockfd, buffer, BUF_SIZE, 0)) < 0){   
        perror("Receive");
        exit(0);
    }
    printf("Client Sends:\n\t%s\n\n", buffer); 

    if((send(sockfd, ping, strlen(ping), 0)) < 0){
        perror("Send");
        exit(0);
    }
    close(sockfd);

}

void grab_banners(const char target[INET_ADDRSTRLEN], const int start, const int end){
    struct sockaddr_in addr;
    int sockfd;
    int addrlen = sizeof(addr);
    int port = 0;
    char ping[] = "GET / HTTP/1.1\r\n"
        "Host: 127.0.0.1\r\n"
        "User-Agent: Mozilla/5.0\r\n"
        "Accept: text/html,appllication/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
        "Accept-Language: en-US,en;q=0.5\r\n"
        "Accept-Encoding: gzip, deflate, br, zstd\r\n"
        "Priorit: u=0\r\n";
    char buffer[BUF_SIZE];


    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(target);

    for(int i = start; i <= end; i++){
        port = i;
        printf("port: %d\n", port);
        sockfd = socket(AF_INET, SOCK_STREAM, 0); 
        if(sockfd < 0){
                perror("Socket");
                exit(1);
        }

        addr.sin_port = htons(port);

        if((connect(sockfd, (struct sockaddr*)&addr, sizeof(addr))) >= 0){
            printf("Port: %d was Open\n", port);

            if((recv(sockfd, buffer, BUF_SIZE, 0)) < 0){   
                perror("Receive");
                //exit(0);
            }
            
            printf("Client Sends:\n\t%s\n\n", buffer); 
            i++;
            port++;
            continue;
            
        }

        if((send(sockfd, ping, strlen(ping), 0)) < 0){
            perror("Send");
           // exit(0);
        }
        if((recv(sockfd, buffer, BUF_SIZE, 0))<0){
            perror("Receive");
           // exit(0);
        }
        printf("Clinet Sends:\n\t%s\n\n", buffer);
        close(sockfd);
    }

}
