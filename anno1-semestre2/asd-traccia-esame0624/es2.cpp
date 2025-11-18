#include "trinary-tree.h"

void deleteSon(Elem el, int sonNumber, triTree& tr){
  if(tr == emptyTriTree)
    return;
  deleteSon(el, 1, tr->child1);
  deleteSon(el, 2, tr->child2);
  deleteSon(el, 3, tr->child3);
  if(tr->el == el){
    triTree aux = tr;
    if(sonNumber == 1)
      tr = tr->child1;
    if(sonNumber == 2)
      tr = tr->child2;
    if (sonNumber == 3) 
      tr = tr->child3;
    delete aux;
  }
}

void deleteAll(Elem el, triTree& tr){
  deleteSon(el, 2, tr);
}

