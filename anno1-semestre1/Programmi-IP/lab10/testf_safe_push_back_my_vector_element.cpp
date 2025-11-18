#include <iostream>
#include <string>
#include "my_vector.h"

using namespace std;

int main() {
    my_vector v{};
    my_vector v1{};
    try {
        v = create_my_vector(2);
        safe_push_back_my_vector_element(v, 1.1);
        safe_push_back_my_vector_element(v, 2.2);
        safe_push_back_my_vector_element(v, 3.3); // Dovrebbe causare un resize
        print_my_vector_status(v); // Controlla il nuovo stato

    } catch (string s) {
        cout << s << endl;
    }
    try{
        safe_push_back_my_vector_element(v1, 1);
        print_my_vector_status(v1);
    } catch (string s) {
        cout << s << endl;
    }
    destroy_my_vector(v);
    destroy_my_vector(v1);
    return 0;
}