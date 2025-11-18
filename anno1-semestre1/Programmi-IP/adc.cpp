#include <iostream>
#define l 8
int *H = (int *) malloc(l*l*sizeof(int)); //allocatelo direttamente in .data

int f1() {
    int i, j, k, t, u, m = 2;
    for (i = 0; i < l; i++)
        for (j = 0; j < l; j++) {
            if (i == 0 && j == 0) H[i*l+j] = 10;
            else for (k = 0; k <= 5; k++) {
                    t = 1<<k;
                    if (i >= t && j < t)
                        H[i*l+j] = H[(i - t)*l + j];
                }
        }
    u=0;
    for (k = 0; k < l*l; ++k){
        std::cout << H[k] << std::endl;
        u += H[k];
    }
    std::cout << "la u e " << u << std::endl;
    return k;
}

int main() {
    for (int k = 0; k < l*l; ++k){
        H[k] = 0;
    }
    int s;
    s = f1();
    std::cout << s; //equivale alla print_int
    exit(0);
}