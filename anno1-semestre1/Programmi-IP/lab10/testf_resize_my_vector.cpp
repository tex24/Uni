#include <iostream>
#include <string>
#include "my_vector.h"

using namespace std;

int main() {
    my_vector v{};
    try {
        my_vector v = create_my_vector(5);
        safe_push_back_my_vector_element(v, 1.1);
        safe_push_back_my_vector_element(v, 2.2);
        safe_push_back_my_vector_element(v, 3.3);
        print_my_vector_status(v);

        resize_my_vector(v, 2); // Riduce la capacità
        print_my_vector_status(v);

        resize_my_vector(v, 6); // Aumenta la capacità
        print_my_vector_status(v);

        resize_my_vector(v, 0);
        print_my_vector_status(v);


    } catch (string s) {
        cout << s << endl;
    }
    destroy_my_vector(v);
    return 0;
}