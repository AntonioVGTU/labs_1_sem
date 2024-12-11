#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main(void) {
    setlocale(LC_ALL, "ru");
    char fname[20] = "number.txt"; // имя файла
    FILE* out; // файл чисел

    puts("Создание файла");

    // Открытие файла для записи
    if ((out = fopen(fname, "wt")) == NULL) {
        printf("Ошибка открытия файла для записи");
        return 0; // выход с ошибкой
    }
    srand(time(NULL));
    int random_number = rand() % 10;
    fprintf(out, "%d", random_number);
    fclose(out);
    system("start number.txt");

    return 1; // закрыть файл
}