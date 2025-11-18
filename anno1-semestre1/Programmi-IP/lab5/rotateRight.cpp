#include "iostream"
#include "string"
using namespace std;

int main() {
    const int D = 5;
    int a[D];
    cout << "inserisci 5 numeri: " << endl;
    for(int i=0; i<D; i++){
        cin >> a[i];
    }
    cout << "[ ";
    for(int i=0; i<D; i++){
        cout << a[i];
        if (i != D-1) cout << ", ";
        else cout << " ]";
    }
    char appoggio = a[D-1];
    for(int i=D-1; i>0; i--){
        a[i] = a[i-1];
    }
    a[0] = appoggio;
    cout << " --> ";
    cout << "[ ";
    for(int i=0; i<D; i++){
        cout << a[i];
        if (i != D-1) cout << ", ";
        else cout << " ]" << endl;
    }


}