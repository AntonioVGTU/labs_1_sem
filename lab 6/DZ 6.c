#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "ru");
	float x, y;
	puts("������� x:");
	scanf_s("%f", & x);
	puts("������� y:");
	scanf_s("%f", & y);
	if (x == 2 && y >= -4 && y <= 5)
		printf("����� ������ ������");
	else if(x == 2.5 && y <= 4.25 && y >= -3)
		printf("����� ������ ������");
	else if(x == 3 && y <= 2.5 && y >= -2.2)
		printf("����� ������ ������");
	else if(x == 3.5 && y <= 3 && y >= 2.25)
		printf("����� ������ ������");
	else if(x == 4 && y <= 2.5 && y >= 0.75)
		printf("����� ������ ������");
	else if(x == 4.5 && y <= 1.75 && y >= 0)
		printf("����� ������ ������");
	else if(x == 4.5 && y == 1)
		printf("����� ������ ������");
	else
		printf("����� ��� ������");

}