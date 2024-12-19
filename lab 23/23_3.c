#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ����������� ��������� ��� �������� ���������� ������
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ������� ��� �������� ������ ����
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ������� ��� �������������� ������� � ��������� ������
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

// ������� ��� ������ ���������� ������
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ������� ��� ������ �������� � ��������� ������
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

// ������� ��� ���������� ���������� ������ �� ��� �����
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

// ������� ��� ������� ���� ��������������� ��������� �������
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

// ������� ��� ���������� ���������� ������ ��������
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
    printf("������� ���������� ���������: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    Node* head = arrayToLinkedList(arr, size);
    free(arr);

    printf("�������� ��������� ������:\n");
    printLinkedList(head);

    int key;
    printf("������� ������� ��� ������: ");
    scanf("%d", &key);
    Node* found = search(head, key);
    if (found) {
        printf("������� %d ������.\n", key);
    }
    else {
        printf("������� %d �� ������.\n", key);
    }

    head = mergeSort(head);
    printf("��������������� ��������� ������:\n");
    printLinkedList(head);

    // ������������ ������
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}