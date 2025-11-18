#include <iostream>
using namespace std;

int main(){
    const int N = 10;
    int source[N];
    int dest[N];
    cout << "inserisci " << N << " numeri interi:" << endl;
    for(int i=0; i<N; i++){
        cout << "Inserisci un valore intero per a[" << i << "] = ";
        cin >> source[i];
    }
    for(int i=0, j=N-1; i<N; i++, j--){
        dest[j] = source[i];
    }
    cout << endl << "array source: ";
    for(int i=0; i<N; i++){
        cout << source[i] << " ";
    }
    cout << endl << endl << "array dest (invertito): ";
    for(int i=0; i<N; i++){
        cout << dest[i] << (i == N-1 ? '\n' : ' ');
    }
}

