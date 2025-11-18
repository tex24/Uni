#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    const int N = 30;
    int item;
    cout << "Inserisci il numero da cercare in un array di " << N << " elementi dal valore di 0,..," << N-1 << ": ";
    cin >> item;
    int v[N];
    for (int i = 0; i < N; i++){
        v[i]=i;
    }
    bool found = false;

    for (int i = 0; i < N && !found; i++){
        count ++;
        if (v[i] == item){
            found = true;
        }else{
            ;
        }
    }
    if (found == false){
        cout << item << " non e' stato trovato" <<endl;
    } else {
        cout << "Sono stati effettuati " << count << " controlli." << endl;
    }
    return 0;
}