#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "ru");
	int x, y;
	puts("введите часы:");
	scanf_s("%d", &x);
	puts("введите минуты:");
	scanf_s("%d", &y);
	if (x < 18 && x >= 6)
		printf("врем€ ближе к полудню: %d часов %d минут", abs(12 - x), y);
	else if (x >= 18 || x < 6)
		printf("врем€ ближе к полуночи: %d часов %d минут", abs(23 - x), 60 - y);
}
