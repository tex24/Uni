#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
	double x, y;
};

double dist(Punto p1, Punto p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}                                           


int main(){
	const int N = 3;
	Punto a[N];
	int somma = 0;
	for(int i=0; i<N; i++){
		cout<<"Inserisci P1 \n";
		cout << "x: ";
		cin>>a[i].x;
		cout << "y: ";
		cin>>a[i].y;
	}
	
	for(int i=0; i<N-1; i++){
		somma += dist(a[i], a[i+1]);
	}
	
	


	cout << "la somma della spezzata e' " << somma << endl;
}
