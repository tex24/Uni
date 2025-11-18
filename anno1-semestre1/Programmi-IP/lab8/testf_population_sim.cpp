#include <iostream>
using namespace std;

int population(int attuale, int nascite, int trasferiti) 
{	
    int media;
    media = attuale /100 * nascite;
    media += attuale /100 * trasferiti;
    
    if(attuale+media < 0) return 0;
    return attuale+media;
}

int main()
{
	int a=0, b=0, c=0;
	cout<<"Inserisci la popolazione attuale: "<<endl;
	cin>>a;
	cout<<"Inserisci la % nascite/morti: "<<endl;
	cin>>b;
	cout<<"Inserisci la % trasferiti: "<<endl;
	cin>>c;
	cout << "la popolazione attuale e': " << a << endl;
	cout << "la popolazione dopo un anno e': " << population(a, b, c) << endl;
}