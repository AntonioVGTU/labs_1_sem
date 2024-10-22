#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	float x;
	printf("введите значение x:\n");
	scanf_s("%f", &x);
	printf("F(%f) = %f\n", x, (x <= 7) ? (-3 * x + 9) : (1 / (x - 7)));


}