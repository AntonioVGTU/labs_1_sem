#include <stdio.h>
#include <locale.h>
int main()
{
	double prise;
	setlocale(LC_ALL, "ru");
	printf("������� ���� �� ��������� ������:");
	scanf_s("%lf", &prise);
	prise += 12.50;
	prise *= 1.25;
	printf("����� ����: %.2f\n", prise);
	return 0;
}