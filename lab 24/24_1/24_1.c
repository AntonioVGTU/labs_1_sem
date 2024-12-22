#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "stack.h"

int isempty(stack* s) {
    return s->top == 0;
}

int isfull(stack* s) {
    return s->top == NMAX - 1;
}

// добавить элемент в стек
int push(stack* s, TYPE a) {
    s->data[++(s->top)] = a;
    return 1;
}

// извлечь элемент из стека
TYPE pop(stack* s) {
    return s->data[(s->top)--];
}

// элемент на вершине стека
TYPE top(stack* s) {
    return s->data[s->top];
}

// содержимое стека (без изменения)
void display(stack* s) {
    int i = s->top;
    while (i > 0)
        printf(FTYPE, s->data[i--]);
    printf("\n");
}

int main() {
    stack s;
    s.top = 0;
    setlocale(LC_ALL, "ru");

    char input[NMAX];
    printf("Введите строку ");
    fgets(input, NMAX, stdin);

    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        push(&s, input[i]);
    }

    printf("Содержимое стека: \n");
    display(&s);

    return 0;
}
//элементы записываются в стек по порядку: 12345, 5 на вершине, в позиции top, поэтому выводится зеркально