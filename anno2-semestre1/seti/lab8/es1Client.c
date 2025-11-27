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
    struct addrinfo *first_info;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int r = getaddrinfo("localhost", "5000", &hints, &first_info);
    if (r == 0)
    {
        struct addrinfo *info = first_info;
        int found = 0;
        struct sockaddr *saddr;
        struct sockaddr_in *addressin;
        if (info != NULL)
        {
            saddr = info->ai_addr;
            addressin = (struct sockaddr_in *)saddr;
            found = 1;
        }
        if (found == 1)
        {
            int descr = socket(PF_INET, SOCK_STREAM, 0);
            r = connect(descr, (struct sockaddr *)addressin,
                        sizeof(struct sockaddr_in));
            if (r != -1)
            {
                char buff[100];
                char mess[30];
                int max = 65535, min = 1;
                int size = read(descr, buff, sizeof(buff));
                buff[size] = '\0';
                printf("%s", buff);
                while (1)
                {
                    int n = (max + min) / 2;
                    if (max == min)
                        n = 0;
                    sprintf(mess, "%d", n);
                    write(descr, mess, strlen(mess));
                    int size = read(descr, buff, sizeof(buff));
                    buff[size] = '\0';
                    printf("%s", buff);
                    if (strcmp(buff, "Perso\n") == 0)
                        break;
                    if (strstr(buff, "PIU") != NULL)
                        min = n;
                    else if (strstr(buff, "MENO") != NULL)
                        max = n;
                    else if (strstr(buff, "Indovina") != NULL)
                        continue;
                    else
                        break;
                }
                close(descr);
            }
            else
            {
                fprintf(stderr, "Problem with connect\n");
                return EXIT_FAILURE;
            }
        }
        else
        {
            fprintf(stderr, "Host not found\n");
            return EXIT_FAILURE;
        }
    }
    else
    {
        fprintf(stderr, "Error: %s\n", gai_strerror(r));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}