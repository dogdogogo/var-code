//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>

#define MaxLen 255

typedef struct {
  char str[MaxLen];
  int len;
} String;

bool subString(String&, String&, int, int);
int strCompare(String&, String&);
int index(String&, String&);

int main() {

  return 0;
}

bool subString(String& s1, String& s2, int pos, int len) {
  if (pos + len - 1 > s2.len)
    return false;

  for (int i = pos; i < pos + len; i ++)
    s1.str[i - pos + 1] = s2.str[i];
  s1.len = len;
  return true;
}

int strCompare(String& s1, String& s2) {
  int end = s1.len;
  if (s1.len > s2.len)
    end = s2.len;

  for (int i = 1; i <= end; i ++) {
    if (s1.str[i] != s2.str[i])
      return s1.str[i] - s2.str[i];
  }

  if (s1.len > s2.len)
    return 1;
  else if (s1.len < s2.len)
    return -1;
  else
    return 0;
}

int index(String& s1, String& s2) {
  if (s2.len > s1.len)
    return 0;

  int s1i, s2i, times;
  for (int i = 1; i <= s1.len - s2.len + 1; i ++) {
    s1i = i;
    s2i = 1;
    times = 1;
    while (s1.str[s1i] == s2.str[s2i] && times <= s2.len) {
      s1i ++;
      s2i ++;
      times ++;
    }
    if (times == s2.len + 1) return i;
  }

  return 0;
}
