#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "ru");
	int x, y;
	puts("������� ����:");
	scanf_s("%d", &x);
	puts("������� ������:");
	scanf_s("%d", &y);
	if (x < 18 && x >= 6)
		printf("����� ����� � �������: %d ����� %d �����", abs(12 - x), y);
	else if (x >= 18 || x < 6)
		printf("����� ����� � ��������: %d ����� %d �����", abs(23 - x), 60 - y);
}
