#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
// ����������� ��������� ���� ������
struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

// ��� ��������� �� ���� ������
typedef struct listitem* List;

// ������������� ������ ������ ����������
void initlist(List* list) {
    *list = NULL;
}

// ������� � ������ ����� ����� �� ��������� ���� number=val
void insertfront_number(List* list, int val) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "������ ��������� ������\n");
        exit(1);
    }
    newNode->number = val;
    newNode->name[0] = '\0';
    newNode->next = *list;
    *list = newNode;
}

// ������� � ������ ����� ����� �� ��������� ���� number=val
void insertback_number(List* list, int val) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "������ ��������� ������\n");
        exit(1);
    }
    newNode->number = val;
    newNode->name[0] = '\0';
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
    }
    else {
        List current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// ������� � ������ ����� ����� �� ��������� str � ���� name
void insertfront_name(List* list, char* str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "������ ��������� ������\n");
        exit(1);
    }
    newNode->number = 0;
    strncpy(newNode->name, str, 79);
    newNode->name[79] = '\0';
    newNode->next = *list;
    *list = newNode;
}

// ������� � ������ ����� ����� �� ��������� str � ���� name
void insertback_name(List* list, char* str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "������ ��������� ������\n");
        exit(1);
    }
    newNode->number = 0;
    strncpy(newNode->name, str, 79);
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
    }
    else {
        List current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// ���������, �������� �� ������ ������
bool isempty(List* list) {
    return *list == NULL;
}

// ����������� ����� ������
int length(List list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

// �������� ��������� ���� node �� ������
void destroyItem(List* list, List node) {
    if (*list == NULL || node == NULL) {
        return;
    }

    if (*list == node) {
        *list = node->next;
        free(node);
        return;
    }

    List current = *list;
    while (current->next != NULL && current->next != node) {
        current = current->next;
    }

    if (current->next == node) {
        current->next = node->next;
        free(node);
    }
}

// ���������� ���� �� ��������� n � ���� number
List getitem_number(List list, int n) {
    while (list != NULL) {
        if (list->number == n) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}


// ������������ ������, ������� �������
void freelist(List* list) {
    List current = *list;
    while (current != NULL) {
        List temp = current;
        current = current->next;
        free(temp);
    }
    *list = NULL;
}

// ������� ��� ������ ������
void printlist(List list) {
    while (list != NULL) {
        printf(": %d\n", list->number);
        list = list->next;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    List myList;
    initlist(&myList);

    int choice, number;;

    while (1) {
        printf("�������� ��������:\n");
        printf("1. �������� ������� � ������ ������ \n");
        printf("2. �������� ������� � ����� ������ \n");
        printf("3. ����� �������\n");
        printf("4. ������� �������\n");
        printf("5. ������� ������\n");
        printf("6. �����\n");
        scanf("%d", &choice);
        getchar(); // ��������� ������ ����� ������

        switch (choice) {
        case 1:
            printf("������� �����: ");
            scanf("%d", &number);
            getchar(); // ��������� ������ ����� ������
            insertfront_number(&myList, number);
            break;
        case 2:
            printf("������� �����: ");
            scanf("%d", &number);
            getchar(); // ��������� ������ ����� ������
            insertback_number(&myList, number);
            break;
        case 3:
            printf("������� ����� ��� ������: ");
            scanf("%d", &number);
            getchar(); // ��������� ������ ����� ������
            List item = getitem_number(myList, number);
            if (item != NULL) {
                printf("������ ������� � ������ %d: %s\n", item->number, item->name);
            }
            else {
                printf("������� � ������ %d �� ������\n", number);
            }
            break;
        case 4:
            printf("������� ��� ��������: ");
            scanf("%d", &number);
            getchar(); // ��������� ������ ����� ������
            item = getitem_number(myList, number);
            if (item != NULL) {
                destroyItem(&myList, item);
                printf("������� � ������ %d ������\n", number);
            }
            else {
                printf("������� � ������ %d �� ������\n", number);
            }
            break;
        case 5:
            printf("������:\n");
            printlist(myList);
            break;
        case 6:
            freelist(&myList);
            return 0;
        default:
            printf("�������� �����. ���������� �����.\n");
        }
    }

    return 0;
}