#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // Устанавливаем русскую локализацию
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int rows, cols;
    float targetValue;

    // Ввод размерности массива
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    // Создание двумерного массива
    float** array = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        array[i] = (float*)malloc(cols * sizeof(float));
    }

    // Заполнение массива по заданному принципу
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i + (float)j / 10;
        }
    }

    // Вывод массива в виде таблицы
    printf("\nМассив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.1f ", array[i][j]);
        }
        printf("\n");
    }

    // Вывод элемента в правом нижнем углу
    printf("\nЭлемент в правом нижнем углу: %.1f\n", array[rows - 1][cols - 1]);

    // Ввод значения для поиска на диагонали
    printf("\nВведите значение для поиска на диагонали: ");
    scanf("%f", &targetValue);

    // Поиск значения на диагонали
    int found = 0;
    for (int i = 0; i < rows && i < cols; i++) {
        if (array[i][i] == targetValue) {
            printf("Значение %.1f найдено на диагонали в позиции (%d, %d)\n", targetValue, i, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Значение %.1f не найдено на диагонали\n", targetValue);
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}