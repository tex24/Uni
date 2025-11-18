#include <iostream>
using namespace std;

int getLength(int);

int main(){
	const int K = 10;
	int n[K] = {0, 266, 15, 5456, 8, 6, 1546540, 1661, 17, 165};
	for(int i=0; i<K; i++){
		cout << "la lunghezza di " << n[i] << " e' ";
		cout << getLength(n[i]) << endl;
	}
	
}

int getLength(int n){
	int i;
	if (n==0) return 1;
	for(i=0; n>0; i++){
		n/=10;
	}
	return i;
}                                           
