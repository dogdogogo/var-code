//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main() {
  char a[] = "def";
  printf("sizeof a = %ld\n", sizeof(a));
  printf("strlen = %ld\n", strlen(a));
  printf("%d\n", 'a' == a[0]);

  char b[3];
  b[0] = 'x';
  b[1] = 'y';
  b[2] = '\0';
  printf("%s\n", b);

  return 0;
}
