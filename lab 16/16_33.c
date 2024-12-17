#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

// ������� ��� ���������� ������� ���������� ������� �� -1 �� 1
double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2 - 1; // ��������� ����� �� -1 �� 1
    }
    return ptr_array;
}

// ������� ��� ������ ��������� �������
int put_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf ", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

// ������� ��� ������� �������� -999 ����� ������������ ���������
double* insert_before_max(double* ptr_array, int size, int* new_size) {
    if (size == 0) {
        *new_size = size;
        return ptr_array;
    }

    // ����� ������������ �������
    double max_value = ptr_array[0];
    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (ptr_array[i] > max_value) {
            max_value = ptr_array[i];
            max_index = i;
        }
    }

    // ������� ����� ������ � �������������� ���������
    double* new_array = (double*)malloc((size + 1) * sizeof(double));
    if (new_array == NULL) {
        puts("error");
        return NULL;
    }

    // ���������� �������� �� ������������� ��������
    for (int i = 0; i < max_index; i++) {
        new_array[i] = ptr_array[i];
    }

    // �������� -999 ����� ������������ ���������
    new_array[max_index] = -999;

    // ���������� ���������� ��������
    for (int i = max_index; i < size; i++) {
        new_array[i + 1] = ptr_array[i];
    }

    *new_size = size + 1;
    free(ptr_array);
    return new_array;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL)); // ������������� ���������� ��������� �����

    double* ptr_array;
    int size;

    printf("������� ������ ������� > ");
    scanf("%d", &size);

    // ��������� ������ ��� ������
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    // ���������� ������� ���������� ������� �� -1 �� 1
    full_elements(ptr_array, size);

    // ������ ��������� ��������� �������
    printf("�������� ������:\n");
    put_elements(ptr_array, size);

    // ������� -999 ����� ������������ ���������
    int new_size;
    double* new_array = insert_before_max(ptr_array, size, &new_size);
    if (new_array == NULL) {
        return -1;
    }

    // ������ ��������� ������ �������
    printf("������ ����� ������� -999 ����� ������������ ���������:\n");
    put_elements(new_array, new_size);

    // ������������ ������
    free(new_array);

    return 0;
}