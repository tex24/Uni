#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int tavolaPitagorica[N][N];
    int n1 = 0, n2 = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tavolaPitagorica[i][j] = (j+1)*(i+1);
        }
    }
    cout << "inserisci una coppia di valori tra 1 e 10 per ottenere il prodotto:" << endl;
    cin >> n1 >> n2;
    while(n1 < 1 or n1 > 10 or n2 < 1 or n2 > 10){
        cout << "Numeri al di fuori del range, riprova." << endl;
        cin >> n1 >> n2;
    }

    cout << "prodotto: " << tavolaPitagorica[n1-1][n2-1] << endl;

}