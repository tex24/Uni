#include <iostream>
using namespace std;

typedef struct Cell{
    int info;
    Cell *next;
}*List;


void insertElement(List &l, int n){
    if(!l){
        l = new Cell;
        l->info = n;
        l->next = nullptr;
        return;
    }
    List aux = new Cell;
    aux->info = n;
    if(l->info >= n){
        aux->next = l;
        l = aux;
        return;
    }
    List curr = l->next;
    List prev = l;
    
    while(curr){
        if(curr->info > n){
            aux->next = curr;
            prev->next = aux;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    aux->next = nullptr;
    prev->next = aux;
}

void insert(List &l, int a){
    if(!l){
        l = new Cell;
        l->info = a;
        l->next = nullptr;
    }else{
        if(l->info > a){
            List aux = new Cell;
            aux->info = a;
            aux->next = l;
            l = aux;
        }else
            insert(l->next, a);
    }
        
}

void printList(List l){
    if(!l)
        return;
    cout << l->info;
    if(l->next){
        cout << "->";
        printList(l->next);
    }
    else
        cout << endl;
}

int main(){

    return 0;
}