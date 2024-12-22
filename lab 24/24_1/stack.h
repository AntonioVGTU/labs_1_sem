#ifndef _STACK_H
#define _STACK_H

#define NMAX 100

#define TYPE char

#define FTYPE "%3c,"

typedef struct  Stack {

	int   top;

	TYPE  data[NMAX];

} stack;

int isempty(stack* s);// проверить, если стек пуст {top==0} вернуть 1, иначе 0

int isfull(stack* s);// проверить, если стек полон {top==NMAX-1} вернуть 1, иначе 0

int push(stack* s, TYPE a);//поместить элемент а в стек  {top=top+1, data[top]=a}, если стек не полон

TYPE pop(stack* s);// вернуть элемент {data[top]}, удалив его из стека {top=top-1}, если стек не пуст

TYPE top(stack* s);//вернуть значение элемента в вершине стека {return data[top]}

#endif /* _STACK_H */