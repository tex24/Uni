#include "intpair-bst.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
//Es 1
//Ritorna il numero di coppie nel albero
unsigned int nbPairs2(const pairBstTree2& pbst){
  if(!pbst)
    return 0;
  return 1 + nbPairs2(pbst->left2) + nbPairs2(pbst->right2);
}

unsigned int nbPairs(const pairBstTree& pbst){
  if(!pbst)
    return 0;
  return nbPairs2(pbst->bst2) + nbPairs(pbst->left1) + nbPairs(pbst->right1);
}
