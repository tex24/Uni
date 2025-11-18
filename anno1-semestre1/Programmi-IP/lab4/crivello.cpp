#include <iostream>

int main(){
    const int n = 1000;
    bool isprime[n];
    for (int i = 0; i < n; ++i) {
        isprime[i] = true;
    }

    // 2) Inizialmente, sia p pari a 2
    isprime[0] = isprime[1] = false;
    int p = 2;

    // 3) Algoritmo del Crivello di Eratostene
    while (p * p < n) {
        if (isprime[p]) {
            for (int i = 2 * p; i < n; i += p) {
                isprime[i] = false;
            }
        }
        // 4) Trovare il prossimo numero non marcato
        do {
            p++;
        } while (p < n && !isprime[p]);
    }

    // 5) Stampare tutti i numeri primi
    std::cout << "Numeri primi minori di " << n << ":\n";
    for (int i = 2; i < n; ++i) {
        if (isprime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
