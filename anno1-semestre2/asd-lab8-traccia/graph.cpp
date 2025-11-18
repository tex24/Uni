#include <iostream>

#include "graph.h"

using namespace graph;

struct halfEdgeVertex{
  Label label;
  Weight weight;
  halfEdgeVertex* nextVertex;
};

struct graph::vertexNode {
  bool isVisited;
  Label label;
  halfEdgeVertex* adjList;
  vertexNode* nextVertex;
};

/**********************************************************************/
/*               Funzione da implementare                             */
/**********************************************************************/
// Restituisce il grafo vuoto
Graph graph::createEmptyGraph(){
  return emptyGraph;
}

Graph getVertex(Label l, const Graph& g){
  Graph curr = g;
  while(!isEmpty(curr)){
    if(curr->label == l)
      return curr;
    curr = curr->nextVertex;
  }
  return emptyGraph;
}
// Aggiunge nuovo vertice con etichetta la stringa.
// Se non è gia presente, ritorna true, altrimenti fallisce e ritorna false 
bool graph::addVertex(Label l, Graph& g){
  if(!isEmpty(getVertex(l, g)))
    return false;
  Graph newVertex = new vertexNode;
  newVertex->label = l;
  newVertex->isVisited = false;
  newVertex->adjList = nullptr;
  newVertex->nextVertex = g;
  g = newVertex;
  return true;
}

// Aggiunge nuovo arco tra i due vertici con etichette le due stringe e peso
// l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
// tra i due e' gia' presente. Se fallisce ritorna false,
// altrimenti ritorna true
bool graph::addEdge(Label from, Label to, Weight w, Graph& g){
  //controllo se i vertici esistono
  Graph f = getVertex(from, g);
  Graph t = getVertex(to, g);
  if(isEmpty(f))
    return false;
  if(isEmpty(t))
    return false;
  //controllo se esiste gia il collegamento
  halfEdgeVertex* curr = f->adjList;
  while(curr){
    if(curr->label == t->label)
      return false;
    curr = curr->nextVertex;
  }
  //creo i due collegamenti e li metto in testa ai due vertici
  halfEdgeVertex* new1 = new halfEdgeVertex;
  halfEdgeVertex* new2 = new halfEdgeVertex;
  new1->label = t->label;
  new1->weight = w;
  new1->nextVertex = f->adjList;
  f->adjList = new1;

  new2->label = f->label;
  new2->weight = w;
  new2->nextVertex = t->adjList;
  t->adjList = new2;
  return true;
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g){
  return g == emptyGraph;
}

// Ritorna il numero di vertici del grafo
unsigned int graph::numVertices(const Graph& g){
  unsigned int i = 0;
  Graph curr = g;
  while(!isEmpty(curr)){
    i++;
    curr = curr->nextVertex;
  }
  return i;
}

// Ritorna il numero di archi del grafo
unsigned int graph::numEdges(const Graph& g){
  unsigned int i = 0;
  Graph curr = g;
  while(!isEmpty(curr)){
    halfEdgeVertex* currEdge = curr->adjList;
    while(currEdge){
      i++;
      currEdge = currEdge->nextVertex;
    }
    curr = curr->nextVertex;
  }
  return i/2;
}

// Calcola e ritorna (nel secondo parametro) il grado del vertice.
// Restituisce un valore falso se il vertice non esiste,
// altrimenti ritorna true
bool graph::nodeDegree(Label l, unsigned int& degree, const Graph& g) {
  Graph vertex = getVertex(l, g);
  if(isEmpty(vertex))
    return false;
  degree = 0;
  halfEdgeVertex* curr = vertex->adjList;
  while(curr){
    degree++;
    curr = curr->nextVertex;
  }
  return true;
}

// Verifica se due vertici sono adiacenti (ovvero se esiste un arco)
bool graph::areAdjacent(Label v1, Label v2, const Graph& g) {
  Graph vertex = getVertex(v1, g);
  if(isEmpty(vertex))
    return false;
  halfEdgeVertex* curr = vertex->adjList;
  while(curr){
    if(curr->label == v2)
      return true;
    curr = curr->nextVertex;
  }
  return false;
}

// Ritorna la lista di adiacenza di un vertice
// corrispondente alla lista dei label dei vertici adiacenti
list::List graph::adjacentList(Label v1, const Graph& g) {
  Graph vertex = getVertex(v1, g);
  if(isEmpty(vertex))
    return list::createEmpty();
  list::List l = list::createEmpty();
  halfEdgeVertex* curr = vertex->adjList;
  while(curr){
    list::addFront(curr->label, l);
    curr = curr->nextVertex;
  }
  return l;
}


void setVisitedToZero(const Graph& g){
  Graph curr = g;
  while(!isEmpty(curr)){
    curr->isVisited = false;
    curr = curr->nextVertex;
  }
}

bool findPathAux(Label to, list::List& path, Weight& weight, const Graph &g, const Graph &gr){
  if(isEmpty(g))
    return false;
  g->isVisited = true;
  if(g->label == to){
    return true;
  }
  halfEdgeVertex* curr = g->adjList;
  while(curr){
    Graph graph = getVertex(curr->label, gr);
    if(!graph->isVisited){
      bool ris = findPathAux(to, path, weight, graph, gr);
      if(ris){
        list::addFront(curr->label, path);
        weight += curr->weight;
        return true;
      }
    }

    curr = curr->nextVertex;
  }
  return false;
}

  // Calcola, se esiste, un cammino tra due vertici
  // Il primo argomento e il vertice di partenza
  // Il secondo argomento e il vertice di arrivo
  // Il terzo argomento sara la lista delle etichette degli
  // vertici visitati sul cammino (senza il vertice di partenza,
  // ma con il vertice di arrivo)
  // Si assume che il chiamante fornisca inizialmente una lista vuota.
  // Il quarto argomento e il peso del cammino
  // La funziona ritorna false se non c'e un cammino tra i due vertici
  // Se il vertice di partenza e uguale al vertice di arrivo, la funzione
  // ritorna true, e il peso e 0 e la lista e' vuota
bool graph::findPath(Label v1, Label v2, list::List& path, Weight& weight, const Graph& g) {
  Graph from = getVertex(v1, g);
  Graph to = getVertex(v2, g);
  //se non esiste almeno un vertice
  if(isEmpty(from) || isEmpty(to)){
    weight = 0;
    return false;
  }
  //se i vertici sono uguali
  if(from == to){
    weight = 0;
    return true;
  }
  //setto isVisited di tutti i vertici e il peso iniziale della funzione a zero
  setVisitedToZero(g);
  weight = 0;

  return findPathAux(v2, path, weight, from, g);

}

void clearList(Graph &g){
  halfEdgeVertex* curr = g->adjList;
  while(curr){
    halfEdgeVertex* aux = curr->nextVertex;
    delete curr;
    curr = aux;
  }
  g->adjList = nullptr;
}
// Svuota un grafo
void graph::clear(graph::Graph& g){
  while(g){
    clearList(g);
    Graph aux = g->nextVertex;
    delete g;
    g = aux;
  }
}

// Stampa il grafo
// Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
// poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
// separate da virgole
void graph::printGraph(const graph::Graph& g) {
  if(isEmpty(g))
    return;
  cout << g->label;
  halfEdgeVertex* curr = g->adjList;
  if(curr)
    cout << ": ";
  while(curr){
    cout << curr->label << '(' << curr->weight << ')' << (curr->nextVertex ? ", " : "\n");
    curr = curr->nextVertex;
  }
  printGraph(g->nextVertex);
}
