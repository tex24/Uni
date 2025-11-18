#include <iostream>
using namespace std;

typedef struct Cell{
    int info;
    Cell *next;
    Cell *prev;
}*List;


void printList(List l){
    List curr = l;
    while(curr){
        cout << curr->info;
        if(curr->next)
            cout << ", ";
        curr = curr->next;
    }
    cout << endl;
}

void printListReverse(List l){
    while(l->next)
        l = l->next;
    while(l){
        cout << l->info;
        if(l->prev)
            cout <<", ";
        l = l->prev;
    }
    cout << endl;
}

void insertElement(List &l, int n){
    Cell *cell = new Cell;
    if(!l){
        cell->next = nullptr;
        cell->prev = nullptr;
        cell->info = n;
        l=cell;
    }else{
        l->prev = cell;
        cell->next = l;
        cell->prev = nullptr;
        cell->info = n;
        l = cell;
    }
}

void insertOrder(List &l, int n){
    if(!l){
        l = new Cell;
        l->next = nullptr;
        l->prev = nullptr;
        l->info = n;
        return;
    }
    if(l->info > n){
        insertElement(l, n);
        return;
    }

    List curr = l;
    Cell *cell = new Cell;
    cell->info = n;
    while(curr->next){
        if(curr->info > n){
            cell->next = curr;
            cell->prev =curr->prev;
            curr->prev->next = cell;
            curr->prev = cell;
            return;
        }
        curr = curr->next;
    }
    if(curr->info > n){
        cell->next = curr;
        cell->prev =curr->prev;
        curr->prev->next = cell;
        curr->prev = cell;
    }else{
        curr->next = cell;
        cell->next = nullptr;
        cell->prev = curr;
    }
}

void recoursive(List &l, int n){
    if(!l){
        l = new Cell;
        l->next = nullptr;
        l->info = n;
    }else if(l->info >= n){
        Cell *cell = new Cell;
        cell->info = n;
        cell->next = l;
        cell->prev = l->prev;
        cout << l->prev << " " << l->info << endl;
        l->prev = cell;
        if(cell->prev) {
            cell->prev->next = cell;
        }
    }else{
        recoursive(l->next, n);
    }

}

void insertHead(List &l, int n){
    List cell = new Cell;
    cell->info = n;
    if(!l){
        cell->next = nullptr;
        cell->prev = nullptr;
        l = cell;
    }else{
        cell->prev = nullptr;
        cell->next = l;
        l->prev = cell;
        l = cell;
    }
}

int main(){
    List l = nullptr;
    insertHead(l, 2);
    insertHead(l, 6);
    insertHead(l, 3);


    printList(l);
    printListReverse(l);
}