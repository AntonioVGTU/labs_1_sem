#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M_PI 3.141592653589793238462643383279 //; 6 13 0.71 ТОЧКА

double fucktorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double sin2(double x, int N) {
    double result = 0.0;
    for (int k = 0; k < N; k++) {
        int posl = 2 * k + 1;
        double term = pow(-1, k) * pow(x, posl) / fucktorial(posl);
        result += term;
    }
    return result;
}

double sin_eps(double x, double eps) {
    x = fmod(x, 2 * M_PI);
    if (x > M_PI) {
        x -= 2 * M_PI;
    }
    else if (x < -M_PI) {
        x += 2 * M_PI;
    }

    double term = x;
    double sum = term;
    int n = 1;
    while (fabs(term) > eps) {
        n += 2;
        term *= -x * x / (n * (n - 1));
        sum += term;
    }

    return sum;
}

double cosinus(double x, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double term = pow(x, 2 * i) / fucktorial(2 * i);
        if (i % 2 == 0) {
            sum += term; // Сложить положительный член
        }
        else {
            sum -= term; // Вычесть отрицательный член
        }
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "ru");
    double x, eps, x2;
    int N;
    system("color F0");

    printf("Введите x\n");
    scanf_s("%lf", &x);
    printf("Введите n\n");
    scanf_s("%d", &N);
    printf("Введите точность eps: ");
    scanf_s("%lf", &eps);

    x2 = x * M_PI / 180.0;

    float result1 = sin2(x, N);
    float result2 = sin(x);
    float result3 = sin_eps(x, eps);
    float result4 = cosinus(x, N);

    printf("sin1(%f) = %.4f\n", x, result1);
    printf("sin2(%f) = %.4f\n", x, result2);
    printf("sin3(%f) = %.4f\n", x, result3);
    printf("cot(%f) = %.4f\n\n", x, result4);
    printf("|    N     |   sin_N  |  отколнение |\n");

    float res2 = 0;
    int se = 0;

    for (int k = 0; k < N; k++) {
        int posl = 2 * k + 1;
        double term = pow(-1, k) * pow(x, posl) / fucktorial(posl);
        res2 += term;
        se++;
        printf("|%10d|%10f|%13f|\n", se, res2, result2 - res2);
    }

}