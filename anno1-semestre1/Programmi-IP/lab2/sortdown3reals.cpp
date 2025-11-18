#include <iostream>
using namespace std;

int main(){
    float a, b, c;
    cout << "inserisci tre numeri reali: \n";
    cin >> a >> b >> c;
    cout << "\n" << "ecco i tre numeri in ordine decrescente: ";

    if(a >= b && a >= c){
        cout << a << " ";
        if(b >= c){
            cout << b << " " << c;
        }else{
            cout << c << " " << b;
        }
    }else if(b >= a && b >= c){
        cout << b << " ";
        if(c >= a){
            cout << c << " " << a;
        }else{
            cout << a << " " << c;
        }
    }else{
        cout << c << " ";
        if(a >= b){
            cout << a << " " << b;
        }else{
            cout << b << " " << a;
        }
    }
    return 0;

}