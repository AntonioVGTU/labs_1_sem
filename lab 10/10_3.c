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

	printf("�������� ��������� ��������:\n 1 - ���������� �������\n 2 - ������� ����������� ������\n 3 - ���������� ������\n");
	scanf_s("%d", &d);
	switch (d) {
	case 3:
		printf("������� ������: ");
		getchar();
		scanf_s("%c", &sim);
		printf("������� �: ");
		scanf_s("%d", &a);
		printf("������� �: ");
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
		printf("������� ��������� ��������: ");
		scanf_s("%f", &base);
		printf("������� ������ ��������: ");
		scanf_s("%f", &height);

		float area = area1(base, height);
		printf("������� ��������: %.2f\n", area);
		return 0;
	case 2:
		printf("������� (��� ��������������) � ��� ���������������, � �������� ��������������� ������� ����� � �����������.\n � �������� ����� ����� ���� ����� ���������������� ���������,\n � ��� ������� ����� ��������� ��� ������������ ��������� �� ������.\n");
		return 0;
	}
}