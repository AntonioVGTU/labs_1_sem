#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ������� ��� ���������� ����� ��������� ������� �� ������� begin �� ������� end ������������
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// ������� ��� ������ ��������, ������� ��������� ��������
int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    printf("������� ������ �������: ");
    scanf_s("%d", &size);

    if (size <= 0) {
        printf("������ ������� ������ ���� ������������� ������.\n");
        return 1;
    }

    double* array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        printf("������ ��������� ������.\n");
        return 1;
    }

    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        printf("������� %d: ", i);
        scanf_s("%lf", &array[i]);
    }

    // ���������� ����� ��������� �� ������� 1 �� ������� 3
    int begin, end;
    printf("������� ��������� ������ ��� �����: ");
    scanf_s("%d", &begin);
    printf("������� �������� ������ ��� �����: ");
    scanf_s("%d", &end);

    if (begin < 0 || end >= size || begin > end) {
        printf("������������ �������.\n");
        free(array);
        return 1;
    }

    double sum = sum_elements(array, begin, end);
    printf("����� ��������� �� ������� %d �� ������� %d: %.2f\n", begin, end, sum);

    // ����� ��������, ������� ��������� ��������
    double element_to_find;
    printf("������� ������� ��� ������: ");
    scanf_s("%lf", &element_to_find);

    int index = find_element(array, size, element_to_find);
    if (index != -1) {
        printf("������� %.2f ������ �� ������� %d\n", element_to_find, index);
    }
    else {
        printf("������� %.2f �� ������\n", element_to_find);
    }

    free(array);
    return 0;
}