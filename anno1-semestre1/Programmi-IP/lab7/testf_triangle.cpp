#include <iostream>
using namespace std;

void triangle(int);

int main(){
	int n;
	cout << "inserisci un numero: ";
	cin >> n;
	cout << endl;
	triangle(n);	
}

void triangle(int n){
	string s = "";
	for(int i=0; i<n; i++){
		s += '*';	
		cout << s << endl;
	}
}
