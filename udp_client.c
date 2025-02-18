#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cli_len = sizeof(cliaddr);
    char buffer[BUFFER_SIZE];
    

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    printf("Server listening on port 8080...\n");

    while (1) {
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cliaddr, &cli_len);
        if (is_palindrome(buffer)) {
            sendto(sockfd, "1", 1, 0, (struct sockaddr *)&cliaddr, cli_len);
        } else {
            sendto(sockfd, "0", 1, 0, (struct sockaddr *)&cliaddr, cli_len);
        }
    }

    return 0;
}
