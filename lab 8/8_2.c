#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "RUS");
    float func, x;
    printf("введите шаг x\n");
    scanf_s("%f", &x);
    printf(" ________________________\n");
    char b = 'x', v = 'f';
    printf("| %-9c |%9c(x)|\n", b, v);
    printf("|________________________|\n");
    for (float i = 2; i <= 4.1; i += x) {
        func = pow(i, 3) + 3 * pow(i, 2) - 3;
        printf("| %8.2f  |%12.2f|\n", i, func);
        printf("|________________________|\n");
    }
    return 0;
}