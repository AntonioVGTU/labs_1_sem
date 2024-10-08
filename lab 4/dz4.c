#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru");
    int x1, y1, z1;
    int x2, y2, z2;

    printf("¬ведите количество €блок, груш и апельсинов, проданных в понедельник: \n");
    printf("яблоки (по 1 руб.): ");
    scanf_s("%d", &x1);
    printf("√руши (по 2 руб.): ");
    scanf_s("%d", &y1);
    printf("јпельсины (по 3 руб.): ");
    scanf_s("%d", &z1);

    printf("\n¬ведите количество €блок, груш и апельсинов, проданных во вторник: \n");
    printf("яблоки (по 1 руб.): ");
    scanf_s("%d", &x2);
    printf("√руши (по 2 руб.): ");
    scanf_s("%d", &y2);
    printf("јпельсины (по 3 руб.): ");
    scanf_s("%d", &z2);

    int totalDay1 = x1 * 1 + y1 * 2 + z1 * 3;
    int totalDay2 = x2 * 1 + y2 * 2 + z2 * 3;

    printf("\n—умма продаж в понедельник: %d руб.\n", totalDay1);
    printf("—умма продаж во вторник: %d руб.\n", totalDay2);

    return 0;
}