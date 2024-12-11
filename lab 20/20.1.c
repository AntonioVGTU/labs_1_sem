#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Функция для преобразования чисел
void transform_numbers(FILE* in, FILE* out) {
    double num;
    int count = 0;

    while (fscanf(in, "%lf", &num) == 1) {
        count++;
        if (count % 4 == 0) {
            num /= 2.0;
        }
        fprintf(out, "%.2f\n", num);
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    char input_filename[] = "temp.txt";
    char output_filename[] = "temp_parity4.txt";
    FILE* in, * out;
    if ((in = fopen(input_filename, "r")) == NULL) {
        perror("Ошибка открытия файла для чтения");
        return 1;
    }
    if ((out = fopen(output_filename, "w")) == NULL) {
        perror("Ошибка открытия файла для записи");
        fclose(in);
        return 1;
    }
    transform_numbers(in, out);

    // Закрытие файлов
    fclose(in);
    fclose(out);

    printf("Преобразование завершено. Результат записан в файл: %s\n", output_filename);
}