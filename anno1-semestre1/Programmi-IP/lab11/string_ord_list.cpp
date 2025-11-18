#include "string_ord_list.h"
#include <iostream>

using namespace std;

// inserisce un elemento contenente s nella lista ordinata l mantenendo la lista ordinata
void insertElement(ordList &l,string s){
	if(!l){
		ordList c = new cell;
		c->data = s;
		l = c;
        l->next = nullptr;
		return;
	}
	ordList curr = l;
	ordList aux = l;
	while(curr){
		if(curr->data >= s){
				if(curr == l){
					ordList c = new cell;
					c->data = s;
					l = c;
					c->next = curr;
					return;
				}
				ordList c = new cell;
				c->data = s;
				aux->next = c;
				c->next = curr;
				return;
		}
		aux = curr;
		curr = curr->next;
	}
    ordList c = new cell;
	c->data = s;
    c->next = nullptr;
	aux->next = c;
}                                                            

// legge valori da input e li memorizza (aggiunge) nella lista ordinata l
// al termine dell'esecuzione di readList la lista l deve essere una lista ordinata.
// l'inserimento termina se l'utente inserisce "STOP!"
void readList(ordList &l){
	string str;
	cout << "scrivi una stringa da inserire nella lista, fermati digitando STOP!" << endl;
	while(true){
		cout << "inserisci stringa (termina la stringa con invio): ";
		getline(cin, str);
		if(str == "STOP!")
			break;
        insertElement(l, str);
	}
}

// stampa tutti i valori (data) degli elementi della lista ordinata l in linea separati da "->"
void printList(const ordList &l){
	if(l and listSize(l) != 0){
		cout << l->data;
        if(l->next)
            cout << "->";
		printList(l->next);
	}
	else
		cout << endl;
}

// ritorna il numero di elementi della lista ordinata l
// NB: nessuna variazione rispetto alla versione per liste non ordinate
unsigned int listSize(const ordList &l){
	if(l)
		return 1 + listSize(l->next);
	else
		return 0;
}

// ritorna true se la lista ordinata l e vuota, false altrimenti
bool isEmptyList(const ordList &l){
	if(l)
		return false;
	else
		return true;
}

// ritorna il contenuto dell'i-esimo elemento della lista ordinata l
// - se la lista ordinata l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
string getElement(const ordList &l, unsigned int i){
    if(!l)
  	    throw string("Impossibile trovare un elemento nella lista vuota");
    ordList curr = l;
    unsigned int j=0;
    while(curr){
        if(i == j)
            return curr->data;
        curr = curr->next;
        j++;
    }
    throw string("indice non valido: " + to_string(i));
}

// cancella l'elemento in posizione i dalla lista ordinata l
// - se la lista ordinata l è vuota solleva un'eccezione con messaggio di tipo string
// - se l'indice i è invalido solleva un'eccezione con messaggio di tipo string
void deleteElementAt(ordList &l, unsigned int i){
    if(!l)
        throw string("Impossibile trovare un elemento nella lista vuota");
    if(i == 0){
        ordList aux = l;
        l = l->next;
        delete aux;
        return;
    }
    ordList curr = l;
    ordList aux = l;
    unsigned int j=0;
    while(curr){
        if(i == j){
            aux->next = curr->next;
            delete curr;
            return;
        }
        aux = curr;
        curr = curr->next;
        j++;
    }
    throw string("indice non valido");
}

// cancella dalla lista ordinata l il primo elemento contenente s
void deleteElementOnce(ordList &l, std::string s){
    ordList curr = l;
    if(l->data == s){
        ordList aux = l;
        l = l->next;
        delete aux;
        return;
    }
    while(curr->next){
        if(curr->next->data == s){
            ordList aux = curr->next;
            curr->next = curr->next->next;
            delete aux;
            return;
        }
        curr = curr->next;
    }
}

