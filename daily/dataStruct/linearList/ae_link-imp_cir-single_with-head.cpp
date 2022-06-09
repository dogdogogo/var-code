//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <malloc/_malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node, *LinkList;

bool initList(LinkList&);

int main() {

  return 0;
}

bool initList(LinkList& L) {
  L = (Node*)malloc(sizeof(Node));
  if (L == NULL)
    return false;

  L->next = L;
  return true;
}
