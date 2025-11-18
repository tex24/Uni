#include <iostream>
using namespace std;


int main ()
{
    int count = 0;
    const int N = 30;
    int item;
    int v[N];
    for (int i = 0; i < N; i++){
        v[i]=i;
    }
    int length = N;
    int first = 0;
    int last= length-1;
    int mid;
    bool found = false;
    cout << "Inserisci il numero da cercare: ";
    cin >> item;
    while(first<=last && !found) {
        mid = (first+last)/2;
        count++;
        if (v[mid] == item) {
            found = true;
        } else if (v[mid] > item) {
            last = mid - 1;
        } else
            first = mid + 1;
    }

    if (found == false) {
        cout << "il numero "<< item <<" non e' stato trovato" << endl;
    } else {
        cout << "Sono stati effettuati "<< count << " controlli." << endl;
    }
    return 0;
}