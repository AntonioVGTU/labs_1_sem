#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // ������������� ������� �����������
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int rows, cols;
    float targetValue;

    // ���� ����������� �������
    printf("������� ���������� �����: ");
    scanf("%d", &rows);
    printf("������� ���������� ��������: ");
    scanf("%d", &cols);

    // �������� ���������� �������
    float** array = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        array[i] = (float*)malloc(cols * sizeof(float));
    }

    // ���������� ������� �� ��������� ��������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i + (float)j / 10;
        }
    }

    // ����� ������� � ���� �������
    printf("\n������:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.1f ", array[i][j]);
        }
        printf("\n");
    }

    // ����� �������� � ������ ������ ����
    printf("\n������� � ������ ������ ����: %.1f\n", array[rows - 1][cols - 1]);

    // ���� �������� ��� ������ �� ���������
    printf("\n������� �������� ��� ������ �� ���������: ");
    scanf("%f", &targetValue);

    // ����� �������� �� ���������
    int found = 0;
    for (int i = 0; i < rows && i < cols; i++) {
        if (array[i][i] == targetValue) {
            printf("�������� %.1f ������� �� ��������� � ������� (%d, %d)\n", targetValue, i, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("�������� %.1f �� ������� �� ���������\n", targetValue);
    }

    // ������������ ������
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}