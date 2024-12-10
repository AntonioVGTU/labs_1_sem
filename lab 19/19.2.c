#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
// ������� ��� ���������� �������� �������
float func(float x) {
    return pow(x, 3) + 3 * pow(x, 2) - 3;
}

int main() {
    setlocale(LC_ALL, "ru");
    float x, start, end;
    int choice;
    FILE* file;

    // ���� ��������� � ���� ���������
    printf("������� ������ ���������: ");
    scanf("%f", &start);
    printf("������� ����� ���������: ");
    scanf("%f", &end);
    printf("������� ��� x: ");
    scanf("%f", &x);

    // ����� �������� �������������
    printf("�������� ��������:\n");
    printf("1. ������ � ����� ����\n");
    printf("2. �������� � ������������ ����\n");
    scanf("%d", &choice);

    // �������� ����� � ������������ � ������� ������������
    if (choice == 1) {
        file = fopen("temp.txt", "w");
    }
    else if (choice == 2) {
        file = fopen("temp.txt", "a");
    }
    else {
        printf("�������� �����\n");
        return 1;
    }

    if (file == NULL) {
        perror("������ ��� �������� �����");
        return 1;
    }

    // ������ ��������� �������
    fprintf(file, " ________________________\n");
    fprintf(file, "| %-9c |%9c(x)|\n", 'x', 'f');
    fprintf(file, "|________________________|\n");

    // ������������� ������� � ������ ����������� � ����
    for (float i = start; i <= end; i += x) {
        float result = func(i);
        fprintf(file, "| %8.2f  |%12.2f|\n", i, result);
        fprintf(file, "|________________________|\n");
    }

    // �������� �����
    fclose(file);

    // �������� ����� � ��������� ��������� �� ���������
#ifdef _WIN32
    system("start temp.txt");
#elif __linux__
    system("xdg-open temp.txt");
#elif __APPLE__
    system("open temp.txt");
#else
    printf("����������� ������������ �������\n");
#endif

    return 0;
}