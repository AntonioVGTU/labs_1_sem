#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "ru");
	int num, n = -1, digit, index = 1, sumlast = 0, s = 0, t = 0, fl = 0;
	printf("¬ведите число: ");
	scanf_s("%d", &num);
	while (num > 0) {
		digit = num % 10;
		num /= 10;
		if (digit % 2 == 0) {
			if (fl == 0) {
				t = digit;
				fl = 1;
			}
			sumlast += digit;
			index++;
		}
		if (n == digit) s++;
		n = digit;
	}
	if (s != 0) s++;
	sumlast -= t;
	printf("сумма всех четных кроме последнего %d\n", sumlast);
	printf("количество р€дом расположенных одинаковых цифр %d", s);

}