#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int div = 1;
    int modulo = 10;
    int numero = 0;
    bool isPalindromo = true;
    vector<int> vettore;
    cout << "inserisci un numero un numero intero positivo: " << endl;
    cin >> n;

    while(true){
        vettore.insert(vettore.begin(), (n % modulo) / div);
        numero = n % modulo;
        if (numero == n) break;
        modulo *= 10;
        div *= 10;
    }

    for (int i=0; i < vettore.size() / 2; i++){
        if (vettore[i] != vettore[vettore.size()-1-i]){
            isPalindromo = false;
            break;
        }
    }
    if (isPalindromo) cout << "il numero " << n << " e palindromo.";
    else cout << "il numero " << n << " non e palindromo.";
}