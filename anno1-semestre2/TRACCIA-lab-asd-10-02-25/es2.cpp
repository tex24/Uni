#include "double-hash.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 2
//Verifica se un elemento e' presente
bool isPresent(const dhash_table& dht,Elem e){
  for(int i=0; i < tableDim; i++){
    dllist curr1 = dht.T1[i];
    dllist curr2 = dht.T2[i];
    while(curr1 != emptydllist){
      if(curr1->elem == e)
        return true;
      curr1 = curr1->next;
    }
    while(curr2 != emptydllist){
      if(curr2->elem == e)
        return true;
      curr2 = curr2->next;
    }
  }
  return false;
}
