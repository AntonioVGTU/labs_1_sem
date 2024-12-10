#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h> 
#include <math.h> 
#define N 20
double* fille(double* ptr_array, int n) {
    double z = 1;
    for (int i = 0; i < n; i++) {
        ptr_array[i] = z;
        z += 0.2;
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
int printe(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %f\n", i, ptr_array[i]);
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "ru");

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
    printe(ptr_array, size);

    free(ptr_array);
    return 0;
}