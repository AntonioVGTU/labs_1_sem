#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int x, y;
    puts("������� ����:");
    scanf_s("%d", &x);
    puts("������� ������:");
    scanf_s("%d", &y);
    if (x < 0 || x > 24 || y < 0 || y >= 60)
        printf("����������� �����.");
    else if ((x <= 24 && x >= 18 ) && x > 6)
        printf("����� � �������� %d � %d �����", abs(23 - x), abs(60 - y));
    else if (x > 6 && x < 18) 
        printf("����� � ������� %d � %d �����", abs(12 - x), y);
    else if ((x < 6 )&& (x > 0) && (y = 0)) 
        printf("����� � �������� %d � %d �����", x, y);
    else if ((x >= 6) && (y > 0))
        printf("����� � ������� %d � %d �����", abs(11 - x), 60 - y);
}