#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    printf("Enter a string: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

    char response[BUFFER_SIZE];
    recvfrom(sockfd, response, BUFFER_SIZE, 0, NULL, NULL);

    printf("Server response: %c\n", response[0]);

    return 0;
}
