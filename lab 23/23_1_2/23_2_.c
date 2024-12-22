#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include <locale.h>

void initlist(List* list) {
	*list = NULL;
}

void insertback_by_name(List* list, char* str) {
	List newNode = (List)malloc(sizeof(struct listitem));
	newNode->number = 0;
	strcpy(newNode->name, str);
	newNode->next = NULL;

	if (*list == NULL) {
		*list = newNode;
	}
	else {
		List temp = *list;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void destroyItem(List* list, List node) {
	if (*list == NULL || node == NULL) return;

	if (*list == node) {
		*list = node->next;
		free(node);
		return;
	}

	List temp = *list;
	while (temp->next != NULL && temp->next != node) {
		temp = temp->next;
	}

	if (temp->next == node) {
		temp->next = node->next;
		free(node);
	}
}

List getitem_by_name(List list, char* str) {
	while (list != NULL) {
		if (strcmp(list->name, str) == 0) {
			return list;
		}
		list = list->next;
	}
	return NULL;
}

int length(List list) {
	int len = 0;
	while (list != NULL) {
		len++;
		list = list->next;
	}
	return len;
}

int main() {
	setlocale(LC_ALL, "ru");
	List myList;
	initlist(&myList);

	char z[20], s4[20];
	int choise, s1, s3, s2;

	insertback_by_name(&myList, "Get_out_of_bed");
	insertback_by_name(&myList, "Go_to_VGTU");
	insertback_by_name(&myList, "Go_home");

	do {
		List temp = myList;
		int ff = 1;
		printf("Меню\n");
		printf("1 - добавить задачу\n");
		printf("2 - Вывести список N задач\n");
		printf("0 - Выход\n");
		printf("Ваш выбор? ");
		scanf("%d", &choise);

		switch (choise) {
		case 1:
			printf("Введите задачу: ");
			scanf("%s", z);
			insertback_by_name(&myList, z);
			break;

		case 2:
			printf("Сколько элементов вывести? (Всего - %d)\n", length(myList));
			scanf("%d", &s1);

			if (s1 > length(myList)) {
				printf("Элементов в списке меньше\n");
				break;
			}

			for (int i = 0; i < s1; i++) {
				if (temp != NULL) {
					printf("Задача %d: %s\n", ff, temp->name);
					temp = temp->next;
					ff += 1;
				}
			}
			break;

		case 3:
			printf("Какую задачу удалить? ");
			scanf("%s", s4);
			List foundByName = getitem_by_name(myList, s4);
			destroyItem(&myList, foundByName);
			break;
		}
	} while (choise != 0);
}