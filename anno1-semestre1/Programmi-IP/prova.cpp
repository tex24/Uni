#include <iostream>
#include <string>
using namespace std;

struct Cell{
    Cell *next;
    string info;
};

typedef struct
cell {
    int head;
    cell *next;
} *lista;

string toString(Cell *a){
    if(a != nullptr)
        return a->info + toString(a->next);
    else
        return "";
}

int size(Cell *a){
    if(a != nullptr)
        return 1 + size(a->next);
    else
        return 0;
}

float adv(float a[], int size){
    if(size == 0)
        throw string("array vuoto");
    if(size == 1)
        return a[0]/size;
    else
        return a[size-1]/size + adv(a, size-1);
}


void insert(lista &l, int value){
    if(!l){
        l = new cell;
        l->head = value;
        l->next = nullptr;
        return;
    }
    if(l->head > value){
        lista aux = new cell;
        aux->head = value;
        aux->next = l;
        l = aux;
    }else
        insert(l->next, value);
}

void del(lista &l, int value){
    if(!l)
        return;
    if(l->head == value){
        lista aux = l;
        l = l->next;
        delete aux;
        return;
    }else if(l->head > value)
        return;
    else
        del(l->next, value);
}

void aggiungiElemento(lista &l, int valore){
    if(l == nullptr){
        lista aux = new cell;
        aux->next = nullptr;
        aux->head = valore;
        l = aux;
        return;
    }
    lista cur = l;
    bool entrato = false;
    lista previous = l;

    if(l->head>valore){
        lista aux = new cell;
        aux->head = valore;
        aux->next = l;
        l=aux;
        return;
    }

    while(cur!=nullptr){

        if(valore<cur->head){//oppure *cur.info
            entrato = true;
            lista aux = new cell;
            aux->head = valore;
            aux->next = cur;
            previous->next= aux;
            return;
        }
        previous = cur; //punta alla casella prima di cur perché nella riga dopo cur lo aumentiamoc(cur=cur->next) passando all'elemento successivo
        cur=cur->next;
    }
    if (entrato==false) {
        lista aux = new cell;
        aux->head = valore;
        aux->next = nullptr;
        previous->next = aux;
    }
}

void elimina(lista &l){
    if(!l)
        return;
    lista aux = l;
    l = l->next;
    delete aux;
    elimina(l);
}

void de(lista &l) {
    while(l) {
        if(!l->next) {
            delete l;
            l = nullptr;
        }else {
            lista curr = l->next;
            lista previous = l;
            while(curr->next) {
                curr = curr->next;
                previous = previous->next;
            }
            previous->next = nullptr;
            delete curr;
        }
    }
}




// stampa tutti i valori (data) degli elementi della lista ordinata l in linea separati da "->"
void printList(const lista &l){
    if(l){
        cout << l->head;
        if(l->next)
            cout << "->";
        printList(l->next);
    }
    else
        cout << endl;
}

int main(){
    /*Cell *primo, *secondo = nullptr;
    primo = new Cell;
    primo->info = "ciao ";
    primo->next = new Cell;
    primo->next->info = "a ";
    primo->next->next = new Cell;
    primo->next->next->info = "tutti ";
    primo->next->next->next = new Cell;
    primo->next->next->next->info = "ragazzi!";
    primo->next->next->next->next = nullptr;
    cout << toString(primo);
    cout << endl << size(primo);
    cout << endl << toString(secondo) << endl << size(secondo);*/
    lista lista1 = nullptr;

    aggiungiElemento(lista1, 4);
    aggiungiElemento(lista1, 1);
    aggiungiElemento(lista1, 5);
    aggiungiElemento(lista1, 1);

    printList(lista1);
    de(lista1);
    printList(lista1);
 /*   del(lista1, 5);
    printList(lista1);
    del(lista1, 1);
    printList(lista1);
    del(lista1, 1);
    printList(lista1);
    del(lista1, 4);
    printList(lista1);
    del(lista1, 4);
    printList(lista1);*/


}