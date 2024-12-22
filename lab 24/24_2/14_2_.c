#include<stdio.h>
#include<locale.h>
#include<math.h>

#define N 100;

double* fill_elem(double* ptr_array, int n);
int put_elem(double* ptr_array, int n);
double* calc_elem(double* ptr_array, int n);
double sum_elem(double* ptr_array, int begin, int end);
int find_elem(double* ptr_array, int n, double elem);



void main()
{

	int ff1, ff2;

	setlocale(LC_ALL, "RUS");

	double array[1024];
	int size;

	printf("¬ведите размер массива - ");
	scanf_s("%d", &size);
	printf("¬ведите индекс начала: ");
	scanf_s("%d", &ff1);
	printf("¬ведите индекс конца суммы: ");
	scanf_s("%d", &ff2);

	fill_elem(array, size);
	calc_elem(array, size);
	put_elem(array, size);
	sum_elem(array, ff1, ff2);

	double elem;
	printf("¬ведите элемент, индекс которого нужно найти - ");
	scanf_s("%lf", &elem);
	int index = find_elem(array, size, elem);

	if (index != -1)
	{
		printf("%d", index);
	}
	else
	{
		printf("-1");
	}
}

double* fill_elem(double* ptr_array, int n)
{
	double z = 1;
	for (int i = 0; i < n; i++)

	{
		ptr_array[i] = z;
		//ptr_array[i] = (pow(z, 3) - 4 * pow(z, 2) + 2);
		z += 0.02;
	}

}

int put_elem(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("array[%d] = %f\n", i, ptr_array[i]);
	}
}

double* calc_elem(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] = -1 * (ptr_array[i]);
	}
	return ptr_array;
}

double sum_elem(double* ptr_array, int begin, int end)
{
	double s = 0;
	for (int i = begin; i <= end; i++)
	{
		s += ptr_array[i];
	}
	printf("—умма элементов массива от индекса %d до индекса %d равна %f\n", begin, end, s);
}

int find_elem(double* ptr_array, int n, double elem) {
	for (int i = 0; i < n; i++) {
		if (ptr_array[i] == elem) {
			return i;
		}
	}
	return -1;
}