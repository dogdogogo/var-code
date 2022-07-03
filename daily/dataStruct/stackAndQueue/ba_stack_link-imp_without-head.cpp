//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int data;
  struct Stack *next;
} Stack, *LinkStack;

void initStack(LinkStack&);
bool push(LinkStack&, int);
bool pop(LinkStack&, int&);
bool top(LinkStack&, int&);

void prtStack(LinkStack&);

int main() {
  LinkStack S;
  initStack(S);

  push(S, 100);
  push(S, 101);
  push(S, 102);
  push(S, 103);
  push(S, 104);
  push(S, 105);
  prtStack(S);

  int ret;
  pop(S, ret);
  printf("ret = %d\n", ret);
  prtStack(S);
  pop(S, ret);
  printf("ret = %d\n", ret);
  prtStack(S);

  top(S, ret);
  printf("ret = %d\n", ret);

  return 0;
}

void initStack(LinkStack& s) {
  s = NULL;
}

bool push(LinkStack& s, int ins) {
  Stack* a = (Stack*)malloc(sizeof(Stack));
  if (a == NULL)
    return false;

  a->data = ins;
  a->next = s;
  s = a;
  return true;
}

bool pop(LinkStack& s, int& ret) {
  if (s == NULL)
    return false;

  ret = s->data;
  Stack* t = s;
  s = s->next;
  free(t);
  return true;
}

bool top(LinkStack& s, int& ret) {
  if (s == NULL)
    return false;

  ret = s->data;
  return true;
}


void prtStack(LinkStack& s) {
  LinkStack t = s;

  printf("$$ print Stack\n");
  while (t != NULL) {
    printf("| %5d |\n", t->data);
    printf(" ------ \n");
    t = t->next;
  }
}
