//usr/bin/env gcc-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>

void A(int* i) {
  *i = 101;
}

int main() {
  printf("hello\n");

  return 0;
}
