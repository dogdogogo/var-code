//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <cstdio>
#include <stdio.h>
#define MAXSIZE 101

typedef struct List {
  int data[MAXSIZE];
  int len;
} List;

void initList(List&);
bool append(List&, int);
bool insert(List&, int, int);
bool delByInd(List&, int, int&);
bool delByVal(List&, int, int&);
int locate(List&, int);
bool get(List&, int, int);

void prt(bool);
bool isEmpty(List&);
bool isFull(List&);
int getLen(List&);
void prtList(List&);

int main() {
  List l;
  initList(l);
  prtList(l);

  append(l, 101);
  append(l, 102);
  append(l, 103);
  prtList(l);
  insert(l, 2, 1002);
  insert(l, 5, 105);
  insert(l, 6, 106);
  insert(l, 7, 107);
  prtList(l);
  int getRet;
  delByInd(l, 2, getRet);
  printf("==> getRet = %d\n", getRet);
  prtList(l);
  delByVal(l, 107, getRet);
  printf("==> getRet = %d\n", getRet);
  prtList(l);
  delByVal(l, 105, getRet);
  printf("==> getRet = %d\n", getRet);
  prtList(l);
  printf("--> locate 103 at index %d\n", locate(l, 103));

  return 0;
}

void initList(List& L) {
  L.len = 0;
}

bool append(List& L, int num) {
  if (isFull(L)) return false;

  L.data[L.len] = num;
  L.len ++;
  printf("--> add %d\n", num);
  return true;
}

bool insert(List& L, int index, int num) {
  if (isFull(L)) return false;
  if (index < 1 || index > L.len + 1) return false;

  for (int i = L.len; i >= index; i --)
    L.data[i] = L.data[i - 1];
  L.data[index - 1] = num;
  L.len ++;
  printf("--> insert %d at index %d\n", num, index);
  return true;
}

bool delByInd(List& L, int index, int& ret) {
  if (index < 1 || index > L.len) return false;
  ret = L.data[index - 1];
  for (int i = index; i <= L.len - 1; i ++)
    L.data[i - 1] = L.data[i];
  L.len --;
  printf("==> delete %d by index %d\n", ret, index);
  return true;
}

bool delByVal(List& L, int del, int& ret) {
  if (isEmpty(L)) return false;
  bool flag = false;

  for (int i = 0; i < L.len; i ++) {
    if (L.data[i] == del) {
      flag = true;
      ret = i + 1;
      break;
    }
  }
  int fake;
  delByInd(L, ret, fake);

  return flag;
}

int locate(List& L, int ser) {
  if (isEmpty(L)) return -1;

  int ans = -1;
  for (int i = 0; i <= L.len - 1; i ++) {
    if (L.data[i] == ser) {
      ans = i + 1;
      break;
    }
  }
  return ans;
}

bool get(List& L, int index, int ret) {
  if (index < 1 || index > L.len) return false;

  ret = L.data[index - 1];
  return true;
}


void prt(bool b) {
  if (b)
    printf("--> ok\n");
  else
    printf("--> not ok\n");
}

bool isEmpty(List& L) {
  return L.len == 0;
}

bool isFull(List& L) {
  return L.len == MAXSIZE;
}

int getLen(List& L) {
  return L.len;
}

void prtList(List& L) {
  if (isEmpty(L)) {
    printf("==> Empty\n");
  } else {
    printf("==> print <==\n");
    printf("length -> %d  data -> ", L.len);
    for (int i = 0; i < L.len; i ++) {
      printf("%d ", L.data[i]);
    }
    printf("\n");
  }
}
