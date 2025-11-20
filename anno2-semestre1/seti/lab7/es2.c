#include <stdint.h>
#include <arpa/inet.h> 
#include <stdio.h>

int main(){
    uint32_t y = 32;
    uint32_t x = htonl(y);
    printf("%d\nx = %u\ny = %u\n", x == y, x, y);
    char a[4];
    //int v = 40000000;
    //char *a=(char *)&v;
    int i = 40000000;
    a[0] = i;
    a[1] = i >> 8;
    a[2] = i >> 16;
    a[3] = i >> 24;
    printf("\n\n%x\n", i);
    for(int i =0; i < 4; i++){
        printf("%x\n", a[i]);
    }
}