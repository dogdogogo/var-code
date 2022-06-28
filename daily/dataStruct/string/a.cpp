//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // ASCII
  // Unicode
  // utf-8
  int c = 65;
  char a = 'a';
  char z = 'A';
  printf("a -toPrint A = %d\n", a - z);
  printf("c = %c\n", c);

  return 0;
}
