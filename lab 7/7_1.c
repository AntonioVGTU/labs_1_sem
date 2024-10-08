#include <stdio.h>
#include <locale.h>

int main()
{
    char c;
    setlocale(LC_ALL, "ru");
    printf("Введите символ: ");
    
    scanf_s("%c", &c);
    if (c >= '0' && c <= '9')
    {
        printf("Это цифра\n");
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        printf("Это буква\n");
    }
    else
    {
        printf("Неизвестный символ\n");
    }

    return 0;
}