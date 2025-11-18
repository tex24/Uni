#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
unsigned nbr;
char ⁎⁎ words;
} w_index;

void print_index(w_index *pi){
    for(unsigned i = 0; i < pi->nbr; i++){
        printf("%s", pi->words[i]);
    }

}

int mian(){
    w_index test;
    test.nbr = 4;
    for (unsigned i = 0; i < test.nbr; i++) {
        
    }
}