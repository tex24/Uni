#include "tragitto.h"

// verifica se un Tragitto e vuoto
bool tragitto::isEmpty(Tragitto tr) {
  return (tr == tragittoVuoto);
}

// inserisce una Tappa in un Tragitto
void tragitto::insert(Tragitto &tr, Tappa t) {
  Tragitto aux = new TragittoElem;
  aux->tappa = t;
  aux->next = tragittoVuoto;
  if(isEmpty(tr)){
    tr = aux;
    return;
  }
  Tragitto curr = tr;
  while(!isEmpty(curr->next)){
    curr = curr->next;
  }
  curr->next = aux;
}

// ritorna FALSE se il Tragitto e vuoto
// altrimenti rimuove la prima Tappa del Tragitto 
//    e la assegna al secondo parametro e ritorna TRUE
bool tragitto::extract(Tragitto &tr, Tappa &t) {
  if(isEmpty(tr))
    return false;
  Tragitto aux = tr->next;
  t = tr->tappa;
  delete tr;
  tr = aux;
  return true;
}

// stampa un Tragitto (formato: N volte [distanza citta'])
void printTragitto(tragitto::Tragitto tr) {
  // TO DO
}
