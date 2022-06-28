//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack
#define MaxSize 101
typedef struct {
  char data[MaxSize];
  int top;
} Stack;
void initStack(Stack&);
bool push(Stack&, char);
bool pop(Stack&, char&);
bool empty(Stack&);
bool full(Stack&);

bool bracketMatching(char[]);

int main() {
  char a[] = "a + {b + c -[1 + (c + d) + (b - c)]}";
  printf("%d\n", bracketMatching(a));

  return 0;
}

void initStack(Stack& s) {
  s.top = -1;
  s.data[MaxSize - 1] = '\0';
}

bool push(Stack& s, char ins) {
  if (full(s))
    return false;

  s.top ++;
  s.data[s.top] = ins;
  return true;
}

bool pop(Stack& s, char& ret) {
  if (empty(s))
    return false;

  ret = s.data[s.top];
  s.top --;
  return true;
}


bool empty(Stack& s) {
  return s.top == -1;
}

bool full(Stack& s) {
  return s.top == MaxSize - 2;
}


bool bracketMatching(char str[]) {
  int len = strlen(str);
  Stack S;
  initStack(S);

  char pop_char;
  for (int i = 0; i < len; i ++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      push(S, str[i]);
    } else {
      if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
        if (empty(S))
          return false;

        pop(S, pop_char);
        if (str[i] == ')' && pop_char != '(')
          return false;
        if (str[i] == ']' && pop_char != '[')
          return false;
        if (str[i] == '}' && pop_char != '{')
          return false;
     }
    }
  }

  return empty(S);
}
