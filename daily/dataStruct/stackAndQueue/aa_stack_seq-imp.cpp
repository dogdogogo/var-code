//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct {
  int data[MaxSize];
  int top;
} Stack;

void initStack(Stack&);
bool push(Stack&, int);
bool pop(Stack&, int&);
bool top(Stack&, int&);

void prtStack(Stack&);

int main() {
  Stack S;
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

  top(S, ret);
  printf("ret = %d\n", ret);

  return 0;
}

void initStack(Stack& s) {
  s.top = -1;
}

bool push(Stack& s, int ins) {
  if (s.top == MaxSize - 1)
    return false;

  s.top += 1;
  s.data[s.top] = ins;
  return true;
}

bool pop(Stack& s, int& ret) {
  if (s.top == -1)
    return false;

  ret = s.data[s.top];
  s.top -= 1;
  return true;
}

bool top(Stack& s, int& ret) {
  if (s.top == -1)
    return false;

  ret = s.data[s.top];
  return true;
}


void prtStack(Stack& s) {
  printf("$$ print Stack\n");
  for (int i = s.top; i >= 0; i --) {
    printf("| %5d |\n", s.data[i]);
    printf(" ------- \n");
  }
}
