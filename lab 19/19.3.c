#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Структура для хранения данных о футболисте
typedef struct {
    char surname[20];
    char birth_date[11]; // Формат: ДД.ММ.ГГГГ
    char club[20];
    char position[20];
    int games_played;
    char birth_place[20];
} Footballer;

// Функция для записи данных в файл
int writefile(char* fname, Footballer* footballers, int size) {
    FILE* out;
    if ((out = fopen(fname, "wt")) == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 0; // выход с ошибкой
    }

    for (int i = 0; i < size; i++) {
        fprintf(out, "Фамилия: %20s ; Дата рождения: %10s ; Клуб: %20s ; Амплуа: %20s ; Количество игр: %d ; Место рождения: %20s\n",
            footballers[i].surname, footballers[i].birth_date, footballers[i].club,
            footballers[i].position, footballers[i].games_played, footballers[i].birth_place);
    }

    fclose(out);
    return 1; // успешный выход
}

int main(void) {
    setlocale(LC_ALL, "Rus");

    char fname[20] = "footballers.txt";

    Footballer footballers[3];

    // Ввод данных о первом футболисте
    puts("Введите данные о первом футболисте:");
    printf("Фамилия: ");
    scanf("%19s", footballers[0].surname);
    printf("Дата рождения (ДД.ММ.ГГГГ): ");
    scanf("%10s", footballers[0].birth_date);
    printf("Клуб: ");
    scanf("%19s", footballers[0].club);
    printf("Амплуа: ");
    scanf("%19s", footballers[0].position);
    printf("Количество игр: ");
    scanf("%d", &footballers[0].games_played);
    getchar(); // Считываем символ новой строки
    printf("Место рождения: ");
    scanf("%19s", footballers[0].birth_place);

    // Ввод данных о втором футболисте
    puts("Введите данные о втором футболисте:");
    printf("Фамилия: ");
    scanf("%19s", footballers[1].surname);
    printf("Дата рождения (ДД.ММ.ГГГГ): ");
    scanf("%10s", footballers[1].birth_date);
    printf("Клуб: ");
    scanf("%19s", footballers[1].club);
    printf("Амплуа: ");
    scanf("%19s", footballers[1].position);
    printf("Количество игр: ");
    scanf("%d", &footballers[1].games_played);
    getchar(); // Считываем символ новой строки
    printf("Место рождения: ");
    scanf("%19s", footballers[1].birth_place);

    // Ввод данных о третьем футболисте
    puts("Введите данные о третьем футболисте:");
    printf("Фамилия: ");
    scanf("%19s", footballers[2].surname);
    printf("Дата рождения (ДД.ММ.ГГГГ): ");
    scanf("%10s", footballers[2].birth_date);
    printf("Клуб: ");
    scanf("%19s", footballers[2].club);
    printf("Амплуа: ");
    scanf("%19s", footballers[2].position);
    printf("Количество игр: ");
    scanf("%d", &footballers[2].games_played);
    getchar(); // Считываем символ новой строки
    printf("Место рождения: ");
    scanf("%19s", footballers[2].birth_place);

    // Запись данных в файл
    if (!writefile(fname, footballers, 3)) {
        printf("Ошибка записи данных в файл\n");
        return 1;
    }
    system("start footballers.txt");
}