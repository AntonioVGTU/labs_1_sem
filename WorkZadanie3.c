#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "RUS");
	float a, b, a1, b1;

	puts("Введите число А:\n");
	scanf_s("%f", &a);
	puts("Введите число :\n");
	scanf_s("%f", &b);
	printf("|  a * b  |  a + b  |  a - b  |\n");
	printf("|%.1f * %.1f|%.1f + %.1f|%.1f - %.1f|\n", a, b, a, b, a, b);
	printf("|   %.1f   |   %.1f   |   %.1f   |\n", a*b, a+b, a-b);
}