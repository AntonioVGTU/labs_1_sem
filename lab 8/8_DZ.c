#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "ru");
    int N, A, B, C;
    printf("������� ����� ����� N: ");
    scanf_s("%d", &N);

    int sum = 0;
    A = pow(N, 2);
    B = pow(N * 2, 2);
    for (int i = 1; i <= N; i++) {
        sum += N + i;
    }
    C = A + B + sum;
    printf("����� ��������� �� N^2 �� (2N)^2: %d\n", C);
    return 0;
}