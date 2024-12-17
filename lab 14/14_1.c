#include<stdio.h>
#include<locale.h>
#include<math.h>

#define N 1024;

double* fille(double* ptr_array, int n);
int printe(double* ptr_array, int n);
double* calce(double* ptr_array, int n);


void main()
{
	setlocale(LC_ALL, "ru");

	double array[1024];
	int size;

	printf("¬ведите размер массива - ");
	scanf_s("%d", &size);

	fille(array, size);
	printe(array, size);
	calce(array, size);

}

double* fille(double* ptr_array, int n)
{
	double z = 1;
	for (int i = 0; i < n; i++)

	{
		ptr_array[i] = (pow(i, 3) + 3 * pow(i, 2) - 3);
		z += 0.02;
	}

}


int printe(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("array[%d] = %f\n", i, ptr_array[i]);
	}
}

double* calce(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] = -1 * (ptr_array[i]);
	}
	return ptr_array;
}