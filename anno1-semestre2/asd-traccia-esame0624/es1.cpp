#include "trinary-tree.h"

unsigned int nbOccurrence(Elem el,const triTree& tr){
  if(tr == emptyTriTree)
    return 0;
  if(tr->el == el)
    return 1 + nbOccurrence(el, tr->child1) + nbOccurrence(el, tr->child2) + nbOccurrence(el, tr->child3);
  return nbOccurrence(el, tr->child1) + nbOccurrence(el, tr->child2) + nbOccurrence(el, tr->child3);
}
