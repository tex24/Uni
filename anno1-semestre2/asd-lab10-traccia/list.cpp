#include "list.h"
#include <iostream>

List createEmptyList() {
    return emptyList;
}

bool isEmpty(List list) {
    return list == emptyList;
}

List insertFront(List& list, industry::Industry& node) {
    ListNode* newNode = new ListNode;
    newNode->nodePtr = node;
    newNode->prev = emptyList;
    
    if (isEmpty(list)) {
        newNode->next = emptyList;
        return newNode;
    }
    
    newNode->next = list;
    list->prev = newNode;
    return newNode;
}

List insertBack(List list, industry::Industry node) {
    if (isEmpty(list)) {
        return insertFront(list, node);
    }
    
    ListNode* current = list;
    while (current->next != emptyList) {
        current = current->next;
    }
    
    ListNode* newNode = new ListNode;
    newNode->nodePtr = node;
    newNode->next = emptyList;
    newNode->prev = current;
    current->next = newNode;
    
    return list;
}

ListNode* search(List list, industry::Industry node) {
    ListNode* current = list;
    while (current != emptyList) {
        if (current->nodePtr == node) {
            return current;
        }
        current = current->next;
    }
    return emptyList;
}

ListNode* searchByName(List list, const std::string& name) {
    ListNode* current = list;
    while (current != emptyList) {
        if (current->nodePtr != emptyList && current->nodePtr->elem.name == name) {
            return current;
        }
        current = current->next;
    }
    return emptyList;
}

List remove(List list, industry::Industry node) {
    if (isEmpty(list)) {
        return list;
    }
    
    // Caso in cui il nodo da rimuovere è il primo
    if (list->nodePtr == node) {
        ListNode* toDelete = list;
        List newHead = list->next;
        
        if (newHead != emptyList) {
            newHead->prev = emptyList;
        }
        
        delete toDelete;
        return newHead;
    }
    
    // Cerchiamo il nodo da rimuovere
    ListNode* current = list;
    while (current->next != emptyList && current->next->nodePtr != node) {
        current = current->next;
    }
    
    // Se lo abbiamo trovato
    if (current->next != emptyList) {
        ListNode* toDelete = current->next;
        current->next = toDelete->next;
        
        if (toDelete->next != emptyList) {
            toDelete->next->prev = current;
        }
        
        delete toDelete;
    }
    
    return list;
}

List removeByName(List list, const std::string& name) {
    if (isEmpty(list)) {
        return list;
    }
    
    // Caso in cui il nodo da rimuovere è il primo
    if (list->nodePtr != emptyList && list->nodePtr->elem.name == name) {
        ListNode* toDelete = list;
        List newHead = list->next;
        
        if (newHead != emptyList) {
            newHead->prev = emptyList;
        }
        
        delete toDelete;
        return newHead;
    }
    
    // Cerchiamo il nodo da rimuovere
    ListNode* current = list;
    while (current->next != emptyList && 
           (current->next->nodePtr == emptyList || current->next->nodePtr->elem.name != name)) {
        current = current->next;
    }
    
    // Se lo abbiamo trovato
    if (current->next != emptyList) {
        ListNode* toDelete = current->next;
        current->next = toDelete->next;
        
        if (toDelete->next != emptyList) {
            toDelete->next->prev = current;
        }
        
        delete toDelete;
    }
    
    return list;
}

int length(List list) {
    int count = 0;
    ListNode* current = list;
    
    while (current != emptyList) {
        count++;
        current = current->next;
    }
    
    return count;
}

void freeList(List& list) {
    // Finché la lista non è vuota
    while (!isEmpty(list)) {
        // Salva un puntatore al nodo corrente
        ListNode* toDelete = list;
        
        // Aggiorna la testa della lista al nodo successivo
        list = list->next;
        
        // Libera la memoria del nodo corrente
        delete toDelete;
    }
    
    // Assicura che la lista sia impostata come vuota
    list = emptyList;
}