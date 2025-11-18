#include "string_ord_list.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    ordList list1 = nullptr;

    // Test isEmptyList
    cout << "La lista inizialmente è vuota? " << (isEmptyList(list1) ? "Sì" : "No") << endl;

    // Test insertElement
    cout << "\nInserimento di elementi nella lista..." << endl;
    cout << "Situazione iniziale: ";
    printList(list1);

    insertElement(list1, "beta");
    insertElement(list1, "alpha");
    insertElement(list1, "gamma");
    insertElement(list1, "delta");

    cout << "Situazione dopo inserimenti: ";
    printList(list1);

    // Test listSize
    cout << "\nDimensione della lista: " << listSize(list1) << endl;

    // Test getElement
    try {
        cout << "\nElemento in posizione 2: " << getElement(list1, 2) << endl;
        cout << "\nElemento in posizione 0: " << getElement(list1, 0) << endl;
        cout << "\nElemento in posizione 3: " << getElement(list1, 3) << endl;
        cout << "\nElemento in posizione 4: " << getElement(list1, 4) << endl;
    } catch (string &e) {
        cout << "Errore: " << e << endl;
    }

    // Test deleteElementAt
    try {
        cout << "\nCancellazione dell'elemento in posizione 1..." << endl;
        cout << "Situazione iniziale: ";
        printList(list1);
        deleteElementAt(list1, 1);
        cout << "Situazione dopo cancellazione: ";
        printList(list1);
        cout << "\nCancellazione dell'elemento in posizione 0..." << endl;
        cout << "Situazione iniziale: ";
        printList(list1);
        deleteElementAt(list1, 0);
        cout << "Situazione dopo cancellazione: ";
        printList(list1);
        cout << "\nCancellazione dell'elemento in posizione 1..." << endl;
        cout << "Situazione iniziale: ";
        printList(list1);
        deleteElementAt(list1, 1);
        cout << "Situazione dopo cancellazione: ";
        printList(list1);
    } catch (string &e) {
        cout << "Errore: " << e << endl;
    }
/*    insertElement(list1, "alfa");
    insertElement(list1, "beta");
    // Test deleteElementOnce
    cout << "\nCancellazione del primo elemento contenente 'delta'..." << endl;
    cout << "Situazione iniziale: ";
    printList(list1);
    deleteElementOnce(list1, "delta");
    cout << "Situazione dopo cancellazione: ";
    printList(list1);
    cout << "\nCancellazione del primo elemento contenente 'gamma'..." << endl;
    cout << "Situazione iniziale: ";
    printList(list1);
    deleteElementOnce(list1, "gamma");
    cout << "Situazione dopo cancellazione: ";
    printList(list1);


    // Test deleteAllElements
    cout << "\nInserimento di duplicati..." << endl;
    cout << "Situazione iniziale: ";
    printList(list1);

    insertElement(list1, "beta");
    insertElement(list1, "beta");
    insertElement(list1, "alfa");
    insertElement(list1, "alfa");
    insertElement(list1, "alfa");

    cout << "Situazione dopo inserimento duplicati: ";
    printList(list1);

    cout << "\nCancellazione di tutti gli elementi contenenti 'beta'..." << endl;
    deleteAllElements(list1, "beta");
    cout << "Situazione dopo cancellazione: ";
    printList(list1);
    cout << "\nCancellazione di tutti gli elementi contenenti 'alfa'..." << endl;
    deleteAllElements(list1, "alfa");
    cout << "Situazione dopo cancellazione: ";
    printList(list1);

    //test listAreEqual
    ordList a = nullptr;
    ordList b = nullptr;
    insertElement(a, "ciao");
    insertElement(a, "ciao");
    insertElement(a, "banane");
    insertElement(b, "banane");
    insertElement(b, "banane");
    insertElement(b, "ciao");
    cout << endl << "test se le liste sono uguali:" << endl;
    cout << "a" << ": ";
    printList(a);
    cout << "b" << ": ";
    printList(b);
    cout << "le liste sono uguali? " << listAreEqual(a, b);
    deleteElementOnce(a, "ciao");
    deleteElementOnce(b, "banane");
    cout << endl << "test se le liste sono uguali:" << endl;
    cout << "a" << ": ";
    printList(a);
    cout << "b" << ": ";
    printList(b);
    cout << "le liste sono uguali: " << listAreEqual(a, b) << endl;


    // Test concatLists
    ordList list2 = nullptr;
    insertElement(list1, "zanzara");
    insertElement(list1, "figo");
    insertElement(list2, "epsilon");
    insertElement(list2, "zeta");
    cout << "\nSituazione iniziale list1: ";
    printList(list1);
    cout << "\nSituazione iniziale list2: ";
    printList(list2);

    ordList concatenated = concatLists(list1, list2);
    cout << "Situazione dopo concatenazione di list1 e list2: ";
    printList(concatenated);

    // Test unionLists
    insertElement(list1, "figo");
    insertElement(list2, "figo");
    cout << "\nlist1 = ";
    printList(list1);
    cout << "list2 = ";
    printList(list2);
    ordList unionList = unionLists(list1, list2);

    cout << "\nUnione di list1 e list2: ";
    printList(unionList);

    // Test intersectLists
    ordList intersection = intersectLists(list1, list2);
    cout << "\nIntersezione di list1 e list2: ";
    printList(intersection);

    ordList nuova = nullptr;
    readList(nuova);
    printList(nuova);*/
    return 0;
}
