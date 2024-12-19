#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    printf("Введите размер массива: ");
    scanf_s("%d", &size);

    if (size <= 0) {
        printf("Размер массива должен быть положительным числом.\n");
        return 1;
    }

    double* array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        printf("Элемент %d: ", i);
        scanf_s("%lf", &array[i]);
    }

    // Вычисление суммы элементов от индекса 1 до индекса 3
    int begin, end;
    printf("Введите начальный индекс для суммы: ");
    scanf_s("%d", &begin);
    printf("Введите конечный индекс для суммы: ");
    scanf_s("%d", &end);

    if (begin < 0 || end >= size || begin > end) {
        printf("Некорректные индексы.\n");
        free(array);
        return 1;
    }

    double sum = sum_elements(array, begin, end);
    printf("Сумма элементов от индекса %d до индекса %d: %.2f\n", begin, end, sum);

    // Поиск элемента, равного заданному значению
    double element_to_find;
    printf("Введите элемент для поиска: ");
    scanf_s("%lf", &element_to_find);

    int index = find_element(array, size, element_to_find);
    if (index != -1) {
        printf("Элемент %.2f найден по индексу %d\n", element_to_find, index);
    }
    else {
        printf("Элемент %.2f не найден\n", element_to_find);
    }

    free(array);
    return 0;
}