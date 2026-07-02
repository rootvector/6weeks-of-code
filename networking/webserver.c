/* MAKING WEB SERVER TO HANDEL FILE SHARING 
 *
 * Date: Wed Jun 10 09:39:58 PM +05 2026
 * copyright: rootvector (https://github.com/rootvector)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>


#define DEF_PORT 40
#define BUF_SIZE 4096
#define WEB_DIR "/home/kali/Desktop/webroot/"

void usage(char tooname[10]);

int sendheader(int *sockfd);
int sendresponse(int *sockfd);


int main(int argc, char *argv[]){
    int sockfd, client_sockfd;
    int port = DEF_PORT;
    char domain[16] = "0.0.0.0";
    struct sockaddr_in addr;
    struct sockaddr_in client_addr;
    int addrlen = sizeof(addr);
    int cliaddrlen = sizeof(client_addr);
    char buffer[BUF_SIZE], response[1000];
    int bytes_send, bytes_recv;

    for(int i = 1; i < argc; i++){
        if(!(strcmp(argv[i], "-h")) || !(strcmp(argv[i], "--help"))){
            system("clear");
            usage(argv[0]);
            return 0;
        }else if(!(strcmp(argv[i], "-p")) || !(strcmp(argv[i], "--port"))){
            if(argc >= i+2){
                if(!(port = atoi(argv[i+1]))){
                    printf("Plese Provide valid Port Number..\n");
                    return -1;
                }
            }else{
                printf("Provid Port Number\n\n");
                return -1;
            }

        }else if(!(strcmp(argv[i], "-d")) || !(strcmp(argv[i], "--domain"))){
            if(argc >= i+2){
                struct sockaddr_in sa;
                if(inet_pton(AF_INET, argv[i+1], &(sa.sin_addr)) != 1){
                    printf("Please Provid valid domain IP..!\n");
                    return -1;
                }else{ 
                    strcpy(domain, argv[i+1]);
                }
            }
        }
    }

    printf("out of loop\nargc: %d\tport: %d\tdomain: %s\n", argc, port, domain);

    // HANDLING WEB SERVER
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(domain);

    if(sockfd < 0){
        perror("Socket Error");
        return -1;
    }

    if((bind(sockfd, (struct sockaddr *)&addr, addrlen)) < 0){
         perror("Bind Error");
         return -1;
    }

    if((listen(sockfd, 5)) < 0){
        perror("Lisetn Error");
        return -1;
    }

    printf("Listening on %s:%d..\n", domain, port);

    if((client_sockfd = accept(sockfd, (struct sockaddr *)&addr,(socklen_t  *)&addrlen)) < 0){
        perror("Accept Error");
        return -1;
    }

    while(1){
        bytes_recv = recv(client_sockfd, buffer, BUF_SIZE, 0);

        printf("Client Sends:\n %s\n", buffer);

        fflush(stdout);
        strcpy(response, "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: 500\r\n\r\n");
        bytes_send = send(client_sockfd, response, strlen(response), 0);

        char filepath[100] = WEB_DIR;
        strcat(filepath, "index.html");
        FILE *fp = fopen(filepath, "r");
        if(fp == NULL){
        strcpy(response, "HTTP/1.1 400 OK\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: 20\r\n\r\n"
                "<h1>File Does not Exites</h1>\r\n");
        bytes_send = send(client_sockfd, response, strlen(response), 0);
        break;

        }
        char c;
        while((c=getc(fp))!=EOF){
            bytes_send = send(client_sockfd, (void *)&c, 1, 0);
        }
        fclose(fp);


        strcpy(response, "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/css\r\n"
                "Content-Length: 20\r\n\r\n");
        bytes_send = send(client_sockfd, response, strlen(response), 0);

        strcpy(filepath, WEB_DIR);
        strcat(filepath, "style.css");
        FILE *cssfile = fopen(filepath, "r");
        if(cssfile == NULL){
        strcpy(response, "HTTP/1.1 400 OK\r\n"
                "Content-Type: text/css\r\n"
                "Content-Length: 96\r\n\r\n"
                "<h1>File Does not Exites</h1>\r\n");
        bytes_send = send(client_sockfd, response, strlen(response), 0);
        break;

        }

        while((c=getc(cssfile))!=EOF){
            bytes_send = send(client_sockfd, (void *)&c, 1, 0);
        }
        fclose(cssfile);
        close(client_sockfd);

    }

    close(sockfd);
    return 0;
}


void usage(char filename[10]){
    printf("Usage: %s -p PORT -d DOMAIN\n\n"
            "OPTIONS\n"
            "\t-h\t[--help] : Get help page\n"
            "\t-p\t[--port] : Specify the port number.\n"
            "\t-d\t[--domain] : Domain/IP for server.\n\n"
            "EXAMPLES\n"
            "\t%s -p 8080 -d 127.0.0.1\n"
            "\t%s --port 3333 --domain 127.0.0.1\n", filename, filename, filename);
}

int sendheader(int *sockfd){

    return 0;
}

int sendresponse(int *sockfd){

    return 0;
}


