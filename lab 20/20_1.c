#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "ru");

	int sum = 0, a, n = 0;
	FILE* file;

	file = fopen("temp.txt", "r");

	while (!feof(file)) {
		fscanf(file, "%d", &a);
		sum += a;
		n++;
	}

	fclose(file);

	printf("Среднее арифмитическое: %d", sum / n);
}
