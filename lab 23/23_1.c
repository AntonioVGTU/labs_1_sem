#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
// Определение структуры узла списка
struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

// Тип указателя на узел списка
typedef struct listitem* List;

// Инициализация списка пустым содержимым
void initlist(List* list) {
    *list = NULL;
}

// Вставка в список перед узлом со значением поля number=val
void insertfront_number(List* list, int val) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->number = val;
    newNode->name[0] = '\0';
    newNode->next = *list;
    *list = newNode;
}

// Вставка в список перед узлом со значением поля number=val
void insertback_number(List* list, int val) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
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

// Вставка в список перед узлом со значением str в поле name
void insertfront_name(List* list, char* str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->number = 0;
    strncpy(newNode->name, str, 79);
    newNode->name[79] = '\0';
    newNode->next = *list;
    *list = newNode;
}

// Вставка в список перед узлом со значением str в поле name
void insertback_name(List* list, char* str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
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

// Проверяет, является ли список пустым
bool isempty(List* list) {
    return *list == NULL;
}

// Определение длины списка
int length(List list) {
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    return count;
}

// Удаление заданного узла node из списка
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

// Нахождение узла со значением n в поле number
List getitem_number(List list, int n) {
    while (list != NULL) {
        if (list->number == n) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}


// Освобождение памяти, занятой списком
void freelist(List* list) {
    List current = *list;
    while (current != NULL) {
        List temp = current;
        current = current->next;
        free(temp);
    }
    *list = NULL;
}

// Функция для вывода списка
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
        printf("Выберите операцию:\n");
        printf("1. Вставить элемент в начало списка \n");
        printf("2. Вставить элемент в конец списка \n");
        printf("3. Найти элемент\n");
        printf("4. Удалить элемент\n");
        printf("5. Вывести список\n");
        printf("6. Выйти\n");
        scanf("%d", &choice);
        getchar(); // Считываем символ новой строки

        switch (choice) {
        case 1:
            printf("Введите число: ");
            scanf("%d", &number);
            getchar(); // Считываем символ новой строки
            insertfront_number(&myList, number);
            break;
        case 2:
            printf("Введите число: ");
            scanf("%d", &number);
            getchar(); // Считываем символ новой строки
            insertback_number(&myList, number);
            break;
        case 3:
            printf("Введите число для поиска: ");
            scanf("%d", &number);
            getchar(); // Считываем символ новой строки
            List item = getitem_number(myList, number);
            if (item != NULL) {
                printf("Найден элемент с числом %d: %s\n", item->number, item->name);
            }
            else {
                printf("Элемент с числом %d не найден\n", number);
            }
            break;
        case 4:
            printf("Введите для удаления: ");
            scanf("%d", &number);
            getchar(); // Считываем символ новой строки
            item = getitem_number(myList, number);
            if (item != NULL) {
                destroyItem(&myList, item);
                printf("Элемент с числом %d удален\n", number);
            }
            else {
                printf("Элемент с числом %d не найден\n", number);
            }
            break;
        case 5:
            printf("Список:\n");
            printlist(myList);
            break;
        case 6:
            freelist(&myList);
            return 0;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    }

    return 0;
}