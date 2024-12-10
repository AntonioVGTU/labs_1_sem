#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 20 
double* fille(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2 - 1;
    }
    return ptr_array;
}
double* calce(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        if ((int)ptr_array[i] % 2 == 0) {
            printf("array[%d] заменено: %f -> 1\n", i, ptr_array[i]);
            ptr_array[i] = 1;
        }
    }
    return ptr_array;
}
double* remove_two_max(double* ptr_array, int* n) {
    int max_index1 = -1, max_index2 = -1;
    for (int i = 0; i < *n; i++) {
        if (max_index1 == -1 || ptr_array[i] > ptr_array[max_index1]) {
            max_index2 = max_index1;
            max_index1 = i;
        }
        else if (max_index2 == -1 || ptr_array[i] > ptr_array[max_index2]) {
            max_index2 = i;
        }
    }
    for (int i = max_index1; i < *n - 1; i++) {
        ptr_array[i] = ptr_array[i + 1];
    }
    (*n)--;
    if (max_index2 > max_index1) {
        max_index2--;
    }
    for (int i = max_index2; i < *n - 1; i++) {
        ptr_array[i] = ptr_array[i + 1];
    }
    (*n)--;
    return ptr_array;
}
int printe(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %f\n", i, ptr_array[i]);
    }
    return 0;
}
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    double* ptr_array;
    int size;
    printf("Введите размер массива: ");
    scanf_s("%d", &size);

    if (size > N) {
        printf("Слишком большой размер. Максимум N = %d.\n", N);
        return -1;
    }
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("Ошибка при выделении памяти.");
        return -1;
    }
    fille(ptr_array, size);
    calce(ptr_array, size);
    printf("Массив до удаления двух максимальных элементов:\n");
    printe(ptr_array, size);
    ptr_array = remove_two_max(ptr_array, &size);
    printf("Массив после удаления двух максимальных элементов:\n");
    printe(ptr_array, size);

    free(ptr_array);
    return 0;
}
