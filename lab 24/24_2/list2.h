#ifndef _LIST2_H
#define _LIST2_H
#define TYPE char

struct  Node {

  TYPE data;

 struct Node * next;

};

typedef struct  {

   struct  Node *queue;

  struct  Node * front;

  struct  Node * back;

 } queue_list;

 void enQueue(queue_list *que, TYPE element);//добавить элемент в очередь

 TYPE deQueue(queue_list *que);//извлечь элемент из очереди

#endif /* _LIST2_H */