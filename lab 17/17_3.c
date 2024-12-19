#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
// Реализация сортировки Шелла
void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Реализация быстрой сортировки
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Реализация сортировки слиянием
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int left_size = m - l + 1;
    int right_size = r - m;
    int* L = malloc(left_size * sizeof(int));
    int* R = malloc(right_size * sizeof(int));

    for (i = 0; i < left_size; i++)
        L[i] = arr[l + i];
    for (j = 0; j < right_size; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < left_size && j < right_size) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Для сортировки стандартной библиотеки
int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Функция для тестирования времени сортировки
void test_sorting_algorithms(int size) {
    int* array = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000;
    }

    // Сортировка Шелла
    clock_t start = clock();
    shell_sort(array, size);
    printf("сортировка шелла для %d элементов: %.6f секунд\n", size, (double)(clock() - start) / CLOCKS_PER_SEC);

    // Генерация нового массива
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000;
    }

    // Быстрая сортировка
    start = clock();
    quick_sort(array, 0, size - 1);
    printf("быстрая сортировка для %d элементов: %.6f секунд\n", size, (double)(clock() - start) / CLOCKS_PER_SEC);

    // Генерация нового массива
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000;
    }

    // Сортировка слиянием
    start = clock();
    merge_sort(array, 0, size - 1);
    printf("сортирова слиянием для %d элементов: %.6f секунд\n", size, (double)(clock() - start) / CLOCKS_PER_SEC);

    // Генерация нового массива
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10000;
    }

    free(array);
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int sizes[] = { 1000, 10000 };
    for (int i = 0; i < 2; i++) {
        test_sorting_algorithms(sizes[i]);
    }

    return 0;
}