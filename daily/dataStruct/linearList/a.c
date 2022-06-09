//usr/bin/env gcc-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>

int main() {
  int a[] = {1, 2, 3};

  printf("size = %ld\n", sizeof(a));
  for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    printf("a[%d] = %d\n", i, *(a + i));

  return 0;
}
