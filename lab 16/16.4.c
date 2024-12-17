#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
// Функция для генерации случайного вещественного числа в диапазоне от -100 до 100
double generate_random_number() {
    return (double)(rand() % 201 - 100);
}

// Функция для генерации массива со случайными вещественными числами
void generate_random_array(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = generate_random_number();
    }
}

// Функция для создания нового массива d
void create_d_array(double* a, int n, double* b, int m, double* c, int l, double** d, int* h) {
    // Найдем количество отрицательных элементов в массиве a
    int negative_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            negative_count++;
        }
    }

    // Количество элементов в массиве d
    *h = negative_count + m + (l / 5);
    *d = (double*)malloc(*h * sizeof(double));

    // Отрицательные элементы массива a в обратном порядке
    int index = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < 0) {
            (*d)[index++] = a[i];
        }
    }

    // Все элементы массива b
    for (int i = 0; i < m; i++) {
        (*d)[index++] = b[i];
    }

    // Каждый пятый элемент массива c
    for (int i = 4; i < l; i += 5) {
        (*d)[index++] = c[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    // Генерация случайных размеров массивов
    int n = rand() % 41 + 10;
    int m = rand() % 41 + 10;
    int l = rand() % 41 + 10;

    // Создание массивов
    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(m * sizeof(double));
    double* c = (double*)malloc(l * sizeof(double));

    // Генерация случайных чисел в массивах
    generate_random_array(a, n);
    generate_random_array(b, m);
    generate_random_array(c, l);

    // Создание нового массива d
    double* d;
    int h;
    create_d_array(a, n, b, m, c, l, &d, &h);

    // Вывод всех массивов на экран
    printf("Массив a:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n\n");

    printf("Массив b:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2f ", b[i]);
    }
    printf("\n\n");

    printf("Массив d:\n");
    for (int i = 0; i < h; i++) {
        printf("%.2f ", d[i]);
    }
    printf("\n\n");

    printf("Массив c:\n");
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