// FILE DA MODIFICARE
#include "ASD-stack.h"

using namespace my_stack;

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/
/* restituisce lo stack vuoto */
Stack my_stack::createEmpty(){
   Stack sret;
   sret.size = 0;
   sret.maxsize = BLOCKDIM;
   sret.data = new Elem[sret.maxsize];
	return sret;
}

/* restituisce true se lo stack e' vuoto */
bool my_stack::isEmpty(const Stack& st){
   return !st.size;
}

/* aggiunge elem in cima (operazione safe, si può sempre fare) */
/* NB: se stack implementato con array dinamico, 
   quando necessario implementare ridimensionamento in espansione*/
void my_stack::push(const Elem el, Stack& st){
   if(st.size == st.maxsize){
      Elem *aux = new Elem[st.maxsize + BLOCKDIM];
      for(unsigned int i=0; i<st.size; i++){
         aux[i] = st.data[i];
      }
      delete [] st.data;
      st.data = aux;
   }
   st.data[st.size++] = el;
}

/* toglie dallo stack l'ultimo elemento e lo restituisce */
/* se lo stack è vuoto solleva una eccezione di tipo string */
/* NB: se stack implementato con array dinamico, 
   quando necessario implementare ridimensionamento in contrazione*/
Elem my_stack::pop(Stack& st){
   if(st.size == 0)
   throw std::string("Stack vuoto");
   return st.data[--st.size];
} 
