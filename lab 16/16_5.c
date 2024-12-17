#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Функция для генерации случайного вещественного числа в заданном диапазоне
double rand_double(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

// Функция для создания нового массива
void create_new_array(double* a, int n, double* b, int m, double* c, int l, double** d, int* h) {
    int count_negative_a = 0;
    int count_every_fifth_c = 0;

    // Подсчет количества отрицательных элементов в массиве a
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            count_negative_a++;
        }
    }

    // Подсчет количества каждого пятого элемента в массиве c
    for (int i = 4; i < l; i += 5) {
        count_every_fifth_c++;
    }

    // Общее количество элементов в новом массиве
    *h = count_negative_a + m + count_every_fifth_c;
    *d = (double*)malloc(*h * sizeof(double));

    int index = 0;

    // Добавление отрицательных элементов массива a в обратном порядке
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < 0) {
            (*d)[index++] = a[i];
        }
    }

    // Добавление всех элементов массива b
    for (int i = 0; i < m; i++) {
        (*d)[index++] = b[i];
    }

    // Добавление каждого пятого элемента массива c
    for (int i = 4; i < l; i += 5) {
        (*d)[index++] = c[i];
    }
}

int main() {
    // Установка русской локали
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    // Генерация случайного количества элементов в интервале от 10 до 50
    int n = 10 + rand() % 41;
    int m = 10 + rand() % 41;
    int l = 10 + rand() % 41;

    // Генерация массивов со случайными вещественными числами
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

    // Создание нового массива
    double* d;
    int h;
    create_new_array(a, n, b, m, c, l, &d, &h);

    // Вывод результатов
    printf("Массив a:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");

    printf("Массив b:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2f ", b[i]);
    }
    printf("\n");

    printf("Массив c:\n");
    for (int i = 0; i < l; i++) {
        printf("%.2f ", c[i]);
    }
    printf("\n");

    printf("Новый массив d:\n");
    for (int i = 0; i < h; i++) {
        printf("%.2f ", d[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(a);
    free(b);
    free(c);
    free(d);

}