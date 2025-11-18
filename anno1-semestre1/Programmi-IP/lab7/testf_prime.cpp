#include <iostream>
using namespace std;

bool isPrime(int);

int main(){
	const int K = 10;
	int n[K] = {0, 2, 1, 5, 8, 6, 10, 11, 17, 15};
	for(int i=0; i<K; i++){
		cout << "il numero " << n[i];
		isPrime(n[i]) ? cout << " e' primo\n" : cout << " non e' primo\n";		
	}
	
}

bool isPrime(int n){
	if (n<2) return false;
	for(int i=2; i<n/2; i++)
		if(n%i == 0) return false;	
	return true;
}