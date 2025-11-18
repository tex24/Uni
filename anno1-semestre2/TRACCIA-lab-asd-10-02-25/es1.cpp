#include "double-hash.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di elementi nella tabella
unsigned int nbElem(const dhash_table& dht){
  int ris = 0;
  for(int i=0; i < tableDim; i++){
    dllist curr1 = dht.T1[i];
    dllist curr2 = dht.T2[i];
    while(curr1 != emptydllist){
      ris++;
      curr1 = curr1->next;
    }
    while(curr2 != emptydllist){
      ris++;
      curr2 = curr2->next;
    }
  }
  return ris;
}


