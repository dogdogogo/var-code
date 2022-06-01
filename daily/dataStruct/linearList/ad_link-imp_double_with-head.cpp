//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *prior, *next;
} Node, *LinkList;

bool initList(LinkList&);
bool nodeNextInsert(Node*, Node*);
bool destoryList(LinkList&);

bool empty(LinkList&);

int main() {
  LinkList l;
  initList(l);

  return 0;
}

bool initList(LinkList& L) {
  L = (Node*)malloc(sizeof(Node));
  if (L == NULL)
    return false;

  L->prior = NULL;
  L->next = NULL;
  printf("** init a double linklist.\n");
  return true;
}

bool nodeNextInsert(Node* p, Node* n) {
  if (p == NULL || n == NULL)
    return false;

  n->next = p->next;
  if (p->next != NULL)
    p->next->prior = n;
  n->prior = p;
  p->next = n;
  printf("++ node -> insert %d after %d.\n", n->data, p->data);
  return true;
}

bool destoryList(LinkList& l) {
  if (l == NULL)
    return true;

  Node* t;
  while (l->next != NULL) {
    t = l;
    l = l->next;
    free(t);
  }
  free(l);

  return true;
}


bool empty(LinkList& L) {
  return (L->next == NULL);
}
