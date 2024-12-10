#include <stdio.h>
#include <locale.h>
#define ROWS 2
#define COLS 22

int main() {
    setlocale(LC_ALL, "ru");
    int scores[ROWS][COLS];
    int total_points = 0;

    // ���� ������ �������������
    printf("������� ���������� ������� � ����������� ����� ��� ������ ���� (22 ����):\n");
    for (int i = 0; i < COLS; i++) {
        printf("���� %d:\n", i + 1);
        printf("������� ����: ");
        scanf("%d", &scores[0][i]);
        printf("����������� ����: ");
        scanf("%d", &scores[1][i]);
    }

    // ������� �����
    for (int i = 0; i < COLS; i++) {
        int goals_scored = scores[0][i];
        int goals_conceded = scores[1][i];

        if (goals_scored > goals_conceded) {
            total_points += 3; // �������
        }
        else if (goals_scored == goals_conceded) {
            total_points += 1; // �����
        }
        else {
            total_points += 0; // ��������
        }
    }

    // ����� ����������
    printf("����� ���������� �����: %d\n", total_points);

    return 0;
}