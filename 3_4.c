#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	puts("введите трех значное число:\n");
	scanf_s("%i", &n);
	printf("первая цыфра числа: %4i\nвторая цыфра числа: %4i\nпоследняя цифра числа: %i\n", n / 100, (n / 10) % 10, n % 10);
	printf("сумма цифр равна: %i\n", (n / 100) + ((n / 10) % 10) + (n % 10));
	printf("число наоборот: %i%i%i", n % 10, (n / 10) % 10, n / 100);
	return 0;
}