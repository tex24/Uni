#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

void reverse(char s[])
{
    char tmp;
    for (int i = 0, j = strlen(s) - 1; i < strlen(s) / 2; i++, j--)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Inserisci 2 argomenti (ip, porta)\n");
        return EXIT_FAILURE;
    }
    struct in_addr address;
    int r = inet_aton(argv[1], &address);
    if (r == 0)
    {
        fprintf(stderr, "Error: aton\n");
        return EXIT_FAILURE;
    }
    struct sockaddr_in sock;
    sock.sin_addr = address;
    sock.sin_family = AF_INET;
    sock.sin_port = htons(atoi(argv[2]));

    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr_in)) == -1)
    {
        fprintf(stderr, "Error: socket\n");
        return EXIT_FAILURE;
    }

    char buff[100];
    for (unsigned int i = 0; i < 4; i++)
    {
        int len = read(s, buff, 99 * sizeof(char));
        buff[len] = '\0';
        reverse(buff);
        printf("%s\n", buff);
    }
    close(s);
}