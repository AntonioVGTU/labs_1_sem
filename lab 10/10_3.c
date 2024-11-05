#include <stdio.h>
#include <locale.h>
float area1(float base, float height) {
	return base * height;
}

int main() {
	setlocale(LC_ALL, "ru"); // * 6 10 60 20
	int a, b, f1, f2, k, r = 1, n, d;
	char sim;
	float base, height;

	printf("выберите требуемое действие:\n 1 - рассчитать площадь\n 2 - вывести определение фигуры\n 3 - нарисовать фигуру\n");
	scanf_s("%d", &d);
	switch (d) {
	case 3:
		printf("введите символ: ");
		getchar();
		scanf_s("%c", &sim);
		printf("сторона А: ");
		scanf_s("%d", &a);
		printf("сторона В: ");
		scanf_s("%d", &b);
		printf("F1: ");
		scanf_s("%d", &f1);
		printf("F2: ");
		scanf_s("%d", &f2);
		k = a + 1;
		int j;
		if ((f1 >= 45) && (f1 < 90)) {
			for (int i = 1; i < (a + 1); i++) {
				for (int z = k; z > 0; z--)
					printf(" ");
				for (int y = 0; y < r; y++)
					printf("%c", sim);
				printf("\n");
				k -= 1;
				r += 2;
			}
			n = (k + 2);
			for (int i = 1; i < (b); i++) {
				for (int i = 0; i < n; i++)
					printf(" ");
				for (int i = (r - 4); i > 0; i--) {
					printf("%c", sim);
				}
				printf("\n");
				for (int i = 0; i < n; i++)
					printf(" ");
				for (int i = (r - 4); i > 0; i--) {
					printf("%c", sim);
				}
				printf("\n");
				r -= 2;
				n += 1;
			}
		}
		if ((f1 >= 90) && (f1 <= 180)) { // * 6 10 90 
			k += 3;
			for (int i = 1; i < (a + 1); i++) {
				for (int z = k; z > 0; z--)
					printf(" ");
				for (int y = 0; y < r; y++)
					printf("%c", sim);
				printf("\n");
				k -= 2;
				r += 4;
			}
			n = (k + 4);
			r -= 4;
			for (int i = 1; i < (b); i++) {
				for (int i = 0; i < n; i++)
					printf(" ");
				for (int i = (r - 4); i > 0; i--) {
					printf("%c", sim);
				}
				printf("\n");
				for (int i = 0; i < n; i++)
					printf(" ");
				for (int i = (r - 4); i > 0; i--) {
					printf("%c", sim);
				}
				printf("\n");
				r -= 4;
				n += 2;

			}
		}
		return 0;
	case 1:
		printf("Введите основание ромбоида: ");
		scanf_s("%f", &base);
		printf("Введите высоту ромбоида: ");
		scanf_s("%f", &height);

		float area = area1(base, height);
		printf("Площадь ромбоида: %.2f\n", area);
		return 0;
	case 2:
		printf("Ромбоид (или параллелограмм) — это четырехугольник, у которого противоположные стороны равны и параллельны.\n У ромбоида также равны углы между противоположными сторонами,\n а его площади можно вычислить как произведение основания на высоту.\n");
		return 0;
	}
}