#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
// Функция для формирования массива
int* full_array(int* arr, int size) {
    arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Заполнение случайными числами
    }
    return arr;
}

// Функция для вывода массива
void put_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Алгоритм сортировки Шелла
void sort_shell(int* arr, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    printf("Введите размер массива: ");
    scanf_s("%d", &size);

    int* ptrarr = NULL;
    ptrarr = full_array(ptrarr, size);

    printf("Сформированный массив:\n");
    put_array(ptrarr, size);

    clock_t t = clock();

    sort_shell(ptrarr, size);

    double time = (double)(clock() - t) / CLOCKS_PER_SEC;

    printf("Отсортированный массив:\n");
    put_array(ptrarr, size);
    printf("Время выполнения сортировки Шелла: %.6f секунд\n", time);

    free(ptrarr); // Освобождение памяти
    return 0;
}
