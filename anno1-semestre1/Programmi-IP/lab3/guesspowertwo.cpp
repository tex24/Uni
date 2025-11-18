#include <iostream>
using namespace std;

int main(){
    int n, quadrato, inserito;
    bool indovinato = false;
    cout << "inserisci un numero: ";
    cin >> n;
    quadrato = n*n;

    while(!indovinato){
        cout << endl << "indovina il quadrato: ";
        cin >> inserito;
        if (inserito == quadrato){
            indovinato = true;
            cout << "Bravo!";
        }else{
            cout << "sbagliato, riprova!" << endl;
        }
    }
}