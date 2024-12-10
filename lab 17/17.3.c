#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int* full_array(int* arr, int size) {
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    return arr;
}
void put_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void sort_insert(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void sort_selection(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void sort_bubble(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sort_cocktail(int* arr, int n) {
    int swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = 0;
        end--;

        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
            }
        }
        start++;
    }
}
void run_experiment(int size) {
    int* arr = full_array(NULL, size);
    clock_t t;

    printf("Размер массива: %d\n", size);

    t = clock();
    sort_insert(arr, size);
    printf("Сортировка вставками: %.6f секунд\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    arr = full_array(arr, size); 

    t = clock();
    sort_selection(arr, size);
    printf("Сортировка выбором: %.6f секунд\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    arr = full_array(arr, size); 

    t = clock();
    sort_bubble(arr, size);
    printf("Сортировка пузырьком: %.6f секунд\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    arr = full_array(arr, size);

    t = clock();
    sort_cocktail(arr, size);
    printf("Шейкерная сортировка: %.6f секунд\n\n", (double)(clock() - t) / CLOCKS_PER_SEC);

    free(arr); 
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    run_experiment(100);
    run_experiment(1000);
    run_experiment(10000);

    return 0;
}