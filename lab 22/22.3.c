#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef double (*TFun)(double);

int calculate(TFun prtf, double* x, int n) {
    for (int i = 0; i < n; i++) {
        if (prtf(x[i]) == 0) {
            return 1; 
        }
    }
    return 0;
}

void transform(TFun prtf, double xmin, double dx, double xmax) {
    for (double x = xmin; x <= xmax; x += dx) {
        printf("f(%f) = %f\n", x, prtf(x));
    }
}

double example_function(double x) {
    return x * x - 4; 
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    printf("¬ведите количество элементов в массиве x: ");
    scanf_s("%d", &n);

    double* x = (double*)malloc(n * sizeof(double));
    printf("¬ведите элементы массива x:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%lf", &x[i]);
    }

    double xmin, dx, xmax;
    printf("¬ведите начальное значение xmin: ");
    scanf_s("%lf", &xmin);
    printf("¬ведите шаг dx: ");
    scanf_s("%lf", &dx);
    printf("¬ведите конечное значение xmax: ");
    scanf_s("%lf", &xmax);

    int result = calculate(example_function, x, n);
    if (result) {
        printf("‘ункци€ пересекает ось ординат.\n");
    }
    else {
        printf("‘ункци€ не пересекает ось ординат.\n");
    }

    printf("«начени€ функции на интервале [%f, %f] с шагом %f:\n", xmin, xmax, dx);
    transform(example_function, xmin, dx, xmax);

    free(x);

    return 0;
}