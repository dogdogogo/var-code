//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef struct {
  int data[MaxSize];
  int front, rear;
  int size;
} Queue;

void initQueue(Queue&);
bool enQueue(Queue&, int);
bool deQueue(Queue&, int&);
bool head(Queue&, int&);

bool empty(Queue&);
bool full(Queue&);
void prtQueue(Queue&);

int main() {
  Queue Q;
  initQueue(Q);

  enQueue(Q, 100);
  enQueue(Q, 101);
  enQueue(Q, 102);
  enQueue(Q, 103);
  enQueue(Q, 104);
  prtQueue(Q);
  enQueue(Q, 10086);

  int ret;
  deQueue(Q, ret);
  printf("ret = %d\n", ret);
  prtQueue(Q);
  deQueue(Q, ret);
  deQueue(Q, ret);
  deQueue(Q, ret);
  prtQueue(Q);

  enQueue(Q, 105);
  enQueue(Q, 106);
  enQueue(Q, 107);
  enQueue(Q, 108);
  prtQueue(Q);
  enQueue(Q, 10086);

  head(Q, ret);
  printf("head = %d\n", ret);

  return 0;
}

void initQueue(Queue& q) {
  q.size = 0;
  q.front = q.rear = 0;
}

bool enQueue(Queue& q, int ins) {
  if (q.size == MaxSize) {
    printf("Full\n");
    return false;
  }

  q.size ++;
  q.data[q.rear] = ins;
  q.rear = (q.rear + 1) % MaxSize;
  return true;
}

bool deQueue(Queue& q, int& ret) {
  if (q.size == 0) {
    printf("Empty\n");
    return false;
  }

  q.size --;
  ret = q.data[q.front];
  q.front = (q.front + 1) % MaxSize;
  return true;
}

bool head(Queue& q, int& ret) {
  if (empty(q))
    return false;

  ret = q.data[q.front];
  return true;
}


bool empty(Queue& q) {
  return q.size == 0;
}

bool full(Queue& q) {
  return q.size == MaxSize;
}

void prtQueue(Queue& q) {
  printf("$$ print Queue\n");
  if (q.size == 0) {
    printf("Empty\n");
  } else {
    int t = q.front;

    do {
      printf(" %4d <- ", q.data[t]);
      t = (t + 1) % MaxSize;
    } while (t != q.rear);
    printf("\n");
  }
}
