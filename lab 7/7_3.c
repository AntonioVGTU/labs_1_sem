#include <stdio.h> 
#include <locale.h> 

int main() {
    setlocale(LC_ALL, "RUS");
    int day;

    printf("������� ���������� ����� ��� ������ (1-7):\n");
    scanf_s("%d", &day);

    switch (day) {
    case 1:
        printf("�����������, �� ����������� �������� 6 ����.\n");
        break;
    case 2:
        printf("�������, �� ����������� �������� 5 ����.\n");
        break;
    case 3:
        printf("�����, �� ����������� �������� 4 ���.\n");
        break;
    case 4:
        printf("�������, �� ����������� �������� 3 ���.\n");
        break;
    case 5:
        printf("�������, �� ����������� �������� 2 ���.\n");
        break;
    case 6:
        printf("�������, �� ����������� ������� 1 ����.\n");
        break;
    case 7:
        printf("�����������, �� ����������� �������� 0 ����.\n");
        break;
    default:
        printf("������������ ����� ��� ������. ������� ����� �� 1 �� 7.\n");
        break;
    }

    return 0;
}
