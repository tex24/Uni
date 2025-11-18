#include "dictionary.h"

using namespace dict;

//STRUCT TO BE COMPLETED
// *** NON AGGIUNGETE IL PUNTATORE AL PADRE ALLA STRUCT!!!! *** 
struct dict::bstNode {
  bstNode* right;
  bstNode* left;
  Elem elem;
};

//Funzione da implementare
bool dict::isEmpty(const Dictionary& d){
  return (d == emptyDictionary);
}
   
//Funzione da implementare
Dictionary dict::createEmptyDict(){
  Dictionary d = emptyDictionary;
  return d;
}

//Funzione da implementare
Error dict::insertElem(const Key k, const Value v, Dictionary& d){
  if(d == emptyDictionary){
    d = new bstNode;
    d->elem.key = k;
    d->elem.value = v;
    d->left = emptyNode;
    d->right = emptyNode;
    return OK;
  }
  if(k < d->elem.key)
    return insertElem(k, v, d->left);
  else if (k > d->elem.key)
    return insertElem(k, v, d->right);
  return FAIL;
}

//Funzione da implementare
Value dict::search(const Key k, const Dictionary& d){
  if(d == emptyDictionary)
    return emptyValue;

  if(k < d->elem.key)
    return search(k, d->left);
  else if (k > d->elem.key)
    return search(k, d->right);
  else
    return d->elem.value;
}

Elem deleteMin(Dictionary& d) {
  if (d->left == emptyNode) {
    Elem minELem = d->elem;
    Dictionary toDelete = d;
    d = d->right;
    delete toDelete;
    return minELem;
  } else {
    return deleteMin(d->left);
  }
}

//Funzione da implementare
Error dict::deleteElem(const Key k, Dictionary& d) {
  if (d == emptyDictionary)
    return FAIL;
  if (k < d->elem.key)
    return deleteElem(k, d->left);
  else if (k > d->elem.key)
    return deleteElem(k, d->right);
  else {
    // Caso con due figli
    if (d->left != emptyNode && d->right != emptyNode) {
      d->elem = deleteMin(d->right);
      return OK;
    }
    // Caso con solo figlio sinistro
    else if (d->left != emptyNode) {
      Dictionary toDelete = d;
      d = d->left;
      delete toDelete;
      return OK;
    }
    // Caso con solo figlio destro
    else if (d->right != emptyNode) {
      Dictionary toDelete = d;
      d = d->right;
      delete toDelete;
      return OK;
    }
    // Caso foglia
    else {
      delete d;
      d = emptyNode;
      return OK;
    }
  }
}


//Funzione da implementare
void print(const Dictionary& d) {
  if(d == emptyDictionary)
    return;
  print(d->left);
  cout << d->elem.key << ": " << d->elem.value << endl;
  print(d->right);
}

/****************************************************************/
/*              FUNZIONE IMPLEMENTATE                           */
/****************************************************************/
Dictionary readFromFile(string nome_file){
  ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
  if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return emptyDictionary;}  
  return readFromStream(ifs);
}

Dictionary readFromStdin(){
  cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
  Dictionary d = readFromStream((std::cin));
  // Questa serve per aggirare un bug di alcune versioni attuali di glibc.
  clearerr(stdin);
  return d;
}

Dictionary readFromStream(istream& str){
  Dictionary d = emptyDictionary; 
  string key, kcopy;
  string value;
  getline (str, key, ':'); 
  getline (str, value); 
  while (!str.eof())  
    {        
      kcopy = key;
      removeBlanksAndLower(kcopy); 
      insertElem(kcopy, value, d);
      getline (str, key, ':'); 
      getline (str, value); 
    }
  str.clear();
  return d;
}
