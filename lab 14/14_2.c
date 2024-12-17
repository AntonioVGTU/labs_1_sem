#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stdarg.h>

#define N 1000

// ������� ��� ���������� ������� ����������
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = sin(i) + cos(i); // ������ ���������� ����������
    }
    return ptr_array;
}

// ������� ��� ������ ��������� �������
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf ", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

// ������� ��� ��������� ��������� �������
double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = sqrt(fabs(ptr_array[i])); // ������ ��������� ��������
    }
    return ptr_array;
}

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

// ������� ��� ������ ������������� �� ������ ��������, �� ������� ��������� A
double find_max_abs_not_equal(double* ptr_array, int n, ...) {
    va_list args;
    va_start(args, n);
    double A = va_arg(args, double);
    va_end(args);

    double max_abs = -1;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] != A && fabs(ptr_array[i]) > max_abs) {
            max_abs = fabs(ptr_array[i]);
        }
    }
    return max_abs;
}

int main() {
    setlocale(LC_ALL, "ru");

    double array[N];
    int size;

    printf("������� ������ ������� > ");
    scanf("%d", &size);

    if (size > N) {
        printf("������ ������� ��������� ���������� ������.\n");
        return 1;
    }

    full_elements(array, size);

    printf("�������� ������:\n");
    put_elements(array, size);

    calc_elements(array, size);

    printf("������������ ������:\n");
    put_elements(array, size);

    int begin, end;
    printf("������� ��������� ������ ��� ����� > ");
    scanf("%d", &begin);
    printf("������� �������� ������ ��� ����� > ");
    scanf("%d", &end);

    if (begin < 0 || end >= size || begin > end) {
        printf("������������ �������.\n");
    }
    else {
        double sum = sum_elements(array, begin, end);
        printf("����� ��������� �� ������� %d �� ������� %d: %lf\n", begin, end, sum);
    }

    double element;
    printf("������� �������� ��� ������ > ");
    scanf("%lf", &element);

    int index = find_element(array, size, element);
    if (index != -1) {
        printf("������� %lf ������ �� ������� %d\n", element, index);
    }
    else {
        printf("������� %lf �� ������\n", element);
    }

    double A;
    printf("������� �������� A ��� ������ ������������� �� ������ ��������, �� ������� A > ");
    scanf("%lf", &A);

    double max_abs_not_equal = find_max_abs_not_equal(array, size, A);
    if (max_abs_not_equal != -1) {
        printf("������������ �� ������ ��������, �� ������ %lf: %lf\n", A, max_abs_not_equal);
    }
    else {
        printf("��� ��������, �� ������ %lf\n", A);
    }

}