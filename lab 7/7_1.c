#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");

	char c, x;

	printf("������� ����� (a/b/c/d/e) ��� ������ (!@#$%):\n ");

	scanf_s("%c", &c);

	switch (c)
	{
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
		printf("������� �����");
		break;
	case '!':
	case '@':
	case '#':
	case '$':
	case '%':
		printf("������ ������");
		break;

	}


	return 0;

}
