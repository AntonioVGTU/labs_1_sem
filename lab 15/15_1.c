#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//1001 диагональ

void printArray(double** array, int rows, int cols) {
    printf("  ");
    for (int j = 0; j < cols; j++) {
        printf("%7d ", j);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("%d ", i);
        for (int j = 0; j < cols; j++) {
            printf("%7.2f ", array[i][j]);
        }
        printf("\n");
    }
}

double findMinInRow(double** array, int row, int cols) {
    double min = array[row][0];
    for (int j = 1; j < cols; j++) {
        if (array[row][j] < min) {
            min = array[row][j];
        }
    }
    return min;
}

double findMaxInColumn(double** array, int col, int rows) {
    double max = array[0][col];
    for (int i = 1; i < rows; i++) {
        if (array[i][col] > max) {
            max = array[i][col];
        }
    }
    return max;
}

int findValueOnDiagonal(double** array, int rows, int cols, double value) {
    int limit = rows < cols ? rows : cols;
    for (int i = 0; i < limit; i++) {
        if (array[i][i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {

    int rows, cols, choice;

    setlocale(LC_ALL, "ru");
    system("color F0");

    printf("\033[35mВведите количество строк: \033[0m");
    scanf_s("%d", &rows);
    system("color F0");
    printf("\033[31mВведите количество столбцов: \033[0m");
    scanf_s("%d", &cols);
    system("color F0");
    

    double** array = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        array[i] = (double*)malloc(cols * sizeof(double));
    }


    printf("Выберите принцип заполнения массива:\n");
    printf("1) Сумма индексов элемента.\n");
    printf("2) Буква (порядковый номер в алфавите равен номеру столбца).\n");
    printf("3) Значение, где целая часть - первый индекс, дробная - второй индекс.\n");
    printf("4) Отношение порядкового номера элемента в строке к номеру столбца.\n");
    printf("5) Случайное значение в интервале от номера строки до номера столбца + 1.\n");
    printf("\033[32m6) Целое значение: единицы - номер строки, тысячи - номер столбца.\033[0m\n");
    scanf_s("%d", &choice);
    system("color F0");

    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            switch (choice) {
            case 1:
                array[i][j] = i + j;
                break;
            case 2:
                array[i][j] = 'A' + j;
                break;
            case 3:
                array[i][j] = i + (double)j / 10;
                break;
            case 4:
                array[i][j] = j != 0 ? (double)(i * cols + j) / j : 0;
                break;
            case 5:
                if (j >= i) {
                    double min = i;
                    double max = j + 1;
                    array[i][j] = min + (double)rand() / RAND_MAX * (max - min);
                }
                else {
                    array[i][j] = 0;
                }
                break;
            case 6:
                array[i][j] = j * 1000 + i;
                break;
            default:
                printf("Некорректный выбор.\n");
                return 1;
            }
        }
    }

    printArray(array, rows, cols);

    int row, col;
    double value;

    printf("\nВведите номер строки для поиска минимального элемента: ");
    scanf_s("%d", &row);

    if (row >= 0 && row < rows) {
        printf("Минимальный элемент в строке %d: %.2f\n", row, findMinInRow(array, row, cols));
    }
    else {
        printf("Некорректный номер строки.\n");
    }

    printf("\nВведите номер столбца для поиска максимального элемента: ");
    scanf_s("%d", &col);

    if (col >= 0 && col < cols) {
        printf("Максимальный элемент в столбце %d: %.2f\n", col, findMaxInColumn(array, col, rows));
    }
    else {
        printf("Некорректный номер столбца.\n");
    }

    printf("\nВведите значение для поиска на главной диагонали: ");
    scanf_s("%lf", &value);

    int foundIndex = findValueOnDiagonal(array, rows, cols, value);
    if (foundIndex != -1) {
        printf("Значение %.2f найдено на главной диагонали в позиции [%d][%d].\n", value, foundIndex, foundIndex);
    }
    else {
        printf("Значение %.2f не найдено на главной диагонали.\n", value);
    }

    printf("Элементы в предпоследнем столбце: ");
    for (int i = 0; i < rows; i++) {
        printf("%f \n", array[i][cols - 2]);
    }
    printf("\n");

}
