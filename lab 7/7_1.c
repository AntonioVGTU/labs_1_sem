#include <stdio.h>
#include <locale.h>

int main()
{
    char c;
    setlocale(LC_ALL, "ru");
    printf("������� ������: ");
    
    scanf_s("%c", &c);
    if (c >= '0' && c <= '9')
    {
        printf("��� �����\n");
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        printf("��� �����\n");
    }
    else
    {
        printf("����������� ������\n");
    }

    return 0;
}