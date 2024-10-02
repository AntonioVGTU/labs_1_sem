#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "ru");
	float x, y;
	puts("введите x:");
	scanf_s("%f" &x);
	puts("введите y:");
	scanf_s("%f" &y);
	if ((x = 2 && y >= -4 && y <= 5) or (x = 2, 5 && y <= 4, 25 && y >= -3) or (x = 3 && y <= 2, 5 && y >= -2, 2) or (x = 3, 5 && y <= 3 && y >= 2, 25) or (x = 4 && y <= 2, 5 && y >= 0, 75) or (x = 4, 5 && y <= 1, 75 && y >= 0) or (x = 4, 5 && y = 1))
		printf("точка внутри фигуры");
	else 
		printf("точка вне фигуры")

}
