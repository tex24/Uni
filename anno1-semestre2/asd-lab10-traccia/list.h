#ifndef NODE_LIST_H
#define NODE_LIST_H

#include <string>
#include "industry.h"

// Definizione della struttura del nodo della lista
typedef struct ListNode {
    industry::Industry nodePtr;            // Puntatore al nodo Industry
    struct ListNode* next;       // Puntatore al nodo successivo
    struct ListNode* prev;       // Puntatore al nodo precedente
} ListNode;

// Definizione del tipo List
typedef ListNode* List;

// Costante per lista vuota
const List emptyList = nullptr;

// Funzioni per la gestione della lista
List createEmptyList();                     // Crea una lista vuota
bool isEmpty(List list);                    // Verifica se la lista è vuota
List insertFront(List& list, industry::Industry& node); // Inserisce in testa alla lista
List insertBack(List& list, industry::Industry& node);  // Inserisce in coda alla lista

// Funzioni di ricerca e accesso
ListNode* search(List list, industry::Industry node); // Cerca un nodo nella lista
ListNode* searchByName(List list, const std::string& name); // Cerca per nome

// Funzioni di rimozione
List remove(List list, industry::Industry node);      // Rimuove un elemento specifico
List removeByName(List list, const std::string& name); // Rimuove per nome
void freeList(List& list);

// Funzioni di utilità
int length(List list);                      // Calcola la lunghezza della lista

#endif // NODE_LIST_H