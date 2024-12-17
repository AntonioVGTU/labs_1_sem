#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void generate_random_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100000;
    }
}

int* shell_sort(int* ptr_array, int n) {
    int j, temp;
    for (int h = n / 2; h > 0; h /= 2) {
        for (int k = 0; k < h; k++) {
            for (int i = 0; i < n / h; i++) {
                j = i;
                while ((j > 0) && ptr_array[j * h + k] < ptr_array[(j - 1) * h + k]) {
                    temp = ptr_array[j * h + k];
                    ptr_array[j * h + k] = ptr_array[(j - 1) * h + k];
                    ptr_array[(j - 1) * h + k] = temp;
                    j = j - 1;
                }
            }
        }
    }
    return ptr_array;
}

void quicksort(int* array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void measure_sort_time(void (*sort_func)(int*, int), int* array, int size, const char* name) {
    int* temp_array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        temp_array[i] = array[i];
    }

    clock_t start = clock();
    sort_func(temp_array, size);
    clock_t end = clock();

    printf("%s: %.2f ms\n", name, (double)(end - start) * 1000 / CLOCKS_PER_SEC);
    free(temp_array);
}

void shell_sort_wrapper(int* array, int size) {
    shell_sort(array, size);
}

void quicksort_wrapper(int* array, int size) {
    quicksort(array, 0, size - 1);
}

void merge_sort_wrapper(int* array, int size) {
    merge_sort(array, 0, size - 1);
}

int main() {
    srand(time(NULL));
    system("color F0");
    setlocale(LC_ALL, "ru");

    int sizes[] = { 1000, 10000 };
    for (int i = 0; i < 2; i++) {
        int size = sizes[i];
        printf("\nРазмер массива: %d\n", size);

        int* array = malloc(size * sizeof(int));
        generate_random_array(array, size);

        measure_sort_time(shell_sort_wrapper, array, size, "Сортировка Шелла");
        measure_sort_time(quicksort_wrapper, array, size, "Быстрая сортировка Хоара");
        measure_sort_time(merge_sort_wrapper, array, size, "Сортировка слиянием");

        clock_t start = clock();
        qsort(array, size, sizeof(int), compare);
        clock_t end = clock();
        printf("Стандартная qsort: %.2f ms\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC);

        free(array);
    }

    return 0;
}
