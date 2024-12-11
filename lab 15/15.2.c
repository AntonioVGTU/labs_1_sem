#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define SIZE 7

void fillArray(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % 21 - 10; // Генерация чисел от -10 до 10
        }
    }
}

void printArray(int array[SIZE][SIZE], const char* title) {
    printf("%s:\n", title);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transposeArray(int source[SIZE][SIZE], int target[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            target[j][i] = source[i][j];
        }
    }
}

int countEqualPairs(int array[SIZE][SIZE]) {
    int count = 0;
    // Проверка соседних элементов в строках
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (array[i][j] == array[i][j + 1]) {
                count++;
            }
        }
    }
    // Проверка соседних элементов в столбцах
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE - 1; i++) {
            if (array[i][j] == array[i + 1][j]) {
                count++;
            }
        }
    }
    return count;
}

int sumNegativeElementsInRow(int array[SIZE][SIZE], int row) {
    int sum = 0;
    for (int j = 0; j < SIZE; j++) {
        if (array[row][j] < 0) {
            sum += array[row][j];
        }
    }
    return sum;
}

void findMaxElement(int array[SIZE][SIZE], int* row, int* col) {
    int maxValue = array[0][0];
    *row = 0;
    *col = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (array[i][j] > maxValue) {
                maxValue = array[i][j];
                *row = i;
                *col = j;
            }
        }
    }
    // Проверка на наличие нескольких максимальных элементов в столбце
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            if (array[i][j] == maxValue) {
                *row = i;
                *col = j;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(NULL));

    int originalArray[SIZE][SIZE];
    int transposedArray[SIZE][SIZE];

    fillArray(originalArray);
    printArray(originalArray, "Исходный массив");

    transposeArray(originalArray, transposedArray);
    printArray(transposedArray, "Транспонированный массив");

    int equalPairs = countEqualPairs(originalArray);
    printf("Число пар одинаковых соседних элементов: %d\n", equalPairs);

    int sumNegative = sumNegativeElementsInRow(originalArray, 4); // Пятая строка (индекс 4)
    printf("Сумма отрицательных элементов пятой строки: %d\n", sumNegative);

    int maxRow, maxCol;
    findMaxElement(originalArray, &maxRow, &maxCol);
    printf("Координаты максимального элемента: (%d, %d)\n", maxRow, maxCol);
}