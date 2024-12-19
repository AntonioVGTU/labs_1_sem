#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
// ������� ��� ������������ �������
int* full_array(int* arr, int size) {
    arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // ���������� ���������� �������
    }
    return arr;
}

// ������� ��� ������ �������
void put_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �������� ���������� �����
void sort_shell(int* arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    printf("������� ������ �������: ");
    scanf_s("%d", &size);

    int* ptrarr = NULL;
    ptrarr = full_array(ptrarr, size);

    printf("�������������� ������:\n");
    put_array(ptrarr, size);

    clock_t t = clock();

    sort_shell(ptrarr, size);

    double time = (double)(clock() - t) / CLOCKS_PER_SEC;

    printf("��������������� ������:\n");
    put_array(ptrarr, size);
    printf("����� ���������� ���������� �����: %.6f ������\n", time);

    free(ptrarr); // ������������ ������
    return 0;
}
