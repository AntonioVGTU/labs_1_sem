#include <stdio.h>
#include <locale.h>
//m = 2, c = 3

int main() {

	setlocale(LC_ALL, "ru");

	int m = 1 + rand() % 10;

	int k;
	printf("Введите цифру от 1 до 10: ");
	scanf_s("%d", &k);

	if (k == m)
		printf("Вы угадали число!\n");
	else
		printf("Вы не угадали число.\n");

	int c = rand() % 3 + 1;
	int z;
	int fl = 0;


	do {

		printf("Выберите: \nКамень = 1\nНожницы = 2\nБумага = 3\n");
		scanf_s("%d", &z);

		switch (z) {

		case 1:
		{
			printf("Компьютер выбрал бумагу, вы проиграли, попробуйте еще раз.\n"); \
				break;
		}

		case 2:
		{
			printf("Компьютер выбрал бумагу, вы победили\n");
			fl = 1;
			break;
		}


		case 3:
		{
			printf("Компьютер тоже выбрал бумагу, ничья, попробуйте еще раз.\n");
			break;
		}

		}

	} while (fl != 1);
}