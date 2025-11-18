// TO DO, vedi indicazioni in industry.h
#include "industry.h"
#include <vcruntime.h>
using namespace industry;

Industry industry::createEmptyIndustry() { return emptyIndustry; }

bool isPresentInStringArray(const std::string &name, std::string *stringArray,
                            size_t size) {
  for (size_t i = 0; i < size; i++) {
    if (stringArray[i] == name) {
      return true;
    }
  }
  return false;
}

ElemList getItem(string name, const Industry &indus) {
  if (!indus)
    return emptyElemList;
  if (indus->elem->name < name)
    return getItem(name, indus->right);
  if (indus->elem->name > name)
    return getItem(name, indus->left);
  return indus->elem;
}

void getListOfDependence(List &ris, string *stringArray, size_t size,
                         Industry &indus) {
  if (!indus)
    return;
  if (isPresentInStringArray(indus->elem->name, stringArray, size)) {
    insertFront(ris, indus);
  }
  getListOfDependence(ris, stringArray, size, indus->left);
  getListOfDependence(ris, stringArray, size, indus->right);
}

ElemList createBasicItem(string name) {
  ElemList node = new Elem;
  node->createItems = createEmptyList();
  node->needItems = createEmptyList();
  node->name = name;
  node->val = 0;
  return node;
}

ElemList createItem(string name, List dependence) {
  ElemList node = new Elem;
  node->createItems = createEmptyList();
  node->needItems = dependence;
  node->name = name;
  node->val = -1;
  return node;
}

bool insert(Industry &indus, Industry &item) {
  if (indus == emptyIndustry) {
    indus = item;
    return true;
  }
  if (indus->elem->name < item->elem->name)
    return insert(indus->right, item);
  if (indus->elem->name > item->elem->name)
    return insert(indus->left, item);
  return false;
}
// Inserisce un nuovo basic item di nome 'name' nell'industria.
// Se esiste gia' un item con quel nome, la funzione restituisce false e non fa
// nulla. Altrimenti inserisce l'item e restituisce true. Si assume che, quando
// viene inserito un basic item, la quantita iniziale sia 0.
bool industry::insertBasicItem(Industry &indus, std::string name) {
  if (indus == emptyIndustry) {
    indus = new st_Industry;
    indus->elem = createBasicItem(name);
    indus->left = emptyIndustry;
    indus->right = emptyIndustry;
    return true;
  }
  if (name < indus->elem->name)
    return insertBasicItem(indus->left, name);
  else if (name > indus->elem->name)
    return insertBasicItem(indus->right, name);
  return false;
}

// Inserisce un nuovo item di nome 'name' nell'industria.
// 'components' e' un array NON VUOTO di lunghezza 's' che contiene i nomi degli
// item da cui dipende il nuovo item. Se esiste gia' un item con quel nome, la
// funzione restituisce false e non fa nulla. Se uno qualsiasi degli item
// indicati in 'components' non esiste nell'industria, la funzione restituisce
// false e non fa nulla. Altrimenti inserisce l'item e restituisce true.
bool insertItem(Industry &indus, std::string name, std::string *components,
                size_t s) {
  if (getItem(name, indus))
    return false;
  List list = createEmptyList();
  getListOfDependence(list, components, s, indus);
  if (length(list) < s) {
    freeList(list);
    return false;
  }

  Industry node = new st_Industry;
  node->elem = createItem(name, list);
  insert(indus, node);

  while (list) {
    insertFront(list->nodePtr->elem->createItems, node);
  }
}

bool st_Industry::isPresentItem(const Industry &indus, std::string name) {
  if(!indus)
    return false;
  if(indus->elem->name == name)
    return true;
  if(indus->elem->name > name)
    return st_Industry::isPresentItem(indus->left, name);
  return st_Industry::isPresentItem(indus->right, name);

}