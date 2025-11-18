#include "iostream";
using namespace std;

int main(){
    char mossa1, mossa2;
    while(true){
       cout << "Giocatore 1 inserici la tua mossa: carta(c), forbice(f), sasso(s): ";
       cin >> mossa1;
       cout << endl;
       cout << "Giocatore 2 inserici la tua mossa: carta(c), forbice(f), sasso(s): ";
       cin >> mossa2;
       cout << endl;
       if((mossa1 == 'c' or mossa1 == 'r' or mossa1 == 's') and (mossa2 == 'c' or mossa2 == 'r' or mossa2 == 's')){
           break;
       }else{
           cout << "Input errati riprovate! \n";
       }
    }
    if(mossa1 == mossa2){
        cout << "Pareggio!";
    }else if ((mossa1 == 'f' && mossa2 == 'c') || (mossa1 == 'c' && mossa2 == 's') || (mossa1 == 's' && mossa2 == 'f')){
        cout << "Giocatore 1 hai vinto!" << endl;
    } else {
        cout << "Giocatore 2 hai vinto!" << endl;
    }

    return 0;
}