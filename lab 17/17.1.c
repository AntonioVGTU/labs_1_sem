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
        arr[i] = rand() % 100;
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

int main() {
    setlocale(LC_ALL, "ru");
    int* ptrarr = NULL;
    int size;

    printf("������� ������ �������: ");
    scanf("%d", &size);

    ptrarr = full_array(ptrarr, size);

    printf("��������������� ������:\n");
    put_array(ptrarr, size);

    clock_t t;
    double time;

    t = clock();

    sort_insert(ptrarr, size);

    time = (double)(clock() - t) / CLOCKS_PER_SEC;

    printf("��������������� ������:\n");
    put_array(ptrarr, size);

    printf("����� ���������� ���������: %.6f ������\n", time);

    free(ptrarr);  // ������������ ������������ ������
    return 0;
}