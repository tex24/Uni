#include "iostream"
#include "string"
using namespace std;

int main(){
    string str;
    char appoggio;
    cout << "inserisci una stringa: ";
    getline(cin, str);

    for(size_t i = 0; i < str.length() / 2; i++){
        appoggio = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = appoggio;
    }

    cout << endl << "la stringa invertita: " << str << endl;
}
