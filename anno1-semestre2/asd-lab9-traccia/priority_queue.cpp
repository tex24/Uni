/**************************************************************************/
/*          Coda con priorita' implementata come heap binario             */
/**************************************************************************/

#include "priority_queue.h"


// Funzioni ausiliarie che non appartengono al TDD 

// tra i due indici, restituisce quello che corrisponde al timestamp inferiore
int minTimeStamp(priorityQueue::PriorityQueue pq, int index1, int index2)
{
  if (index1 >= pq.size && index2 >= pq.size)
    // entrambi gli indici sono fuori dal limite dello heap
    return -1; 
  if (index1 >= pq.size)
    // il primo e' fuori, restituisco il secondo
    return index2;
  if (index2 >= pq.size)
    // il secondo e' fuori, restituisco il primo
    return index1;
      
  // entrambi sono dentro lo heap, scelgo quello con timestamp inferiore
  if (pq.data[index1].timeStamp < pq.data[index2].timeStamp)
    return index1; 
    else return index2;
}


//void moveDown(...) {// TODO}

//void moveUp(...) {// TODO}


// Funzioni del TDD PriorityQueue

// crea una PriorityQueue di dimensione dim
priorityQueue::PriorityQueue priorityQueue::createEmptyPQ(int dim) {
  PriorityQueue pq;
  pq.size = 0;
  pq.maxsize = dim;
  pq.data = new Elem[dim];
  return pq;
}

// verifica se una PriorityQueue e' vuota
bool priorityQueue::isEmpty(const PriorityQueue &pq)
{
  return (pq.size == 0);
} 

void moveUp(priorityQueue::Elem* e, int pos){
  if(pos != 0 && e[pos].timeStamp < e[(pos-1)/2].timeStamp){
    priorityQueue::Elem aux = e[pos];
    e[pos] = e[(pos-1)/2];
    e[(pos-1)/2] = aux;
    moveUp(e, (pos-1)/2);
  }
}

void moveDown(priorityQueue::Elem* e, int pos, priorityQueue::PriorityQueue &pq){
  int son = pos*2;
  if(son+1 < pq.size && e[pos].timeStamp > e[son+1].timeStamp){
    priorityQueue::Elem aux = e[pos];
    e[pos] = e[son+1];
    e[son+1] = aux;
    moveDown(e, son+1, pq);
  }else if(son+2 < pq.size && e[pos].timeStamp > e[son+2].timeStamp){
    priorityQueue::Elem aux = e[pos];
    e[pos] = e[son+2];
    e[son+2] = aux;
    moveDown(e, son+2, pq);
  }
}
// inserisce un Elem in una PriorityQueue (nella posizione corretta) e ritorna TRUE
// nel caso in cui la PriorityQueue sia piena ritorna FALSE
// suggerimento: inserire in fondo e poi chiamare la funzione ausiliaria moveUp(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::insert(PriorityQueue &pq, const Elem &elem) {
  if(pq.size == pq.maxsize)
    return false;
  pq.data[pq.size++] = elem;
  moveUp(pq.data, pq.size-1);
  return true;
}

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE e l'Elem minimo nella PriorityQueue in res
// (cioe' quello radice in posizione 0)
bool priorityQueue::findMin(const PriorityQueue &pq, Elem &res) {
  if(pq.size == 0)
    return false;
  res = pq.data[0];
  return true;
}

// ritorna FALSE se PriorityQueue e' vuota 
// altrimenti TRUE ed elimina l'Elem minimo nella PriorityQueue
// (cioe' quello radice in posizione 0)
// suggerimento: sostituiamo la radice dell'albero con l'ultimo elemento
//   e poi chiamare la funzione ausiliaria moveDown(...)
//   per ripristinare proprieta' dell'ordinamento a heap
bool priorityQueue::deleteMin(PriorityQueue &pq) {  
  if(pq.size == 0)
    return false;
  pq.data[0] = pq.data[--pq.size];
  moveDown(pq.data, 0, pq);
  return true;
}