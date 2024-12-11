#include <stdio.h>
#include <locale.h>
#define ROWS 2
#define COLS 22

int main() {
    setlocale(LC_ALL, "ru");
    int scores[ROWS][COLS];
    int total_points = 0;

    // Ввод данных пользователем
    printf("Введите количество забитых и пропущенных мячей для каждой игры (22 игры):\n");
    for (int i = 0; i < COLS; i++) {
        printf("Игра %d:\n", i + 1);
        printf("Забитые мячи: ");
        scanf("%d", &scores[0][i]);
        printf("Пропущенные мячи: ");
        scanf("%d", &scores[1][i]);
    }

    // Подсчет очков
    for (int i = 0; i < COLS; i++) {
        int goals_scored = scores[0][i];
        int goals_conceded = scores[1][i];

        if (goals_scored > goals_conceded) {
            total_points += 3; // Выигрыш
        }
        else if (goals_scored == goals_conceded) {
            total_points += 1; // Ничья
        }
        else {
            total_points += 0; // Проигрыш
        }
    }

    // Вывод результата
    printf("Общее количество очков: %d\n", total_points);

    return 0;
}