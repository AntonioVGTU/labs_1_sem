#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "ru");
	int num, n = -1, digit, index = 1, sumlast = 0, s = 0;
	printf("������� �����: ");
	scanf_s("%d", &num);
	while (num > 0) {
		digit = num % 10;
		num /= 10;
		if (digit % 2 == 0 && index != 1) sumlast += digit;
		index++;
		if (n == digit) s++;
		n = digit;
	}
	if (s != 0) s++;
	printf("����� ���� ������ ����� ��������� %d\n", sumlast);
	printf("���������� ����� ������������� ���������� ���� %d", s);
	
}