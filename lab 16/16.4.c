#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
// ������� ��� ��������� ���������� ������������� ����� � ��������� �� -100 �� 100
double generate_random_number() {
    return (double)(rand() % 201 - 100);
}

// ������� ��� ��������� ������� �� ���������� ������������� �������
void generate_random_array(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = generate_random_number();
    }
}

// ������� ��� �������� ������ ������� d
void create_d_array(double* a, int n, double* b, int m, double* c, int l, double** d, int* h) {
    // ������ ���������� ������������� ��������� � ������� a
    int negative_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            negative_count++;
        }
    }

    // ���������� ��������� � ������� d
    *h = negative_count + m + (l / 5);
    *d = (double*)malloc(*h * sizeof(double));

    // ������������� �������� ������� a � �������� �������
    int index = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < 0) {
            (*d)[index++] = a[i];
        }
    }

    // ��� �������� ������� b
    for (int i = 0; i < m; i++) {
        (*d)[index++] = b[i];
    }

    // ������ ����� ������� ������� c
    for (int i = 4; i < l; i += 5) {
        (*d)[index++] = c[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    // ��������� ��������� �������� ��������
    int n = rand() % 41 + 10;
    int m = rand() % 41 + 10;
    int l = rand() % 41 + 10;

    // �������� ��������
    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(m * sizeof(double));
    double* c = (double*)malloc(l * sizeof(double));

    // ��������� ��������� ����� � ��������
    generate_random_array(a, n);
    generate_random_array(b, m);
    generate_random_array(c, l);

    // �������� ������ ������� d
    double* d;
    int h;
    create_d_array(a, n, b, m, c, l, &d, &h);

    // ����� ���� �������� �� �����
    printf("������ a:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n\n");

    printf("������ b:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2f ", b[i]);
    }
    printf("\n\n");

    printf("������ d:\n");
    for (int i = 0; i < h; i++) {
        printf("%.2f ", d[i]);
    }
    printf("\n\n");

    printf("������ c:\n");
    for (int i = 0; i < l; i++) {
        printf("%.2f ", c[i]);
    }
    printf("\n\n");

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}