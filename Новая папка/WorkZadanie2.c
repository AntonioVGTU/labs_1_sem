#include <stdio.h>
#include <locale.h>
#define D 2.54
#define P 2.32

int main(){
    setlocale(LC_ALL, "RUS");
    int dym;
    float result, result1;
    puts("Введи число");
    scanf ("%d", &dym);
    result = D *dym;
    result1 = P * dym;
    printf ("%d английских дюймов – это %.1f см\n", dym, result);
    printf ("%d испанских дюймов – это %.1f см", dym, result1);
}