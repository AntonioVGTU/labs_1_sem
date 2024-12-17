#include <stdio.h>
#include<locale.h>
#include <stdlib.h>

#define TYPE char
#define FTYPE "%3c"
#define NSTR 100

struct Node {
    TYPE data;
    struct Node* next;
};

typedef struct {
    struct Node* front;
    struct Node* back;
} queue_list;

void enQueue(queue_list* que, TYPE element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (que->back) {
        que->back->next = newNode;
    }
    else {
        que->front = newNode; 
    }
    que->back = newNode;
}

TYPE deQueue(queue_list* que) {
    if (que->front == NULL) {
        return '\0'; 
    }
    struct Node* temp = que->front;
    TYPE value = temp->data;
    que->front = que->front->next;
    if (que->front == NULL) {
        que->back = NULL; 
    }
    free(temp);
    return value;
}

void queue_test() {
    queue_list Str;
    Str.back = Str.front = NULL;

    char temp[NSTR];
    system("chcp 1251");
    puts("¬ведите строки:");
    fgets(temp, NSTR - 1, stdin);

    for (int i = 0; i < NSTR - 1 && temp[i] != '\n' && temp[i]; i++) {
        enQueue(&Str, temp[i]);
    }

    while (Str.front) {
        printf(FTYPE, deQueue(&Str));
    }
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    queue_test();
    return 0;
}
