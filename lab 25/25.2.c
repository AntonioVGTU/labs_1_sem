#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int rand10(int mmax) {
    return rand() % mmax + 1;
}

double rand_double(double dmin, double dmax) {
    return dmin + (dmax - dmin) * rand() / RAND_MAX;
}

int* rand10_array(int n, int mmax) {
    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = rand10(mmax);
    }
    return array;
}

double* rand_double_array(int n, double dm) {
    double* array = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        array[i] = rand_double(-dm, dm);
    }
    return array;
}

int main() {

    setlocale(LC_ALL, "ru");

    srand(time(NULL));

    int mmax;
    double dmin = -1.0, dmax = 1.0;
    int n;
    double dm;

    printf("¬ведите максимальное целое число дл€ генерации: ");
    scanf_s("%d", &mmax);
    printf("¬ведите количество целых элементов массива дл€ генерации: ");
    scanf_s("%d", &n);
    printf("¬ведите дробное число дл€ генерации: ");
    scanf_s("%lf", &dm);
    printf("¬ведите минимальное дробное число дл€ генерации: ");
    scanf_s("%lf", &dmin);
    printf("¬ведите максимальное дробное число дл€ генерации: ");
    scanf_s("%lf", &dmax);

    int rand_int = rand10(mmax);
    printf("—лучайное целое: %d\n", rand_int);

    double rand_dbl = rand_double(dmin, dmax);
    printf("—лучайное дробное: %f\n", rand_dbl);

    int* rand_int_array = rand10_array(n, mmax);
    printf("—лучайный массив целых: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", rand_int_array[i]);
    }
    printf("\n");
    free(rand_int_array);

    double* rand_dbl_array = rand_double_array(n, dm);
    printf("—лучайный массив дробных: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", rand_dbl_array[i]);
    }
    printf("\n");
    free(rand_dbl_array);

}