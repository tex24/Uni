#include "iostream"
#include "string"
using namespace std;

int main(){
    int n;
    string ris;
    int modulo = 10;
    cout << "inserisci un numero intero: ";
    cin >> n;
    cout << endl;
    while(n > 0){
        ris += to_string(n % modulo);
        n = n / modulo;
    }
    char appoggio;
    for(size_t i=0; i<ris.length()/2; i++){
        appoggio = ris[i];
        ris[i] = ris[ris.length()-1-i];
        ris[ris.length()-1-i] = appoggio;
    }

    cout << "il numero scritto in stringa: " << ris << endl;
}
