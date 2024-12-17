#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// ������� ��� ��������� ���������� ������������� ����� � �������� ���������
double rand_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

// ������� ��� �������� ������ �������
void create_new_array(double* a, int n, double* b, int m, double* c, int l, double** d, int* h) {
    int count_negative_a = 0;
    int count_every_fifth_c = 0;

    // ������� ���������� ������������� ��������� � ������� a
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            count_negative_a++;
        }
    }

    // ������� ���������� ������� ������ �������� � ������� c
    for (int i = 4; i < l; i += 5) {
        count_every_fifth_c++;
    }

    // ����� ���������� ��������� � ����� �������
    *h = count_negative_a + m + count_every_fifth_c;
    *d = (double*)malloc(*h * sizeof(double));

    int index = 0;

    // ���������� ������������� ��������� ������� a � �������� �������
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < 0) {
            (*d)[index++] = a[i];
        }
    }

    // ���������� ���� ��������� ������� b
    for (int i = 0; i < m; i++) {
        (*d)[index++] = b[i];
    }

    // ���������� ������� ������ �������� ������� c
    for (int i = 4; i < l; i += 5) {
        (*d)[index++] = c[i];
    }
}

int main() {
    // ��������� ������� ������
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    // ��������� ���������� ���������� ��������� � ��������� �� 10 �� 50
    int n = 10 + rand() % 41;
    int m = 10 + rand() % 41;
    int l = 10 + rand() % 41;

    // ��������� �������� �� ���������� ������������� �������
    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(m * sizeof(double));
    double* c = (double*)malloc(l * sizeof(double));

    for (int i = 0; i < n; i++) {
        a[i] = rand_double(-100.0, 100.0);
    }

    for (int i = 0; i < m; i++) {
        b[i] = rand_double(-100.0, 100.0);
    }

    for (int i = 0; i < l; i++) {
        c[i] = rand_double(-100.0, 100.0);
    }

    // �������� ������ �������
    double* d;
    int h;
    create_new_array(a, n, b, m, c, l, &d, &h);

    // ����� �����������
    printf("������ a:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    printf("������ b:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2f ", b[i]);
    }
    printf("\n");

    printf("������ c:\n");
    for (int i = 0; i < l; i++) {
        printf("%.2f ", c[i]);
    }
    printf("\n");

    printf("����� ������ d:\n");
    for (int i = 0; i < h; i++) {
        printf("%.2f ", d[i]);
    }
    printf("\n");

    // ������������ ������
    free(a);
    free(b);
    free(c);
    free(d);

}