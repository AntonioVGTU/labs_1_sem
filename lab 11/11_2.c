#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 10
int main() {
	setlocale(LC_ALL, "ru");
	float A[N];
	float z = 2;
	int cntm = 0, cntp = 0, chet = 0, f;
	float sminus = 0, splus = 0, sump = 0, smin = 0;
	for (int i = 0; i < N; i++) {
		f = (pow(z, 3) + 3 * pow(z, 2) - 3);
		A[i] = f;
		if (f > 0) {
			splus += f;
			cntp++;
		}
		else {
			sminus += f;
			cntm++;
		}
		chet++;
		z += 0.02;
	}
	for (int i = 0; i < N; i++) {
		printf("arr[%d] = %f\n", i, A[i]);
	}
	printf("Имя массива: arr[N]\n");
	printf("Сумма положительных: %f\n", splus);
	printf("Сумма отрицытельных: %f\n", sminus);
	printf("Количество отрицательных: %d\n", cntm);
	printf("Количество положительных: %d\n", cntp);
	printf("Среднее положительных: %f\n", splus / 100);
	printf("Среднее отрицытельных: %f\n", sminus / 100);
	

}
