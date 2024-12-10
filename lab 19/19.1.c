#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
// Функция для вычисления значения функции
float func(float x) {
    return pow(x, 3) + 3 * pow(x, 2) - 3;
}

int main() {
    setlocale(LC_ALL, "ru");
    float x, start, end;
    int choice;
    FILE* file;

    // Ввод интервала и шага табуляции
    printf("Введите начало интервала: ");
    scanf("%f", &start);
    printf("Введите конец интервала: ");
    scanf("%f", &end);
    printf("Введите шаг x: ");
    scanf("%f", &x);

    // Выбор действия пользователем
    printf("Выберите действие:\n");
    printf("1. Запись в новый файл\n");
    printf("2. Дозапись в существующий файл\n");
    scanf("%d", &choice);

    // Открытие файла в соответствии с выбором пользователя
    if (choice == 1) {
        file = fopen("temp.txt", "w");
    }
    else if (choice == 2) {
        file = fopen("temp.txt", "a");
    }
    else {
        printf("Неверный выбор\n");
        return 1;
    }

    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    // Запись заголовка таблицы
    fprintf(file, " ________________________\n");
    fprintf(file, "| %-9c |%9c(x)|\n", 'x', 'f');
    fprintf(file, "|________________________|\n");

    // Табулирование функции и запись результатов в файл
    for (float i = start; i <= end; i += x) {
        float result = func(i);
        fprintf(file, "| %8.2f  |%12.2f|\n", i, result);
        fprintf(file, "|________________________|\n");
    }

    // Закрытие файла
    fclose(file);

    // Открытие файла в текстовом редакторе по умолчанию
#ifdef _WIN32
    system("start temp.txt");
#elif __linux__
    system("xdg-open temp.txt");
#elif __APPLE__
    system("open temp.txt");
#else
    printf("Неизвестная операционная система\n");
#endif

    return 0;
}