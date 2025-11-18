#include <iostream>
using namespace std;

int main(){
    struct Time{
        unsigned int h;
        unsigned int m;
        unsigned int s;
    };
    bool minore = false;
    Time t1, t2;
    cout << "inserisci ore minuti e secondi del primo orario:" << endl;
    cout << "h: ";
    cin >> t1.h;
    cout << "m: ";
    cin >> t1.m;
    cout << "s: ";
    cin >> t1.s;
    cout << "inserisci ore minuti e secondi del secondo orario:" << endl;
    cout << "h: ";
    cin >> t2.h;
    cout << "m: ";
    cin >> t2.m;
    cout << "s: ";
    cin >> t2.s;

    if(t1.h > 23 or t1.h < 0 or t1.m > 59 or t1.m < 0 or t1.s > 59 or t1.s < 0){
        cout << "Il primo orario inserito non e corretto!\n";
        return 0;
    }
    if(t2.h > 23 or t2.h < 0 or t2.m > 59 or t2.m < 0 or t2.s > 59 or t2.s < 0){
        cout << "Il secondo orario inserito non e corretto!\n";
        return 0;
    }
    if(t1.h < t2.h) minore = true;
    else if(t1.h == t2.h){
        if(t1.m < t2.m) minore = true;
        else if(t1.m == t2.m){
            if(t1.s < t2.s) minore = true;
            else if(t1.s == t2.s){
                cout << "Sono trascorse 0 ore, 0 minuti e 0 secondi.\n";
            }
        }
    }
    if (minore) {
        int diffH = t2.h - t1.h;
        int diffM = t2.m - t1.m;
        int diffS = t2.s - t1.s;

        if (diffS < 0) {
            diffS += 60;
            diffM -= 1;
        }

        if (diffM < 0) {
            diffM += 60;
            diffH -= 1;
        }

        cout << "Sono trascorse " << diffH << " ore, " << diffM << " minuti e " << diffS << " secondi.\n";
    } else {
        cout << "Il primo orario è maggiore del secondo.\n";
    }

    return 0;
}