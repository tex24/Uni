#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

int main() {
    struct in_addr address;
    int r = inet_aton("129.6.15.29", &address);
    if (r == 0) {
        fprintf(stderr, "Error: aton\n");
        return EXIT_FAILURE;
    }
    struct sockaddr_in sock;
    sock.sin_addr = address;
    sock.sin_family = AF_INET;
    sock.sin_port = htons(13);

    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (connect(s, (struct sockaddr*)&sock, sizeof(struct sockaddr_in)) == -1) {
        fprintf(stderr, "Error: socket\n");
        return EXIT_FAILURE;
    }

    char buff[50];
    int len = read(s, buff, 49 * sizeof(char));
    close(s);
    buff[len] = '\0';
    char* word;
    char date[10];
    char time[10];
    word = strchr(buff, ' ');
    word++;
    sscanf(word, "%s %s", date, time);
    printf("Siamo il %s e sono le %s\n", date, time);
}