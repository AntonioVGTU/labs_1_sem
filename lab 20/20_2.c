#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ������� ��� �������������� �����
void transform_numbers(FILE* in, FILE* out) {
    double num;
    int count = 0;

    while (fscanf(in, "%lf", &num) == 1) {
        count++;
        if (count % 4 == 0) {
            num /= 2.0;
        }
        fprintf(out, "%.2f\n", num);
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    char input_filename[] = "temp.txt";
    char output_filename[] = "temp_parity4.txt";
    FILE* in, * out;
    if ((in = fopen(input_filename, "r")) == NULL) {
        perror("������ �������� ����� ��� ������");
        return 1;
    }
    if ((out = fopen(output_filename, "w")) == NULL) {
        perror("������ �������� ����� ��� ������");
        fclose(in);
        return 1;
    }
    transform_numbers(in, out);

    // �������� ������
    fclose(in);
    fclose(out);

    printf("�������������� ���������. ��������� ������� � ����: %s\n", output_filename);
}