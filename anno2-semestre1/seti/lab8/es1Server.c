#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address_sock;
    address_sock.sin_family = AF_INET;
    address_sock.sin_port = htons(5002);
    address_sock.sin_addr.s_addr = htonl(INADDR_ANY);
    int r = bind(sock, (struct sockaddr *)&address_sock, sizeof(struct sockaddr_in));
    if (r == 0)
    {
        r = listen(sock, 0);
        while (1)
        {
            struct sockaddr_in caller;
            socklen_t size = sizeof(caller);
            int sock2 = accept(sock, (struct sockaddr *)&caller, &size);
            if (sock2 >= 0)
            {
                int idfork = fork();
                if (idfork == 0)
                {
                    close(sock);
                    char mess[25] = "Ciao ti sei collegato!\n";
                    write(sock2, mess, strlen(mess) * sizeof(char));
                    int n = rand() % 65535;
                    printf("%d\n", n);
                    for (int i = 1; i < 21; i++)
                    {
                        char buff[100];
                        int received = read(sock2, buff, 99 * sizeof(char));
                        buff[received] = '\0';
                        printf("Messagio ricevuto : %d\n", atoi(buff));
                        if (atoi(buff) < n)
                        {
                            sprintf(mess, "MENO %d\n", 20-i);
                            write(sock2, mess, strlen(mess) * sizeof(char));
                        }
                        else if (atoi(buff) > n)
                        {
                            sprintf(mess, "PIU %d\n", 20-i);
                            write(sock2, mess, strlen(mess) * sizeof(char));
                        }
                        else
                        {
                            sprintf(mess, "VINTO %d\n", 20-i);
                            write(sock2, mess, strlen(mess) * sizeof(char));
                            close(sock2);
                            exit(0);
                        }
                    }
                    strcpy(mess, "PERSO\n");
                    write(sock2, mess, strlen(mess) * sizeof(char));
                    close(sock2);
                    exit(0);
                }
                else
                {
                    close(sock2);
                }
            }
        }
    }
    else
    {
        fprintf(stderr, "Problem with bind\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}