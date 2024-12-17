#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Функция для извлечения элемента из стека (Pop)
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Стек пуст\n");
        return -1; 
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}


void print_stack(Stack* stack) {
    Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void swap_halves(Stack* stack) {
    if (stack->top == NULL) {
        printf("Стек пуст\n");
        return;
    }

    Stack* temp_stack = create_stack();

    int count = 0;
    Node* temp = stack->top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int half_count = count / 2;
    for (int i = 0; i < half_count; i++) {
        push(temp_stack, pop(stack));
    }

    Stack* lower_half = create_stack();
    while (stack->top != NULL) {
        push(lower_half, pop(stack));
    }

    while (temp_stack->top != NULL) {
        push(stack, pop(temp_stack));
    }

    while (lower_half->top != NULL) {
        push(stack, pop(lower_half));
    }

    free(temp_stack);
    free(lower_half);
}

int main() {
    Stack* stack = create_stack();
    setlocale(LC_ALL, "ru");
    // Заполнение стека числами, введенными с клавиатуры
    int num;
    printf("Введите числа для заполнения стека (введите -1 для завершения):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        push(stack, num);
    }

    // Вывод стека до преобразования
    printf("Стек до преобразования:\n");
    print_stack(stack);

    // Перемещение верхней и нижней половин стека
    swap_halves(stack);

    // Вывод стека после преобразования
    printf("Стек после преобразования:\n");
    print_stack(stack);

    // Освобождение памяти
    while (stack->top != NULL) {
        pop(stack);
    }
    free(stack);

    return 0;
}