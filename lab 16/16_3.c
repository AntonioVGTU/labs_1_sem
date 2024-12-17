#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

// Функция для заполнения массива случайными числами от -1 до 1
double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2 - 1; // Случайные числа от -1 до 1
    }
    return ptr_array;
}

// Функция для печати элементов массива
int put_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf ", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

// Функция для вставки значения -999 перед максимальным элементом
double* insert_before_max(double* ptr_array, int size, int* new_size) {
    if (size == 0) {
        *new_size = size;
        return ptr_array;
    }

    // Найти максимальный элемент
    double max_value = ptr_array[0];
    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (ptr_array[i] > max_value) {
            max_value = ptr_array[i];
            max_index = i;
        }
    }

    // Создать новый массив с дополнительным элементом
    double* new_array = (double*)malloc((size + 1) * sizeof(double));
    if (new_array == NULL) {
        puts("error");
        return NULL;
    }

    // Копировать элементы до максимального элемента
    for (int i = 0; i < max_index; i++) {
        new_array[i] = ptr_array[i];
    }

    // Вставить -999 перед максимальным элементом
    new_array[max_index] = -999;

    // Копировать оставшиеся элементы
    for (int i = max_index; i < size; i++) {
        new_array[i + 1] = ptr_array[i];
    }

    *new_size = size + 1;
    free(ptr_array);
    return new_array;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL)); // Инициализация генератора случайных чисел

    double* ptr_array;
    int size;

    printf("Введите размер массива > ");
    scanf("%d", &size);

    // Выделение памяти под массив
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("error");
        return -1;
    }

    // Заполнение массива случайными числами от -1 до 1
    full_elements(ptr_array, size);

    // Печать элементов исходного массива
    printf("Исходный массив:\n");
    put_elements(ptr_array, size);

    // Вставка -999 перед максимальным элементом
    int new_size;
    double* new_array = insert_before_max(ptr_array, size, &new_size);
    if (new_array == NULL) {
        return -1;
    }

    // Печать элементов нового массива
    printf("Массив после вставки -999 перед максимальным элементом:\n");
    put_elements(new_array, new_size);

    // Освобождение памяти
    free(new_array);

    return 0;
}