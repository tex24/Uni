#include "mytree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node *new_node(const char *name) {
  node *cur = malloc(sizeof(node));
  if (!cur)
    return NULL;
  cur->name = malloc(sizeof(char) * (strlen(name) + 1));
  if (!cur->name)
    return NULL;
  strcpy(cur->name, name);
  cur->nb_children = 0;
  cur->children = NULL;
  return cur;
}

int new_child(node *current, const char *name) {
  list_node *ins = malloc(sizeof(list_node));
  if (!ins)
    return -1;
  ins->n = *new_node(name);
  ins->next = current->children;
  current->children = ins;
  return 0;
}

void auxPrint_tree(node *current, int n) {
  if (!current)
    return;
  for (int i = 0; i < n; i++)
    printf("--");
  puts(current->name);
  list_node *children = current->children;
  while (children) {
    auxPrint_tree(&children->n, n + 1);
    children = children->next;
  }
}

void print_tree(node *current) { auxPrint_tree(current, 0); }

void auxDelete_tree(list_node *n){
  if(!n)
    return;
  list_node *curr = n;
  while(curr){
    auxDelete_tree(curr->n.children);
    list_node *aux = curr;
    curr = curr->next;
    printf("libero %s\n", aux->n.name);
    free(aux->n.name);
    free(aux);
  }
}

void delete_tree(node *current) {
  if (!current)
    return;
  auxDelete_tree(current->children);
  printf("libero il padre %s\n", current->name);
  free(current->name);
  free(current);
}

int main() {
  node *padre = new_node("padre di tutti");
  new_child(padre, "figlio");
  new_child(padre, "ciao");
  new_child(&padre->children->n, "figlissimo");
  print_tree(padre);
  delete_tree(padre);
  padre = NULL;
}