#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // ������������� ���������� ��������� �����
    srand(time(NULL));

    // ��������� ������������ ����� �� 0 �� 9
    int random_number = rand() % 10;

    // �������� � �������� ����� number.txt ��� ������
    FILE* file = fopen("number.txt", "w");
    if (file == NULL) {
        perror("������ ��� �������� �����");
        return 1;
    }

    // ������ ����� � ����
    fprintf(file, "%d", random_number);

    // �������� �����
    fclose(file);

    printf("����� %d �������� � ���� number.txt\n", random_number);

    return 0;
}