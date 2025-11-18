#include <iostream>
#include <string>
#include "my_vector.h"

using namespace std;

my_vector create_my_vector(unsigned int capacity){
  if(capacity <= 0)
  	  throw string("create_my_vector: capacity fornita non positiva");
  	double* c(new double[capacity]);
    my_vector v={0,capacity,c};
  return v;
}

void print_my_vector_status(const my_vector &v){
  cout << "**********************" << endl;
  cout << "my_vector size = " << v.size << endl;
  cout << "my_vector capacity = " << v.capacity << endl;
  cout << "my_vector store = { ";
  for(unsigned int i=0; i<v.size; i++){
  	cout << v.store[i];
  	if(i != v.size-1){
  		cout << ",";
  	}
  	cout << " ";
  }
  cout << "}" << endl;
  cout << "**********************" << endl;
}

void push_back_my_vector_element(my_vector &v, double x){
  if(v.size == v.capacity)
  	  throw string("push_back_my_vector_element: Impossibile inserire elemento in Array pieno");
  v.store[v.size++] = x;
}

double pop_back_my_vector_element(my_vector &v){
  if(v.size == 0)
  	  throw string("pop_back_my_vector_element: Impossibile estrarre elemento da Array vuoto"); 
  v.size--;
  return v.store[v.size];
}

void set_my_vector_element(my_vector &v, double value, unsigned int index){
  if(v.size == 0)
  	  throw string("set_my_vector_element: Impossibile impostare un elemento di un My_Vector vuoto");
  if( index >= v.size)
  	  throw string("set_my_vector_element: Indice fornito non ammissibile");
  v.store[index] = value;
}


double get_my_vector_element(const my_vector &v, unsigned int index){
  if(v.size == 0)
  	  throw string("get_my_vector_element: Impossibile leggere un elemento di un My_Vector vuoto");
  if( index >= v.size)
  	  throw string("get_my_vector_element: Indice fornito non ammissibile");
  return v.store[index];
}

void resize_my_vector(my_vector &v, unsigned int new_capacity) {
    if (new_capacity == 0)
        throw std::string("resize_my_vector: new_capacity fornita non positiva");

    double* c = new double[new_capacity];
    if (v.size > 0) {
        unsigned int limit = (v.size > new_capacity) ? new_capacity : v.size;
        for (unsigned int i = 0; i < limit; i++) {
            c[i] = v.store[i];
        }
        v.size = limit;
    }

    delete[] v.store;
    v.store = c;
    v.capacity = new_capacity;
}


void safe_push_back_my_vector_element(my_vector &v, double x){
  try{
  	  push_back_my_vector_element(v, x);
  }catch(string s){
  	  if(v.capacity == 0)
  	  	  resize_my_vector(v, 1);
  	  else
  	  	  resize_my_vector(v, v.capacity * 2);
  	  push_back_my_vector_element(v, x);
  }
}

void destroy_my_vector(my_vector &v){
	if(v.capacity > 0){
		delete [] v.store;
        v.store = nullptr;
		v.size = 0;
		v.capacity = 0;
	}
}

bool looks_consistent_my_vector(const my_vector &v){
  //DA MODIFICARE
  return false;
}

void sort_my_vector(my_vector &v){
  //DA MODIFICARE
}
