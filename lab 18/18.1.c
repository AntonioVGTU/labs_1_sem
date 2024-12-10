#include<stdio.h>
#include<locale.h>
#include<math.h>


struct point
{
	float x;
	float y;
	char name;
};

typedef struct point Point;
void put(Point z)
{
	printf("point %c (%f,%f)\n", z.name, z.x, z.y);
}

float dist(Point z, Point w)
{
	float wx = w.x;
	float wy = w.y;
	float zx = z.x;
	float zy = z.y;
	float pwzx = pow(wx - zx, 2);
	float pwzy = pow(wy - zy, 2);
	float pwz = pwzx + pwzy;
	float distance = sqrt(pwz);
	printf("Расстояние между точками %c и %c = %f", w.name, z.name, distance);
}

float midpoint(Point z, Point w)
{
	float x1x2 = z.x + w.x;
	float two = 2;
	float pointx = x1x2 / two;
	float y1y2 = z.y + w.y;
	float pointy = y1y2 / two;
	printf("Координаты точки середины отрезка (%f;%f)\n", pointx, pointy);
}

float quarter(Point z)
{
	if (z.x > 0 && z.y > 0)
	{
		printf("Точка %c находится в 1-й координатной четверти", z.name);
	}
	if (z.x < 0 && z.y > 0)
	{
		printf("Точка %c находится в 2-й координатной четверти", z.name);
	}
	if (z.x < 0 && z.y < 0)
	{
		printf("Точка %c находится в 3-й координатной четверти", z.name);
	}
	if (z.x > 0 && z.y < 0)
	{
		printf("Точка %c находится в 4-й координатной четверти", z.name);
	}
}



void main()
{
	setlocale(LC_ALL, "ru");
	system("color 2");

	struct point a;
	struct point b;
	struct point z;
	struct point w;

	a = (Point){ 1,2,'A' };
	b.x = 5;
	b.y = -3;
	b.name = 'B';

	printf("point %c (%f,%f)\n", b.name, b.x, b.y);

	printf("Введите координату Х точки Z - ");
	scanf_s("%f", &z.x);
	printf("Введите координату Y точки Z - ");
	scanf_s("%f", &z.y);
	printf("Введите координату Х точки W - ");
	scanf_s("%f", &w.x);
	printf("Введите координату Y точки W - ");
	scanf_s("%f", &w.y);

	z.name = 'Z';
	put(z);
	w.name = 'W';
	put(w);
	dist(z, w);
	printf("\n");
	midpoint(z, w);

	quarter(z);

}