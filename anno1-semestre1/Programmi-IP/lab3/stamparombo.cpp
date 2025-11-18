#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cout << "inserisci un numero intero positivo: ";
	cin >> n;
	vector<char> stringa;
	for(int i=0; i<2*n+1;i++)
	{
		stringa.push_back(' ');
	}
	stringa[n] = '*';
	int i;
	for(i = 0; i <= n; i++)
	{
		stringa[n+i]='*';
		stringa[n-i]='*';
		for (char c : stringa) {
            cout << c;
        }
		cout << endl;
	}
	for (i=i-1; i>0; i--)
	{
		stringa[n+i] = ' ';
		stringa[n-i] = ' ';
		for (char c : stringa) {
            cout << c;
        }
        cout << endl;
	}
}