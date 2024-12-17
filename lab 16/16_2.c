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

// ������� ��� �������� ���� ������������ ��������� �������
double* remove_two_max_elements(double* ptr_array, int size, int* new_size) {
    if (size < 2) {
        *new_size = size;
        return ptr_array;
    }

    // ����� ��� ������������ ��������
    double max1 = -2, max2 = -2;
    int index1 = -1, index2 = -1;

    for (int i = 0; i < size; i++) {
        if (ptr_array[i] > max1) {
            max2 = max1;
            index2 = index1;
            max1 = ptr_array[i];
            index1 = i;
        }
        else if (ptr_array[i] > max2) {
            max2 = ptr_array[i];
            index2 = i;
        }
    }

    // ������� ��� ������������ ��������
    double* new_array = (double*)malloc((size - 2) * sizeof(double));
    if (new_array == NULL) {
        puts("error");
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i != index1 && i != index2) {
            new_array[j++] = ptr_array[i];
        }
    }

    *new_size = size - 2;
    free(ptr_array);

    // ����� ��������� ���������
    printf("��������� ��������: %lf � %lf\n", max1, max2);

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

    // �������� ���� ������������ ���������
    int new_size;
    double* new_array = remove_two_max_elements(ptr_array, size, &new_size);
    if (new_array == NULL) {
        return -1;
    }

    // ������ ��������� ������ �������
    printf("������ ����� �������� ���� ������������ ���������:\n");
    put_elements(new_array, new_size);

    // ������������ ������
    free(new_array);

    return 0;
}