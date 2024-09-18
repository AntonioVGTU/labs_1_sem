#include <stdio.h>
#include <locale.h>
int main()
{
	double prise;
	setlocale(LC_ALL, "ru");
	printf("введите цену за едининицу товара:");
	scanf_s("%lf", &prise);
	prise += 12.50;
	prise *= 1.25;
	printf("новая цена: %.2f\n", prise);
	return 0;
}