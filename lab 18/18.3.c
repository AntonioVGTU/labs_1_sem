#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Генерация произвольной цифры от 0 до 9
    int random_number = rand() % 10;

    // Создание и открытие файла number.txt для записи
    FILE* file = fopen("number.txt", "w");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    // Запись цифры в файл
    fprintf(file, "%d", random_number);

    // Закрытие файла
    fclose(file);

    printf("Цифра %d записана в файл number.txt\n", random_number);

    return 0;
}