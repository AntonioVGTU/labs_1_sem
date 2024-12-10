#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int* full_array(int* arr, int size) {
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("������ ��������� ������\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // ��������� ������ ���������� ������� �� 0 �� 99
    }

    return arr;
}

void put_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort_insert(int* ptrarr, int n) {
    for (int i = 1; i < n; i++) {
        int key = ptrarr[i];
        int j = i - 1;
        while (j >= 0 && ptrarr[j] > key) {
            ptrarr[j + 1] = ptrarr[j];
            j--;
        }
        ptrarr[j + 1] = key;
    }
}

void sort_selection(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = ptrarr[min_idx];
        ptrarr[min_idx] = ptrarr[i];
        ptrarr[i] = temp;
    }
}

void sort_bubble(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                int temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int* ptrarr = NULL;
    int size;
    int choice;

    printf("������� ������ �������: ");
    scanf_s("%d", &size);

    ptrarr = full_array(ptrarr, size);

    printf("��������������� ������:\n");
    put_array(ptrarr, size);

    printf("�������� ����� ����������:\n");
    printf("1. ���������� ���������\n");
    printf("2. ���������� �������\n");
    printf("3. ���������� ���������\n");
    printf("4. ������� ����������\n");
    scanf_s("%d", &choice);

    clock_t t;
    double time;

    t = clock();

    switch (choice) {
    case 1:
        sort_insert(ptrarr, size);
        break;
    case 2:
        sort_selection(ptrarr, size);
        break;
    case 3:
        sort_bubble(ptrarr, size);
        break;
    case 4:
        quick_sort(ptrarr, 0, size - 1);
        break;
    default:
        printf("�������� �����\n");
        free(ptrarr);
        return 1;
    }

    time = (double)(clock() - t) / CLOCKS_PER_SEC;

    printf("��������������� ������:\n");
    put_array(ptrarr, size);

    printf("����� ����������: %.2f ������\n", time);

    free(ptrarr);
    return 0;
}