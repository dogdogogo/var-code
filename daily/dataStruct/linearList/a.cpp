#include <stdio.h>
#include <stdlib.h>

int main() {
  char* a = (char*)malloc(sizeof(char));
  *a = 'a';
  printf("a = %c\n", *a);

  return 0;
}