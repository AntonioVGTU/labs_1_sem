#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru");
    int x1, y1, z1;
    int x2, y2, z2;

    printf("������� ���������� �����, ���� � ����������, ��������� � �����������: \n");
    printf("������ (�� 1 ���.): ");
    scanf_s("%d", &x1);
    printf("����� (�� 2 ���.): ");
    scanf_s("%d", &y1);
    printf("��������� (�� 3 ���.): ");
    scanf_s("%d", &z1);

    printf("\n������� ���������� �����, ���� � ����������, ��������� �� �������: \n");
    printf("������ (�� 1 ���.): ");
    scanf_s("%d", &x2);
    printf("����� (�� 2 ���.): ");
    scanf_s("%d", &y2);
    printf("��������� (�� 3 ���.): ");
    scanf_s("%d", &z2);

    int totalDay1 = x1 * 1 + y1 * 2 + z1 * 3;
    int totalDay2 = x2 * 1 + y2 * 2 + z2 * 3;

    printf("\n����� ������ � �����������: %d ���.\n", totalDay1);
    printf("����� ������ �� �������: %d ���.\n", totalDay2);

    return 0;
}