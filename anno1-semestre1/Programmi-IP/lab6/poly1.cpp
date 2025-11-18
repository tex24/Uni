#include <iostream>
#include <cmath>
using namespace std;

int main(){
    struct Point{
        double x;
        double y;
    };
    bool uguali = true;
    bool poligono = false;
    const int N = 5;
    double somme[N-1];
    Point a[N];
    for(int i=0; i<N; i++){
        cout << "inserisci x e y del punto " << i+1 << ":\n";
        cin >> a[i].x >> a[i].y;
    }
    for(int i=0; i<N-1; i++){
        somme[i] = sqrt(pow((a[i+1].x - a[i].x), 2) + pow((a[i+1].y - a[i].y), 2));
    }
    cout << endl;
    for(int i=0; i<N-2; i++){
        if (somme[i] != somme[i+1]) uguali = false;
    }
    if(a[0].x == a[N-1].x and a[0].y == a[N-1].y) poligono = true;

    if(poligono){
        cout << "La linea viene chiusa e quindi definisce un poligono ";
        if(uguali) cout << "regolare\n";
        else cout << endl;
    }else cout << "la linea viene aperta quindi NON definisce un poligono\n";
}
