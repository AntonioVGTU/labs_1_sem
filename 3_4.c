#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	puts("������� ���� ������� �����:\n");
	scanf_s("%i", &n);
	printf("������ ����� �����: %4i\n������ ����� �����: %4i\n��������� ����� �����: %i\n", n / 100, (n / 10) % 10, n % 10);
	printf("����� ���� �����: %i\n", (n / 100) + ((n / 10) % 10) + (n % 10));
	printf("����� ��������: %i%i%i", n % 10, (n / 10) % 10, n / 100);
	return 0;
}