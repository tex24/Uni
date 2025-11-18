typedef struct _list_node list_node;
typedef struct _node {
  char * name;
  unsigned nb_children;
  list_node * children;
} node;
struct _list_node {
  node n;
  struct _list_node * next;
};
// Questa funzione crea un nuovo nodo con nome name
// con 0 figli
node * new_node(const char * name);

// Questa funzione aggiunge un figlio al nodo current
// Il nodo aggiunto non avvr 'a figli
// Questa funzione ritorna 0 se tutto va bene e -1 altrimenti
int new_child(node * current, const char * name);

// Questa funzione stampa il contenuto dell 'albero con radice il
// node current
void print_tree(node * current);

// Questa funzione cancella l'albero con radice current
// liberando la memoria allocata
void delete_tree(node * current);

// Questa funzione crea l'albero corrispondente alla cartella di lavoro
node * build_from_current_file();