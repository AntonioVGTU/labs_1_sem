#include <stdio.h> 
#include <locale.h> 

int main() {
    setlocale(LC_ALL, "RUS");
    int day;

    printf("Введите порядковый номер дня недели (1-7):\n");
    scanf_s("%d", &day);

    switch (day) {
    case 1:
        printf("Понедельник, до Воскресенья осталось 6 дней.\n");
        break;
    case 2:
        printf("Вторник, до Воскресенья осталось 5 дней.\n");
        break;
    case 3:
        printf("Среда, до Воскресенья осталось 4 дня.\n");
        break;
    case 4:
        printf("Четверг, до Воскресенья осталось 3 дня.\n");
        break;
    case 5:
        printf("Пятница, до Воскресенья осталось 2 дня.\n");
        break;
    case 6:
        printf("Суббота, до Воскресенья остался 1 день.\n");
        break;
    case 7:
        printf("Воскресенье, до Воскресенья осталось 0 дней.\n");
        break;
    default:
        printf("Некорректный номер дня недели. Введите число от 1 до 7.\n");
        break;
    }

    return 0;
}
