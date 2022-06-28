//usr/bin/env g++-11 -o main "$0" && ./main; rm -rf main; exit
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
  int data;
  struct QueueNode *next;
} QueueNode;

typedef struct {
  QueueNode *front, *rear;
} LinkQueue;

void initQueue(LinkQueue&);
bool enQueue(LinkQueue&, int);
bool deQueue(LinkQueue&, int&);

bool empty(LinkQueue&);
void prtQueue(LinkQueue&);

int main() {
  LinkQueue Q;
  initQueue(Q);
  prtQueue(Q);

  enQueue(Q, 100);
  enQueue(Q, 101);
  enQueue(Q, 102);
  enQueue(Q, 103);
  enQueue(Q, 104);
  prtQueue(Q);

  int ret;
  deQueue(Q, ret);
  printf("ret = %d\n", ret);
  deQueue(Q, ret);
  prtQueue(Q);

  return 0;
}

void initQueue(LinkQueue& q) {
  q.front = q.rear = NULL;
}

bool enQueue(LinkQueue& q, int ins) {
  QueueNode* a = (QueueNode*)malloc(sizeof(QueueNode));
  if (a == NULL)
    return false;

  a->data = ins;
  a->next = NULL;
  if (empty(q)) {
    q.front = q.rear = a;
  } else {
    q.rear->next = a;
    q.rear = a;
  }
  return true;
}

bool deQueue(LinkQueue& q, int& ret) {
  if (empty(q))
    return false;

  ret = q.front->data;
  QueueNode* t = q.front;
  q.front = t->next;
  if (q.front == NULL)
    q.front = q.rear = NULL;
  free(t);
  return true;
}


bool empty(LinkQueue& q) {
  return q.front == NULL;
}

void prtQueue(LinkQueue& q) {
  if (empty(q)) {
    printf("Empty\n");
  } else {
    QueueNode* t = q.front;
    printf("$$ print Queue\n");
    while (t != NULL) {
      printf(" %4d <- ", t->data);
      t = t->next;
    }
    printf("\n");
  }
}
