#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int x, y;
    puts("введите часы:");
    scanf("%d", &x);
    puts("введите минуты:");
    scanf("%d", &y);
    if (x < 0 || x > 24 || y < 0 || y >= 60) {
        printf("некоректное время.");
        return 1;
    }


}