#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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

// Функция для вычисления значения функции в заданной точке
void compute_value(double (*func)(double)) {
    double x;
    printf("Введите значение x: ");
    scanf("%lf", &x);
    double result = func(x);
    if (isnan(result)) {
        printf("Значение функции в точке %.2f: NaN\n", x);
    }
    else {
        printf("Значение функции в точке %.2f: %.4f\n", x, result);
    }
}

// Функция для описания функции на заданном интервале
void describe_function(double (*func)(double), double start, double end, double step) {
    // Здесь можно добавить логику для описания функции на интервале
    // Например, проверка на возрастание/убывание, знакопеременность и т.д.
    printf("Описание функции на интервале [%.2f, %.2f] с шагом %.2f:\n", start, end, step);
    // Пример проверки на возрастание/убывание
    double prev_value = func(start);
    int increasing = 1, decreasing = 1, sign_changing = 0;
    for (double x = start + step; x <= end; x += step) {
        double current_value = func(x);
        if (current_value > prev_value) {
            decreasing = 0;
        }
        else if (current_value < prev_value) {
            increasing = 0;
        }
        if ((current_value > 0 && prev_value < 0) || (current_value < 0 && prev_value > 0)) {
            sign_changing = 1;
        }
        prev_value = current_value;
    }
    if (increasing) {
        printf("Функция возрастающая на интервале.\n");
    }
    else if (decreasing) {
        printf("Функция убывающая на интервале.\n");
    }
    else {
        printf("Функция не монотонная на интервале.\n");
    }
    if (sign_changing) {
        printf("Функция знакопеременная на интервале.\n");
    }
    else {
        printf("Функция не знакопеременная на интервале.\n");
    }
}

// Функция для отображения меню и обработки выбора пользователя
void menu() {
    int choice, func_choice;
    double start, end, step, x;
    double (*func)(double);

    while (1) {
        printf("\nМЕНЮ\n");
        printf("1. Вычислить значение\n");
        printf("2. Табулировать\n");
        printf("3. Описать функцию на интервале\n");
        printf("4. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("Выберите функцию:\n");
        printf("1. S(x)\n");
        printf("2. V(x)\n");
        printf("3. Y(x)\n");
        printf("Ввод: ");
        scanf("%d", &func_choice);

        switch (func_choice) {
        case 1:
            func = S;
            break;
        case 2:
            func = V;
            break;
        case 3:
            func = Y;
            break;
        default:
            printf("Неверный выбор функции.\n");
            continue;
        }

        switch (choice) {
        case 1:
            compute_value(func);
            break;
        case 2:
            printf("Введите начало интервала: ");
            scanf("%lf", &start);
            printf("Введите конец интервала: ");
            scanf("%lf", &end);
            printf("Введите шаг табуляции: ");
            scanf("%lf", &step);
            print_table(func, start, end, step);
            break;
        case 3:
            printf("Введите начало интервала: ");
            scanf("%lf", &start);
            printf("Введите конец интервала: ");
            scanf("%lf", &end);
            printf("Введите шаг: ");
            scanf("%lf", &step);
            describe_function(func, start, end, step);
            break;
        default:
            printf("Неверный выбор действия.\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    menu();
    return 0;
}