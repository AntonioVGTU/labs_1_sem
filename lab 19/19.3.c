#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ��������� ��� �������� ������ � ����������
typedef struct {
    char surname[20];
    char birth_date[11]; // ������: ��.��.����
    char club[20];
    char position[20];
    int games_played;
    char birth_place[20];
} Footballer;

// ������� ��� ������ ������ � ����
int writefile(char* fname, Footballer* footballers, int size) {
    FILE* out;
    if ((out = fopen(fname, "wt")) == NULL) {
        printf("������ �������� ����� ��� ������\n");
        return 0; // ����� � �������
    }

    for (int i = 0; i < size; i++) {
        fprintf(out, "�������: %20s ; ���� ��������: %10s ; ����: %20s ; ������: %20s ; ���������� ���: %d ; ����� ��������: %20s\n",
            footballers[i].surname, footballers[i].birth_date, footballers[i].club,
            footballers[i].position, footballers[i].games_played, footballers[i].birth_place);
    }

    fclose(out);
    return 1; // �������� �����
}

int main(void) {
    setlocale(LC_ALL, "Rus");

    char fname[20] = "footballers.txt";

    Footballer footballers[3];

    // ���� ������ � ������ ����������
    puts("������� ������ � ������ ����������:");
    printf("�������: ");
    scanf("%19s", footballers[0].surname);
    printf("���� �������� (��.��.����): ");
    scanf("%10s", footballers[0].birth_date);
    printf("����: ");
    scanf("%19s", footballers[0].club);
    printf("������: ");
    scanf("%19s", footballers[0].position);
    printf("���������� ���: ");
    scanf("%d", &footballers[0].games_played);
    getchar(); // ��������� ������ ����� ������
    printf("����� ��������: ");
    scanf("%19s", footballers[0].birth_place);

    // ���� ������ � ������ ����������
    puts("������� ������ � ������ ����������:");
    printf("�������: ");
    scanf("%19s", footballers[1].surname);
    printf("���� �������� (��.��.����): ");
    scanf("%10s", footballers[1].birth_date);
    printf("����: ");
    scanf("%19s", footballers[1].club);
    printf("������: ");
    scanf("%19s", footballers[1].position);
    printf("���������� ���: ");
    scanf("%d", &footballers[1].games_played);
    getchar(); // ��������� ������ ����� ������
    printf("����� ��������: ");
    scanf("%19s", footballers[1].birth_place);

    // ���� ������ � ������� ����������
    puts("������� ������ � ������� ����������:");
    printf("�������: ");
    scanf("%19s", footballers[2].surname);
    printf("���� �������� (��.��.����): ");
    scanf("%10s", footballers[2].birth_date);
    printf("����: ");
    scanf("%19s", footballers[2].club);
    printf("������: ");
    scanf("%19s", footballers[2].position);
    printf("���������� ���: ");
    scanf("%d", &footballers[2].games_played);
    getchar(); // ��������� ������ ����� ������
    printf("����� ��������: ");
    scanf("%19s", footballers[2].birth_place);

    // ������ ������ � ����
    if (!writefile(fname, footballers, 3)) {
        printf("������ ������ ������ � ����\n");
        return 1;
    }
    system("start footballers.txt");
}