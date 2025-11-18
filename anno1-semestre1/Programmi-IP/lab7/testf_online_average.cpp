#include <iostream>
using namespace std;


double onlineAverage(){
	char continua = 'y';
	double n;
	double somma;
	int i=0;
	while(continua == 'y'){
		cout << "inserisci un numero reale: ";
		cin >> n;
		somma += n;
		i++;
		cout << "se vuoi continuare a inserire numeri digita y, se vuoi smettere digita n: ";
		cin >> continua;
	}
	return somma/i;
}                                           


int main(){
	cout << onlineAverage() << endl;
}
