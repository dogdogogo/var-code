//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <malloc/_malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node, *LinkList;

bool initList(LinkList&);
bool headInsert(LinkList&, int);
bool tailInsert(LinkList&, int);
bool indexInsert(LinkList&, int, int);
bool nodeNextInsert(Node*, int);
bool nodePriorInsert(Node*, int);
bool indexDelete(LinkList&, int, int&);
Node* get(LinkList&, int);
Node* locate(LinkList&, int);

void prtList(LinkList);

int main() {
  LinkList l;
  initList(l);
  prtList(l);

  headInsert(l, 101);
  headInsert(l, 102);
  headInsert(l, 103);
  headInsert(l, 104);
  prtList(l);

  tailInsert(l, 105);
  tailInsert(l, 106);
  tailInsert(l, 107);
  prtList(l);

  indexInsert(l, 2, 1002);
  indexInsert(l, 4, 1004);
  indexInsert(l, 6, 1006);
  prtList(l);

  int getRet;
  indexDelete(l, 1, getRet);
  indexDelete(l, 2, getRet);
  indexDelete(l, 8, getRet);
  printf("-- %d\n", indexDelete(l, 8, getRet));
  prtList(l);

  get(l, 2);
  get(l, 10);
  Node* g = get(l, 7);
  printf("<< %d\n", g->data);

  Node* aa= locate(l, 102);
  printf("==> locate %d.\n", aa->data);

  return 0;
}

bool initList(LinkList& L) {
  L = (Node*)malloc(sizeof(Node));
  if (L == NULL)
    return false;

  L->next = NULL;
  printf("** init a linklist.\n");
  return true;
}

bool headInsert(LinkList& L, int ins) {
  Node* a = (Node*)malloc(sizeof(Node));
  if (a == NULL)
    return false;

  a->data = ins;
  a->next = L->next;
  L->next = a;
  printf("++ head insert %d.\n", ins);
  return true;
}

bool tailInsert(LinkList& L, int ins) {
  Node* a = (Node*)malloc(sizeof(Node));
  if (a == NULL)
    return false;

  LinkList p = L;
  while (p->next != NULL)
    p = p->next;
  a->data = ins;
  a->next = NULL;
  p->next = a;
  printf("++ tail insert %d.\n", ins);
  return true;
}

bool indexInsert(LinkList& L, int l, int i) {
  if (l < 1)
    return false;

  Node* a = (Node*)malloc(sizeof(Node));
  if (a == NULL)
    return false;

  int c = 0;
  Node* p = L;
  while (c < l - 1) {
    if (p->next == NULL)
      break;
    p = p->next;
    c ++;
  }

  if (c != l - 1)
    return false;

  a->data = i;
  a->next = p->next;
  p->next = a;
  printf("++ index insert %d at index %d.\n", i, l);
  return true;
}

bool nodeNextInsert(Node* n, int i) {
  if (n == NULL)
    return false;

  Node* t = (Node*)malloc(sizeof(Node));
  if (t == NULL)
    return false;

  t->data = i;
  t->next = n->next;
  n->next = t;
  printf("++ node next insert %d\n", i);
  return true;
}

bool nodePriorInsert(Node* n, int i) {
  if (n == NULL)
    return false;

  Node* t = (Node*)malloc(sizeof(Node));
  if (t == NULL)
    return false;

  t->next = n->next;
  n->next = t;
  t->data = n->data;
  n->data = i;
  return true;
}

bool indexDelete(LinkList& L, int i, int& r) {
  if (i < 1)
    return false;

  Node* t = L;
  int c = 0;
  while (c < i - 1) {
    if (t->next == NULL)
      break;
    t = t->next;
    c ++;
  }
  if (c != i - 1)
    return false;

  if (t->next == NULL)
    return false;

  Node* nn = t->next;
  r = nn->data;
  t->next = nn->next;
  free(nn);
  printf("-- del %d at index %d.\n", r, i);
  return true;
}

Node* get(LinkList& L, int i) {
  if (i < 1)
    return NULL;

  Node* n = L;
  int c = 0;

  while (n != NULL && c < i) {
    n = n->next;
    c ++;
  }

  if (n != NULL)
    printf(">> %d at index %d.\n", n->data, i);
  else
    printf(">> not get.\n");
  return n;
}

Node* locate(LinkList& L, int n) {
  if (L == NULL)
    return NULL;

  Node* p = L->next;
  while (p != NULL && p->data != n)
    p = p->next;
  return p;
}


void prtList(LinkList L) {
  printf("$$ print list.\n");
  while (L->next != NULL) {
    L = L->next;
    printf("%d ", L->data);
  }
  printf("\n");
}
