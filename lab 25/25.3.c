
#include <stdio.h>  
#include <locale.h>  
#include <stdlib.h>  
#define n 10  

int* reverseKElements(int* start, int* end, int k, int* newSize) {
    if (start > end || k <= 0) {
        printf("Некорректные параметры\n");
        return NULL;
    }

    int size = end - start + 1;
    int* result = (int*)malloc(size * sizeof(int));
    if (!result) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }

    for (int i = 0; i < size; i += k) {
        int left = i;
        int right = (i + k - 1 < size) ? (i + k - 1) : size - 1;

        // Реверсируем куск массива
        while (left < right) {
            int temp = start[left];
            start[left] = start[right];
            start[right] = temp;
            left++;
            right--;
        }
    }

    // Копируем реверсированный массив в результат
    for (int i = 0; i < size; i++) {
        result[i] = start[i];
    }

    *newSize = size;
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    int array[n];

    printf("Введите элементы массива через пробел: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &array[i]);
    }

    int k;
    printf("Введите значение K: ");
    scanf_s("%d", &k);

    int newSize;
    int* result = reverseKElements(array, array + n - 1, k, &newSize);

    if (result) {
        printf("Массив после реверса: ");
        for (int i = 0; i < newSize; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    return 0;
}