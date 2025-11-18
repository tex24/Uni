#include <iostream>
#include <string>
#include "my_vector.h"

using namespace std;

int main() {

    my_vector v = create_my_vector(5);
    safe_push_back_my_vector_element(v, 1.1);
    safe_push_back_my_vector_element(v, 2.2);
    print_my_vector_status(v);

    destroy_my_vector(v);
    print_my_vector_status(v);
    return 0;
}