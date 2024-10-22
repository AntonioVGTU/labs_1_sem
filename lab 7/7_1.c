#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");

	char c, x;

	printf("Введите букву (a/b/c/d/e) или символ (!@#$%):\n ");

	scanf_s("%c", &c);

	switch (c)
	{
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
		printf("Введена буква");
		break;
	case '!':
	case '@':
	case '#':
	case '$':
	case '%':
		printf("Введен символ");
		break;

	}


	return 0;

}
