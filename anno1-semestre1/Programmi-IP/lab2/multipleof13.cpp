#include "iostream";
using namespace std;

int main(){
    int a;
    cout << "inserisci un numero intero: \n";
    cin >> a;
    cout << endl;
    if (a % 13 == 0){
        cout << a << " e divisibile per 13";
    }else{
        cout << a << " non e divisibile per 13";
    }

    return 0;
}