// cancella dalla lista ordinata l tutti gli elementi contenenti s
void deleteAllElements(ordList &l, std::string s){
    bool entrato = false;
    while(l and l->data == s){
        if(l->data != s)
            break;
        ordList aux = l;
        l = l->next;
        delete aux;
        entrato = true;
    }
    if(entrato)
        return;
    ordList curr = l->next;
    ordList aux = l;
    while(curr){
        if(curr->data == s){
            aux->next = curr->next;
            delete curr;
            curr = aux->next;
        }else{
            aux = curr;
            curr = curr->next;
        }

    }
}

// restituisce true se le due liste contengono le stesse stringhe (con la stessa molteplicità)
// false altrimenti
bool listAreEqual(const ordList &l1, const ordList &l2){
    if(listSize(l1) != listSize(l2))
        return false;
    ordList curr1 = l1;
    ordList curr2 = l2;
    while(curr1 and curr2){
        if(curr1->data != curr2->data)
            return false;
        curr2 = curr2->next;
        curr1 = curr1->next;
    }
    return true;
}

// restituisce una nuova lista ordinata contenente gli elementi delle 2 liste ordinate l1 e l2
// Il numero di occorrenze di un elemento nel risultato 
// è la somma del numero delle sue occorrenze nelle due liste l1 e l2
// NB: ogni elemento della nuova lista deve essere un duplicato di quelli //     in questo modo sia l1 che l2 non subiscono alcuna modifica
ordList concatLists(const ordList &l1, const ordList &l2) {
    ordList ris = nullptr;
    ordList curr = l1;
    while(curr){
        insertElement(ris, curr->data);
        curr = curr->next;
    }
    curr = l2;
    while(curr){
        insertElement(ris, curr->data);
        curr = curr->next;
    }
    return ris;
}


// restituisce una nuova lista ordinata senza ripetizioni contenente
// gli elementi presenti in almeno una delle due liste l1 e l2
// NB1: ogni elemento della nuova lista deve essere un duplicato di quelli contenuti in l1 e l2
//      in questo modo sia l1 che l2 non subiscono alcuna modifica
// NB2: opzionalmente cercate di implementare la funzione in modo da sfruttare il fatto che
//      le due liste sono ordinate per minimizzare il numero di operazioni necessarie
ordList unionLists(const ordList &l1, const ordList &l2){
    ordList ris = nullptr;
    bool trovato = false;
    string str;
    try{
        for(unsigned int i=0; i< listSize(l1); i++){
            str = getElement(l1, i);
            trovato = false;
            for(unsigned int j=0; j< listSize(ris); j++){
                if(getElement(ris, j) == str){
                    trovato = true;
                    break;
                }
            }
            if(!trovato)
                insertElement(ris, str);
        }
        for(unsigned int i=0; i< listSize(l2); i++){
            str = getElement(l2, i);
            trovato = false;

            for(unsigned int j=0; j< listSize(ris); j++){
                if(getElement(ris, j) == str){
                    trovato = true;
                    break;
                }
            }
            if(!trovato)
                insertElement(ris, str);
        }
    }catch(string s){
        cout << "eccezione: " << s;
    }

  return ris;
}

// restituisce una nuova lista ordinata senza ripetizioni contenente
// gli elementi presenti in entrambe le liste l1 e l2
// NB1: ogni elemento della nuova lista deve essere un duplicato di quelli contenuti in l1 e l2
//      in questo modo sia l1 che l2 non subiscono alcuna modifica
// NB2: opzionalmente cercate di implementare la funzione in modo da sfruttare il fatto che
//      le due liste sono ordinate per minimizzare il numero di operazioni necessarie
//funzione ausiliaria
bool isIn(ordList l1, string str){
    for(unsigned int i=0; i< listSize(l1); i++){
        string s = getElement(l1, i);
        if(s == str)
            return true;
        if(s > str)
            return false;
    }
    return false;
}

ordList intersectLists(const ordList &l1, const ordList &l2){
    ordList ris = nullptr;
    for(unsigned int i=0; i< listSize(l1); i++){
        if(isIn(l2, getElement(l1, i)) and !isIn(ris, getElement(l1, i))){
            insertElement(ris, getElement(l1, i));
        }
    }
    return ris;
}

