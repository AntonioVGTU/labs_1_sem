#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
// ������� Y(x)
double Y(double x) {
    if (x > 0) {
        return log(cbrt(x * x * x));
    }
    else {
        return 0.0; // ��� ����� ������� NaN, ���� x <= 0
    }
}

// ������� V(x)
double V(double x) {
    if (x > 1) {
        double tg_value = tan(x * x - 1);
        if (tg_value >= 0) {
            return sqrt(tg_value);
        }
        else {
            return NAN; // ���������� NaN, ���� ������� �������������
        }
    }
    else if (0 <= x && x <= 1) {
        return -2 * x;
    }
    else {
        return exp(cos(x));
    }
}

// ������� S(x)
double S(double x) {
    double term = (x - 1) / (x + 1);
    return term + pow(term, 3) / 3 + pow(term, 5) / 5 + pow(term, 7) / 7;
}

// ������� ������ ������� ��������
void print_table(double (*func)(double), double start, double end, double step) {
    printf(" x      |  f(x)\n");
    printf("------------------\n");
    for (double x = start; x <= end; x += step) {
        double result = func(x);
        if (isnan(result)) {
            printf("%7.2f  |  NaN\n", x);
        }
        else {
            printf("%7.2f  |  %7.4f\n", x, result);
        }
    }
}

// ������� ��� ���������� �������� ������� � �������� �����
void compute_value(double (*func)(double)) {
    double x;
    printf("������� �������� x: ");
    scanf("%lf", &x);
    double result = func(x);
    if (isnan(result)) {
        printf("�������� ������� � ����� %.2f: NaN\n", x);
    }
    else {
        printf("�������� ������� � ����� %.2f: %.4f\n", x, result);
    }
}

// ������� ��� �������� ������� �� �������� ���������
void describe_function(double (*func)(double), double start, double end, double step) {
    // ����� ����� �������� ������ ��� �������� ������� �� ���������
    // ��������, �������� �� �����������/��������, ����������������� � �.�.
    printf("�������� ������� �� ��������� [%.2f, %.2f] � ����� %.2f:\n", start, end, step);
    // ������ �������� �� �����������/��������
    double prev_value = func(start);
    int increasing = 1, decreasing = 1, sign_changing = 0;
    for (double x = start + step; x <= end; x += step) {
        double current_value = func(x);
        if (current_value > prev_value) {
            decreasing = 0;
        }
        else if (current_value < prev_value) {
            increasing = 0;
        }
        if ((current_value > 0 && prev_value < 0) || (current_value < 0 && prev_value > 0)) {
            sign_changing = 1;
        }
        prev_value = current_value;
    }
    if (increasing) {
        printf("������� ������������ �� ���������.\n");
    }
    else if (decreasing) {
        printf("������� ��������� �� ���������.\n");
    }
    else {
        printf("������� �� ���������� �� ���������.\n");
    }
    if (sign_changing) {
        printf("������� ��������������� �� ���������.\n");
    }
    else {
        printf("������� �� ��������������� �� ���������.\n");
    }
}

// ������� ��� ����������� ���� � ��������� ������ ������������
void menu() {
    int choice, func_choice;
    double start, end, step, x;
    double (*func)(double);

    while (1) {
        printf("\n����\n");
        printf("1. ��������� ��������\n");
        printf("2. ������������\n");
        printf("3. ������� ������� �� ���������\n");
        printf("4. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("�������� �������:\n");
        printf("1. S(x)\n");
        printf("2. V(x)\n");
        printf("3. Y(x)\n");
        printf("����: ");
        scanf("%d", &func_choice);

        switch (func_choice) {
        case 1:
            func = S;
            break;
        case 2:
            func = V;
            break;
        case 3:
            func = Y;
            break;
        default:
            printf("�������� ����� �������.\n");
            continue;
        }

        switch (choice) {
        case 1:
            compute_value(func);
            break;
        case 2:
            printf("������� ������ ���������: ");
            scanf("%lf", &start);
            printf("������� ����� ���������: ");
            scanf("%lf", &end);
            printf("������� ��� ���������: ");
            scanf("%lf", &step);
            print_table(func, start, end, step);
            break;
        case 3:
            printf("������� ������ ���������: ");
            scanf("%lf", &start);
            printf("������� ����� ���������: ");
            scanf("%lf", &end);
            printf("������� ���: ");
            scanf("%lf", &step);
            describe_function(func, start, end, step);
            break;
        default:
            printf("�������� ����� ��������.\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    menu();
    return 0;
}