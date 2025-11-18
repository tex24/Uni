#include <iostream>
#include <exception>
#include <string>
using namespace std;

void computeRectInfo(double l1, double l2, double &area, double &perimetro){
    if (l1 < 0 and l2 < 0)
        throw string("Lunghezza e altezza negativi.");
    if (l1 < 0)
        throw string("Lunghezza negativa.");
    if (l2 < 0)
        throw string("Altezza negativa.");

    perimetro = l2*2 + l1*2;
    area = l1*l2;
}

int main(){
    double area, perimetro, altezza, lunghezza;
    cout << "Inserisci i due lati del rettangolo:" << endl;
    cout << "Altezza: ";
    cin >> altezza;
    cout << "Lunghezza: ";
    cin >> lunghezza;
    try{
        computeRectInfo(lunghezza, altezza, area, perimetro);
        cout << "Il rettangolo ha area: " << area << ", e perimetro " << perimetro << endl;
    }catch(string s){
        cout << "Error: " << s << endl;
    }

}