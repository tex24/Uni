#include "stdio.h"
#include "string.h"
int main(int argc, char* argv[]){
    int s = 0;
    int n = 0;
    unsigned int i = 1;
    if(argc > 1){
        if(!strcmp(argv[1], "-n")){
            n = 1; 
            i++;
        }
        if(!strcmp(argv[1], "-s")){
            s = 1; 
            i++;
        }
    }
    if(argc > 2){
        if(!strcmp(argv[2], "-n")){
            n = 1; 
            i++;
        }
        if(!strcmp(argv[2], "-s")){
            s = 1; 
            i++;
        }
    }
    for(unsigned int j=i;j<argc;j++){
        if(j != i && !s)
            printf(" %s", argv[j]);
        else
            printf("%s", argv[j]);
    }
    if(!n)
        printf("\n");
}