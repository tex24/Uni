#include "intpair-bst.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
// Es 3
// Ritorna la coppia piu' piccola dell'albero
// Se l'albero e' vuoto, ritorna noPair

pairBstTree findMin(const pairBstTree &pbst) {
  if (!pbst)
    return emptyPairBstTree;
  if (pbst->left1 == emptyPairBstTree)
    return pbst;
  return findMin(pbst->left1);
}
pairBstTree2 findMin2(const pairBstTree2 &pbst) {
  if (!pbst)
    return emptyPairBstTree2;
  if (pbst->left2 == emptyPairBstTree2)
    return pbst;
  return findMin2(pbst->left2);
}
intpair minPaira(const pairBstTree &pbst) {
  if (!pbst)
    return noPair;
  intpair ris = noPair;
  pairBstTree min1 = findMin(pbst);
  pairBstTree2 min2 = findMin2(min1->bst2);
  ris.v1 = min1->el;
  ris.v2 = min2->el;
  return ris;
}

intpair minPair(const pairBstTree &pbst) {
  if (!pbst)
    return noPair;
  pairBstTree curr = pbst;
  while (curr->left1)
    curr = curr->left1;
  pairBstTree2 curr2 = curr->bst2;
  while (curr2->left2)
    curr2 = curr2->left2;
  intpair ris = noPair;
  ris.v1 = curr->el;
  ris.v2 = curr2->el;
  return ris;
}
