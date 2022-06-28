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
  q.front = q.rear = (QueueNode*)malloc(sizeof(QueueNode));
  q.front->next = NULL;
}

bool enQueue(LinkQueue& q, int ins) {
  QueueNode* a = (QueueNode*)malloc(sizeof(QueueNode));
  if (a == NULL)
    return false;

  a->data = ins;
  a->next = NULL;
  q.rear->next = a;
  q.rear = a;
  return true;
}

bool deQueue(LinkQueue& q, int& ret) {
  if (empty(q))
    return false;

  QueueNode *del = q.front->next;
  ret = del->data;
  q.front->next = del->next;
  if (del == q.rear)
    q.rear = q.front;
  free(del);
  return true;
}


bool empty(LinkQueue& q) {
  return q.front == q.rear;
}

void prtQueue(LinkQueue& q) {
  if (empty(q)) {
    printf("Empty\n");
  } else {
    printf("$$ print Queue\n");
    QueueNode* t = q.front->next;
    while (t != NULL) {
      printf(" %4d <- ", t->data);
      t = t->next;
    }
    printf("\n");
  }
}
