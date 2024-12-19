#include <stdio.h>
#include <math.h>
#include <locale.h>
// Функция Y(x)
double Y(double x) {
    if (x > 0) {
        return log(cbrt(x * x * x));
    }
    else {
        return 0.0; // или можно вернуть NaN, если x <= 0
    }
}

// Функция V(x)
double V(double x) {
    if (x > 1) {
        double tg_value = tan(x * x - 1);
        if (tg_value >= 0) {
            return sqrt(tg_value);
        }
        else {
            return NAN; // Возвращаем NaN, если тангенс отрицательный
        }
    }
    else if (0 <= x && x <= 1) {
        return -2 * x;
    }
    else {
        return exp(cos(x));
    }
}

// Функция S(x)
double S(double x) {
    double term = (x - 1) / (x + 1);
    return term + pow(term, 3) / 3 + pow(term, 5) / 5 + pow(term, 7) / 7;
}

// Функция печати таблицы значений
void print_table(double (*func)(double), double start, double end, double step) {
    printf(" x      |  f(x)\n");
    printf("------------------\n");
    for (double x = start; x <= end; x += step) {
        double result = func(x);
        if (isnan(result)) {
            printf("%7.2f  |  NaN\n", x);
        }
        else {
            printf("%7.2f  |  %7.4f\n", x, result);
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    double start = 0.0;
    double end = 10.0;
    double step = 1.0;

    printf("Таблица значений для функции Y(x):\n");
    print_table(Y, start, end, step);

    printf("\nТаблица значений для функции V(x):\n");
    print_table(V, start, end, step);

    printf("\nТаблица значений для функции S(x):\n");
    print_table(S, start, end, step);

    return 0;
}