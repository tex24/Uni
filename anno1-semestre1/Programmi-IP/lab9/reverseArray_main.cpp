#include <iostream>
#include "reverseArray_funct.h"
#include <string>
using namespace std;

int main(){
    int source[5] = {3,2,3,5,6};
    int dest[5] = {0, 0, 0, 0, 0};

    printArray(source,5);
    printArray(dest,5);

    cout << endl;
    try{
        reverseArray(source, dest, 5);
        printArray(source,5);
        printArray(dest,5);
    }catch(const string& e){
        cout << e;
    }
}