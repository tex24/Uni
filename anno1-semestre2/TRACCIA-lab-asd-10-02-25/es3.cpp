#include "double-hash.h"
#include <iostream>

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

void insertElem(dllist &list, Elem e) {
    if (list == emptydllist) {
        // Caso lista vuota
        dllist aux = new cell;
        aux->prev = emptydllist;
        aux->next = emptydllist;
        aux->elem = e;
        list = aux;
        return;
    }

    dllist curr = list;

    // Scorri la lista per trovare la posizione corretta
    while (curr->next != emptydllist && curr->elem < e) {
        curr = curr->next;
    }

    if (curr->elem > e) {
        // Inserimento prima di `curr`
        dllist aux = new cell;
        aux->elem = e;
        aux->next = curr;
        aux->prev = curr->prev;

        if (curr->prev != emptydllist) {
            curr->prev->next = aux;
        } else {
            // Aggiorna l'inizio della lista
            list = aux;
        }

        curr->prev = aux;
    } else {
        // Inserimento in coda
        dllist aux = new cell;
        aux->elem = e;
        aux->next = emptydllist;
        aux->prev = curr;
        curr->next = aux;
    }
}

//Es 3
//Inserisce un nuovo elemento
void insert(dhash_table& dht,Elem e){
  unsigned int len1 = 0, len2 = 0;
  for(dllist curr = dht.T1[h1(e)]; curr!=emptydllist; curr = curr -> next){
    if(curr->elem == e)
      return;
    
      
    len1++;
  }
    
  for(dllist curr = dht.T2[h2(e)]; curr!=emptydllist; curr = curr -> next){
    if(curr->elem == e)
      return;
    len2++;
  }
  if(len2 < len1)
    insertElem(dht.T2[h2(e)], e);
  else
    insertElem(dht.T1[h1(e)], e);
}


