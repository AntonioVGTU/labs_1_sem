#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stdarg.h>

#define N 1000

// Функция для заполнения массива значениями
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = sin(i) + cos(i); // Пример заполнения значениями
    }
    return ptr_array;
}

// Функция для печати элементов массива
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lf ", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

// Функция для обработки элементов массива
double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = sqrt(fabs(ptr_array[i])); // Пример обработки значений
    }
    return ptr_array;
}

// Функция для вычисления суммы элементов массива от индекса begin до индекса end включительно
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// Функция для поиска элемента, равного заданному значению
int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i;
        }
    }
    return -1;
}

// Функция для поиска максимального по модулю значения, не равного заданному A
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

    printf("Введите размер массива > ");
    scanf("%d", &size);

    if (size > N) {
        printf("Размер массива превышает допустимый предел.\n");
        return 1;
    }

    full_elements(array, size);

    printf("Исходный массив:\n");
    put_elements(array, size);

    calc_elements(array, size);

    printf("Обработанный массив:\n");
    put_elements(array, size);

    int begin, end;
    printf("Введите начальный индекс для суммы > ");
    scanf("%d", &begin);
    printf("Введите конечный индекс для суммы > ");
    scanf("%d", &end);

    if (begin < 0 || end >= size || begin > end) {
        printf("Некорректные индексы.\n");
    }
    else {
        double sum = sum_elements(array, begin, end);
        printf("Сумма элементов от индекса %d до индекса %d: %lf\n", begin, end, sum);
    }

    double element;
    printf("Введите значение для поиска > ");
    scanf("%lf", &element);

    int index = find_element(array, size, element);
    if (index != -1) {
        printf("Элемент %lf найден по индексу %d\n", element, index);
    }
    else {
        printf("Элемент %lf не найден\n", element);
    }

    double A;
    printf("Введите значение A для поиска максимального по модулю значения, не равного A > ");
    scanf("%lf", &A);

    double max_abs_not_equal = find_max_abs_not_equal(array, size, A);
    if (max_abs_not_equal != -1) {
        printf("Максимальное по модулю значение, не равное %lf: %lf\n", A, max_abs_not_equal);
    }
    else {
        printf("Нет значений, не равных %lf\n", A);
    }

}