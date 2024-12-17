#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Функция для вывода списка на экран
void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void remove_after_odd(Node** head) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data % 2 != 0) {
            Node* temp = current->next;
            if (temp != NULL) {
                current->next = temp->next;
                free(temp);
            }
            if (current->next != NULL) {
                temp = current->next;
                current->next = temp->next;
                free(temp);
            }
        }
        prev = current;
        current = current->next;
    }
}

// Основная функция
int main() {
    Node* head = NULL;
    setlocale(LC_ALL, "ru");
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    for (int i = 0; i < 12; i++) {
        append_node(&head, values[i]);
    }

    // Вывод списка до преобразования
    printf("Список до преобразования:\n");
    print_list(head);

    // Удаление двух элементов после каждого элемента с нечетным значением
    remove_after_odd(&head);

    // Вывод списка после преобразования
    printf("Список после преобразования:\n");
    print_list(head);

    // Освобождение памяти
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}