#include <stdio.h>
#include <locale.h>

void main()
{
	int a = 11, b = 3;
	int x;
	float y; 
	double z;
    x = a / b;
	y = a / b;
	z = a / b;
	printf("x = %d\ny = %f\nz = %lf", x, ((float) a / b), ((double) a / b));
}