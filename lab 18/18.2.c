#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void center(const char* message) {
    int length = strlen(message);
    int padding = (80 - length) / 2;
    for (int i = 0; i < padding; i++) {
        printf("*");
    }
    printf("%*s", length, message);
    for (int i = 0; i < padding; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "RUS");

    struct tm* mytime;
    time_t t;
    t = time(NULL);
    mytime = localtime(&t);

    for (int i = 0; i < 80; i++) {
        printf("*");
    }
    printf("\n");

    char array[200];
    sprintf(array, "Время в Москве %02d:%02d:%02d", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    center(array);

    switch (mytime->tm_wday) {
    case 0: sprintf(array, "Сегодня воскресенье"); break;
    case 1: sprintf(array, "Сегодня понедельник"); break;
    case 2: sprintf(array, "Сегодня вторник"); break;
    case 3: sprintf(array, "Сегодня среда"); break;
    case 4: sprintf(array, "Сегодня четверг"); break;
    case 5: sprintf(array, "Сегодня пятница"); break;
    case 6: sprintf(array, "Сегодня суббота"); break;
    }
    center(array);

    sprintf(array, "%02d.%02d.%04d", mytime->tm_mday, mytime->tm_mon + 1, mytime->tm_year + 1900);
    center(array);

    switch (mytime->tm_mon) {
    case 0: sprintf(array, "%d Января", mytime->tm_mday); break;
    case 1: sprintf(array, "%d Февраля", mytime->tm_mday); break;
    case 2: sprintf(array, "%d Марта", mytime->tm_mday); break;
    case 3: sprintf(array, "%d Апреля", mytime->tm_mday); break;
    case 4: sprintf(array, "%d Мая", mytime->tm_mday); break;
    case 5: sprintf(array, "%d Июня", mytime->tm_mday); break;
    case 6: sprintf(array, "%d Июля", mytime->tm_mday); break;
    case 7: sprintf(array, "%d Августа", mytime->tm_mday); break;
    case 8: sprintf(array, "%d Сентября", mytime->tm_mday); break;
    case 9: sprintf(array, "%d Октября", mytime->tm_mday); break;
    case 10: sprintf(array, "%d Ноября", mytime->tm_mday); break;
    case 11: sprintf(array, "%d Декабря", mytime->tm_mday); break;
    }
    center(array);

    sprintf(array, "Сегодня %d день %d года", mytime->tm_yday + 1, mytime->tm_year + 1900);
    center(array);

    sprintf(array, "До воскресенья осталось %d дней и %d часов", (7 - mytime->tm_wday), (23 - mytime->tm_hour));
    center(array);

    sprintf(array, "С первой пары прошло %d часов и %d минут", mytime->tm_hour - 9, mytime->tm_min - 30);
    center(array);

    sprintf(array, "До Нового года осталось %d месяцев и %d дней", (12 - mytime->tm_mon - 1), (31 - mytime->tm_mday));
    center(array);

    sprintf(array, "До конца пары осталось %d минут и %d секунд", (90 - mytime->tm_min), (59 - mytime->tm_sec));
    center(array);

    sprintf(array, "До конца месяца %d дней, до конца года %d месяцев", (31 - mytime->tm_mday), (12 - mytime->tm_mon));
    center(array);

    switch (mytime->tm_mon) {
    case 0: sprintf(array, "Месяц 1, год - %d", mytime->tm_year + 1900); break;
    case 1: sprintf(array, "Месяц 2, год - %d", mytime->tm_year + 1900); break;
    case 2: sprintf(array, "Месяц 3, год - %d", mytime->tm_year + 1900); break;
    case 3: sprintf(array, "Месяц 4, год - %d", mytime->tm_year + 1900); break;
    case 4: sprintf(array, "Месяц 5, год - %d", mytime->tm_year + 1900); break;
    case 5: sprintf(array, "Месяц 6, год - %d", mytime->tm_year + 1900); break;
    case 6: sprintf(array, "Месяц 7, год - %d", mytime->tm_year + 1900); break;
    case 7: sprintf(array, "Месяц 8, год - %d", mytime->tm_year + 1900); break;
    case 8: sprintf(array, "Месяц 9, год - %d", mytime->tm_year + 1900); break;
    case 9: sprintf(array, "Месяц 10, год - %d", mytime->tm_year + 1900); break;
    case 10: sprintf(array, "Месяц 11, год - %d", mytime->tm_year + 1900); break;
    case 11: sprintf(array, "Месяц 12, год - %d", mytime->tm_year + 1900); break;
    }
    center(array);

    return 0;
}