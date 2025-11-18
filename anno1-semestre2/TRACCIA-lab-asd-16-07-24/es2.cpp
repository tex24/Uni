#include "intpair-bst.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/
// Es 2
// Inserisce una nuova coppia di interi nell'albero
// Ritorna false, se la coppia e' gia' presente e in questo caso non la
// inserisce Altrimenti ritorna true

bool insertPair2(Elem v2, pairBstTree2 &pbst) {
  if (!pbst) {
    pairBstTree2 aux = new pairBstNode2;
    aux->el = v2;
    aux->left2 = emptyPairBstTree2;
    aux->right2 = emptyPairBstTree2;
    pbst = aux;
    return true;
  }
  if (pbst->el < v2)
    return insertPair2(v2, pbst->right2);

  if (pbst->el > v2)
    return insertPair2(v2, pbst->left2);

  return false;
}

bool insertPair(intpair p, pairBstTree &pbst) {
  if (!pbst) {
    pairBstTree aux = new pairBstNode;
    aux->el = p.v1;
    aux->left1 = emptyPairBstTree;
    aux->right1 = emptyPairBstTree;
    pbst = aux;
    return insertPair2(p.v2, pbst->bst2);
  }
  if (pbst->el < p.v1)
    return insertPair(p, pbst->right1);

  if (pbst->el > p.v1)
    return insertPair(p, pbst->left1);

  return insertPair2(p.v2, pbst->bst2);
}
