#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>


int main() {
    struct addrinfo *first_info;
    struct addrinfo hints = {};
    hints.ai_family = AF_INET;


}