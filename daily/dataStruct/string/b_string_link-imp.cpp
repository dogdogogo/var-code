//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>

typedef struct StringNode {
  char str[4];
  struct StringNode *next;
} StringNode, *String;

int main() {

  return 0;
}
