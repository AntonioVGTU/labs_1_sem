#include <stdio.h>
#include <locale.h>
#define N 5

int main() {
    setlocale(LC_ALL, "ru");

    int a[N];
    float temp;
    int i;

    for (int i = 0; i < 5; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf_s("%f", &temp);
        a[i] = temp;
    }
    printf("выберите индекс\n");
    scanf_s("%d", &i);
    if (a[i + 1] > a[i - 1])
        printf("%d", a[i + 1]);
    else printf("%d", a[i - 1]);

}
    