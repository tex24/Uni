#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct esame{
    string nome;
    int CFU;
    bool superato;
    int voto;
};

typedef struct cell{
    int info;
    cell* next;
}*stack;

void push(stack &s, int elemento);
int pop(stack &s);

int pop(stack &s){
    if(!s)
        throw string("stack vuoto");
    stack aux = s;
    s = s->next;
    int ris = aux->info;
    delete aux;
    return ris;
}

bool secondYear(vector<esame> piano){
    int somma = 0;
    for(size_t i = 0; i<piano.size(); i++){
        if(piano[i].superato){
            somma += piano[i].CFU;
        }
    }
    if(somma >= 30)
        return true;
    return false;
}

double media(vector<esame> piano){
    int somma = 0;
    int sommaCFU = 0;
    for(size_t i = 0; i<piano.size(); i++){
        if(piano[i].superato){
            somma += piano[i].CFU * piano[i].voto;
            sommaCFU += piano[i].CFU;
        }
    }
    return (double) somma/sommaCFU;
}

int numBase(vector<char> a, unsigned start){
    if(start < a.size()) {
        if (a[start] == 'A' or a[start] == 'C' or a[start] == 'G' or a[start] == 'T')
            return 1 + numBase(a, start + 1);
        else
            return numBase(a, start + 1);
    }else{
        return 0;
    }
}


int main(){
    vector<esame> piano;
    vector<char> a = {'C', 'a', 'd', 'T', 'G', 'T', 'A', 'f'};
    cout << numBase(a, 1);
}

