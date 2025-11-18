#include <iostream>
#include <string>
#include "my_vector.h"

using namespace std;

int main() {
        my_vector v{};
        my_vector c{};
    try {
        v = create_my_vector(5);
        safe_push_back_my_vector_element(v, 1.1);
        safe_push_back_my_vector_element(v, 2.2);
        print_my_vector_status(v);

        double value = get_my_vector_element(v, 0);
        cout << "Elemento a indice 0: " << value << endl;

        value = get_my_vector_element(v, 1);
        cout << "Elemento a indice 1: " << value << endl;


        value = get_my_vector_element(v, 2);
        cout << "Elemento a indice 2: " << value << endl;


    } catch (string s) {
        cout << s << endl;

    }
    try{
        c = create_my_vector(5);
        double value = get_my_vector_element(c, 1);
        cout << "Elemento a indice 1: " << value << endl;

    } catch (string s) {
        cout << s << endl;

    }
    destroy_my_vector(v);
    destroy_my_vector(c);
    return 0;
}