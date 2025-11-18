#include <iostream>
#include "printArray_funct.h"
using namespace std;

int main(){
    int a[5] = {3,2,3,5,6};
    int b[1] = {1};
    int c[0];
    printArray(a,5);
    printArrayWithIndex(a,5);
    printArray(b,1);
    printArrayWithIndex(b,1);
    printArray(c,0);
    printArrayWithIndex(c,0);
}