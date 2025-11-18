#include <iostream>
#include "reverseArray_funct.h"
#include <string>


void reverseArray(int *source, int *dest, int size){
    if(source == dest) throw std::string("I due array corrispondono alla stessa area di memoria\n");
    for(int i=0, j=size-1; i<size; i++, j--){
        dest[j] = source[i];
    }
}

void printArray(int* s, int size) {
    std::cout<<"I valori contenuti nell'array sono: { ";
    for (int i = 0; i < size; i++) {
        std::cout << *(s);
        if(i != size-1) std::cout << ", ";
        s++;
    }
    std::cout << " }"<< std::endl;
}