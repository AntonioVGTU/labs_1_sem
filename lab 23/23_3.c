#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Определение структуры для элемента связанного списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Функция для создания нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функция для преобразования массива в связанный список
Node* arrayToLinkedList(int arr[], int size) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < size; i++) {
        Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Функция для печати связанного списка
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Функция для поиска элемента в связанном списке
Node* search(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Функция для разделения связанного списка на две части
void split(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Функция для слияния двух отсортированных связанных списков
Node* sortedMerge(Node* a, Node* b) {
    Node* result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Функция для сортировки связанного списка слиянием
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* a;
    Node* b;

    split(head, &a, &b);

    a = mergeSort(a);
    b = mergeSort(b);

    return sortedMerge(a, b);
}

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    printf("Введите количество элементов: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    Node* head = arrayToLinkedList(arr, size);
    free(arr);

    printf("Исходный связанный список:\n");
    printLinkedList(head);

    int key;
    printf("Введите элемент для поиска: ");
    scanf("%d", &key);
    Node* found = search(head, key);
    if (found) {
        printf("Элемент %d найден.\n", key);
    }
    else {
        printf("Элемент %d не найден.\n", key);
    }

    head = mergeSort(head);
    printf("Отсортированный связанный список:\n");
    printLinkedList(head);

    // Освобождение памяти
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}