#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main(void) {
    setlocale(LC_ALL, "ru");
    char fname[20] = "number.txt"; // ��� �����
    FILE* out; // ���� �����

    puts("�������� �����");

    // �������� ����� ��� ������
    if ((out = fopen(fname, "wt")) == NULL) {
        printf("������ �������� ����� ��� ������");
        return 0; // ����� � �������
    }
    srand(time(NULL));
    int random_number = rand() % 10;
    fprintf(out, "%d", random_number);
    fclose(out);
    system("start number.txt");

    return 1; // ������� ����
}