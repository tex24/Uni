// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include "ASD-doubly-linked-list.h"

using namespace list;
using namespace std;

/*Descrizione da come e' fatta  la struttura node. */
/*I dettagli interni non saranno visibili dal main*/
struct list::node {  
  Elem info;
  node *prev;
  node *next;
};

/**************************************************/
/*      funzioni da implementare                    */
/**************************************************/
  
/* crea la lista vuota */
void list::createEmpty(List& li){
    li = new node;
    li->prev = li;
    li->next = li;
}

/* "smantella" la lista (tranne la sentinella) */
void list::clear(List& li){
    List last = li->prev;
    if(last == li)
        return;
    while(last != li){
        li->prev = last->prev;
        delete last;
        last = li->prev;
    }
    li->next = li;
    li->prev = li;
}

/* restituisce true se la lista e' vuota */
bool list::isEmpty(const List& li){
    return (li->next == li);
}

/* restituisce la dimensione della lista */
unsigned int list::size(const List& li){
    List curr = li->next;
    int ris = 0;
    while(curr != li){  // Fixed termination condition
        ris++;
        curr = curr->next;
    }
    return ris;
}

/* restituisce l'elemento in posizione pos */
/* se pos non e corretta, solleva una eccezione di tipo string*/
Elem list::get(unsigned int pos, const List& li){
    List curr = li->next;
    unsigned int i = 0;
    while(i < pos){
        if(curr == li)
            throw string("errore");
        curr = curr->next;
        i++;
    }
    if(curr != li)
        return curr->info;
    else
        throw string("errore");
}

/* modifica l'elemento in posizione pos */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::set(unsigned int pos, Elem el, const List& li){
    List curr = li->next;
    unsigned int i = 0;
    while(i < pos){
        if(curr == li)
            throw string("errore");
        curr = curr->next;
        i++;
    }
    if(curr != li)
        curr->info = el;
    else
        throw string("errore");
}

/* inserisce l'elemento in posizione pos*/
/*shiftando a destra gli altri elementi */
/*se pos non e' corretta, solleva una eccezione di tipo string*/
void list::add(unsigned int pos, Elem el, const List& li){
  List curr = li;
  unsigned int i = 0;
  while (i <= pos){
      curr = curr->next;
      if(curr == li && i < pos)
          throw string("errore");
      i++;
  }
  List aux = new node;
  aux->info = el;
  aux->next = curr;
  aux->prev = curr->prev;
  curr->prev->next = aux;
  curr->prev = aux;

}
/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem el, const List& li){
	List aux = new node;
  aux->info = el;
  aux->next = li;
  aux->prev = li->prev;
  li->prev->next = aux;
  li->prev = aux;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem el, const List& li) {
	List aux = new node;
  aux->info = el;
  aux->prev = li;
  aux->next = li->next;
  li->next = aux;
  aux->next->prev = aux;
}

/* cancella l'elemento in posizione pos dalla lista */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::removePos(unsigned int pos,const List& li){
  List curr = li;
  for(unsigned int i=0; i<=pos; i++){
    curr = curr->next;
    if(curr == li)
      throw string("Errore");
  }
  curr->prev->next = curr->next;
  curr->next->prev = curr->prev;
  delete curr;
}

/* cancella tutte le occorrenze dell'elemento elem*/
/*se presenti, dalla lista */
void list::removeEl(Elem el,const List& li){
	List curr = li->next;
  while(curr != li){
    if(curr->info == el){
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      List aux = curr;
      curr = curr->next;
      delete aux;
    }else
      curr = curr->next;
  }
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
  
/* riempie una lista da file */
void list::readFromFile(string name_file, const List& li){
  ifstream infile;
  string read_data;
  infile.open(name_file);
  while (getline (infile,read_data)){
    if(read_data.length()>0){
      addRear(stoi(read_data),li);
    }
  }
}

/* riempie una lista da standard input */
void list::readFromStdin(const List& li){
  cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
  string read_data;
  cin>>read_data;
  while(read_data!="END"){
    addRear(stoi(read_data),li);
    cin>>read_data;
  }
}

/* stampa la lista */
void list::print(const List& li){
  if(li==li->next){
    cout<<"vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    cout << cur->info;
    cur= cur->next;
    if(cur!=li) cout<<" <-> ";
  }
  cout<<endl;
}

/* produce una string contenendo la lista*/
std::string list::tostring(const List& li){
  string out="";
  if(li==li->next){
    out+="vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    out+=to_string(cur->info);
    cur= cur->next;
    if(cur!=li) out+=" <-> ";
  }
  return out;
}
