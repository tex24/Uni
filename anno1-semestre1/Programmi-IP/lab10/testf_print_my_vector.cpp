#include <iostream>
#include <string>
#include "my_vector.h"
using namespace std;

int main(){
    my_vector v{};
    my_vector v1{};
    my_vector v2{};
    try{
        v = create_my_vector(10);
        print_my_vector_status(v);
        v1 = create_my_vector(5);
        print_my_vector_status(v1);
        v2 = create_my_vector(0);
        print_my_vector_status(v2);
    }catch(string s){
        cout << s << endl;
    }
    destroy_my_vector(v);
    destroy_my_vector(v1);
    destroy_my_vector(v2);
}