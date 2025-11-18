#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main(){
    char mossaU, mossaC;
    srand(time(NULL));
    int randomNumber;
    char isContinuo;
    int vittorie[] = {0, 0};
    do{
		while(true){
		   cout << "Giocatore inserici la tua mossa: carta(c), forbice(f), sasso(s): ";
		   cin >> mossaU;
		   //controllo mossa utente
		   if((mossaU == 'c' or mossaU == 'f' or mossaU == 's')){
			   break;
		   }else{
			   cout << "Input errati riprovate! \n";
		   }
		}
		//mossa del computer
		randomNumber = (rand()%3);
		if (randomNumber == 0) mossaC = 'f';
		else if (randomNumber == 1 ) mossaC = 'c';
		else mossaC = 's';
		   
		cout << "Il computer ha inserito: " << mossaC << endl;
		if(mossaU == mossaC){
			cout << "Pareggio!" << endl;
		}else if ((mossaU == 'f' && mossaC == 'c') || (mossaU == 'c' && mossaC == 's') || (mossaU == 's' && mossaC == 'f')){
			cout << "Hai vinto!" << endl;
			vittorie[1]++;
		} else {
			cout << "Ha vinto il computer!" << endl;
			vittorie[0]++;
		}
		
		cout << "se vuoi fare un altra mano digita s o S, altrimenti digita qualsiasi altro carattere." << endl;
		cin >> isContinuo;
    }while(isContinuo == 's' or isContinuo == 'S');

    cout << "Computer: " << vittorie[0] << endl << "Utente: " << vittorie[1] << endl;
    return 0;
}