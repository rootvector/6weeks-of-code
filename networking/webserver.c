/* WEB SERVER USING SOCKET */
/* date: Thu Jun  4 10:03:35 PM +05 2026 */

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>


#define BUF_SIZE 10000
#define PORT 8080

int main(int argc, char *argv[]){
    char buffer[BUF_SIZE];
    int sockfd, new_socket;
    struct sockaddr_in addr;   
    int addrlen = sizeof(addr);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("Socket does not created..\n");
        return -1;
    }


    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if((bind(sockfd,(struct sockaddr *)&addr, sizeof(struct sockaddr)) != 0)){
        perror("bind error..!\n");
        close(sockfd);
        return -1;
    }

    if((listen(sockfd, 5)) != 0){
        printf("Does not listen for connection..!\n");
        close(sockfd);
        return -1;
    }

    printf("Server listening on port %d\n", PORT);

        if((new_socket = accept(sockfd, (struct sockaddr *)&addr, (socklen_t *)&addrlen)) < 0){
            printf("Accept Error\n");
            close(sockfd);
            return -1;
        }


        int bytes = recv(new_socket, buffer, BUF_SIZE, 0);
        printf("client sends: %s\n", buffer);

        FILE *fd = fopen("index.html", "r");
        if(fd == NULL){
            printf("file not open..\n");
            close(new_socket);
            close(sockfd);
            return -1;
        }
      //  char *message = (char *)malloc(BUF_SIZE);

      //  size_t bytessize = fread(message, 1, ftell(fd), fd); 

        char *message = "HTTP/1.1 200 OK\r\n";
        send(new_socket, message, strlen(message), 0);

        char *headers = "Content-Type: text/html\r\n"
            "Content-Length: 10000\r\n\n\n";
        send(new_socket, headers, strlen(headers), 0);
        
        int c;
        int size = 0;
        char text[BUF_SIZE];
       /* while((c=getchar())!=EOF){
        //char *response = "<center><h1>Hello, Rohan</h1></center>\r\n";
            text[size] = c;
            size++;
            if(size>255){
                size = 0;
                send(new_socket, text, strlen(text), 0);
            }
        }*/
        send(new_socket, "<a href=\"https://youtube.com\">youtube</a>", 50, 0);

    fclose(fd);
   // free(message);
    close(new_socket);
    close(sockfd);
    return 0;
}
