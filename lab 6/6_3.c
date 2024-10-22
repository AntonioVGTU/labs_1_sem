#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int x, y;
    puts("введите часы:");
    scanf_s("%d", &x);
    puts("введите минуты:");
    scanf_s("%d", &y);
    if (x < 0 || x > 24 || y < 0 || y >= 60)
        printf("некоректное время.");
    else if ((x <= 24 && x >= 18 ) && x > 6)
        printf("ближе к полуночи %d и %d минут", abs(23 - x), abs(60 - y));
    else if (x > 6 && x < 18) 
        printf("ближе к полудню %d и %d минут", abs(12 - x), y);
    else if ((x < 6 )&& (x > 0) && (y = 0)) 
        printf("ближе к полуночи %d и %d минут", x, y);
    else if ((x >= 6) && (y > 0))
        printf("ближе к полудню %d и %d минут", abs(11 - x), 60 - y);
}