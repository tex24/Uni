#include <iostream>
#include "printArray_funct.h"
using namespace std;

void printArray(int* s, int size) {
	cout<<"I valori contenuti nell'array sono (aritemtica puntatori): { ";
    for (int i = 0; i < size; i++) {
        cout << *(s);
        if(i != size-1) cout << ", ";
        s++;
    }
    cout << " }"<< endl;
}

void printArrayWithIndex(int s[], int size){
	cout<<"I valori contenuti nell'array sono (indice):               { ";
    for (int i = 0; i < size; i++) {
        cout << s[i];
        if(i != size-1) cout << ", ";
    }
    cout << " }"<< endl;
}
