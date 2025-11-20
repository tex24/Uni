#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

int main(){
    struct in_addr address;
    int r = inet_aton("45.79.112.203", &address);
    if(r==0){
        fprintf(stderr,"Error: aton\n");
        return EXIT_FAILURE;
    }
    struct sockaddr_in sock;
    sock.sin_addr = address;
    sock.sin_family = AF_INET;
    sock.sin_port = htons(4242);

    int s = socket(PF_INET, SOCK_STREAM, 0);
    if(connect(s, (struct sockaddr *) &sock, sizeof(struct sockaddr_in)) == -1) {
        fprintf(stderr,"Error: socket\n");
        return EXIT_FAILURE;
    }
    char buff[100];
    for (int i = 0; i < 10; i++) {
        char *mess = "ciao\n";
        write(s, mess, strlen(mess));
        int size = read(s, buff, 99*sizeof(char));
        buff[size] = '\0';
        printf("%s\n", buff);
    }
    close(s);
}