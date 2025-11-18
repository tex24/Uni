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

int population2(int attuale, int nascite, int trasferiti, int anni) 
{	
	for(int i=0; i< anni; i++){
		attuale = population(attuale, nascite, trasferiti);	
	}
	return attuale;
}

int main()
{
	int a, b, c, d;
	cout<<"Inserisci la popolazione attuale: "<<endl;
	cin>>a;
	cout<<"Inserisci la % nascite/morti: "<<endl;
	cin>>b;
	cout<<"Inserisci la % trasferiti: "<<endl;
	cin>>c;
	cout<<"Inserisci gli anni: "<<endl;
	cin>>d;
	cout << "la popolazione attuale e' " << a << endl;
	cout << "la popolazione dopo " << d << " anni e' " << population2(a, b, c, d) << endl;
}