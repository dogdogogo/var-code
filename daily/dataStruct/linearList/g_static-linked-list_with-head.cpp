//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 11

typedef struct {
  int data;
  int next;
} Node, *LinkList;

void initList(LinkList);

void prtInit(LinkList);

int main() {
  Node L[MaxSize];
  printf("size = %ld\n", sizeof(L));

  initList(L);
  prtInit(L);

  return 0;
}

void initList(LinkList l) {
  l->next = -1;

  for (int i = 1; i < MaxSize; i++)
    l[i].next = -2;
}


void prtInit(LinkList l) {
  for (int i = 0; i < MaxSize; i ++)
    printf("l[%d] = %d\n", i, l[i].next);
}
