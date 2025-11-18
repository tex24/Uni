#include <iostream>
#include <string>
#include "my_vector.h"

using namespace std;

int main() {
    my_vector v{};

    try {
        v = create_my_vector(5);
        safe_push_back_my_vector_element(v, 1.1);
        safe_push_back_my_vector_element(v, 2.2);
        print_my_vector_status(v);

        set_my_vector_element(v, 9.9, 0);
        set_my_vector_element(v, 8.8, 1);
        print_my_vector_status(v);

        set_my_vector_element(v, 20, 3);
        print_my_vector_status(v);
    } catch (string s) {
        cout << s << endl;
    }
    destroy_my_vector(v);
    return 0;
}