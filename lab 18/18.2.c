#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>

void center(const char* message) {
    int length = strlen(message);
    int padding = (80 - length) / 2;
    for (int i = 0; i < padding; i++) {
        printf("*");
    }
    printf("%*s", length, message);
    for (int i = 0; i < padding; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "RUS");

    struct tm* mytime;
    time_t t;
    t = time(NULL);
    mytime = localtime(&t);

    for (int i = 0; i < 80; i++) {
        printf("*");
    }
    printf("\n");

    char array[200];
    sprintf(array, "����� � ������ %02d:%02d:%02d", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    center(array);

    switch (mytime->tm_wday) {
    case 0: sprintf(array, "������� �����������"); break;
    case 1: sprintf(array, "������� �����������"); break;
    case 2: sprintf(array, "������� �������"); break;
    case 3: sprintf(array, "������� �����"); break;
    case 4: sprintf(array, "������� �������"); break;
    case 5: sprintf(array, "������� �������"); break;
    case 6: sprintf(array, "������� �������"); break;
    }
    center(array);

    sprintf(array, "%02d.%02d.%04d", mytime->tm_mday, mytime->tm_mon + 1, mytime->tm_year + 1900);
    center(array);

    switch (mytime->tm_mon) {
    case 0: sprintf(array, "%d ������", mytime->tm_mday); break;
    case 1: sprintf(array, "%d �������", mytime->tm_mday); break;
    case 2: sprintf(array, "%d �����", mytime->tm_mday); break;
    case 3: sprintf(array, "%d ������", mytime->tm_mday); break;
    case 4: sprintf(array, "%d ���", mytime->tm_mday); break;
    case 5: sprintf(array, "%d ����", mytime->tm_mday); break;
    case 6: sprintf(array, "%d ����", mytime->tm_mday); break;
    case 7: sprintf(array, "%d �������", mytime->tm_mday); break;
    case 8: sprintf(array, "%d ��������", mytime->tm_mday); break;
    case 9: sprintf(array, "%d �������", mytime->tm_mday); break;
    case 10: sprintf(array, "%d ������", mytime->tm_mday); break;
    case 11: sprintf(array, "%d �������", mytime->tm_mday); break;
    }
    center(array);

    sprintf(array, "������� %d ���� %d ����", mytime->tm_yday + 1, mytime->tm_year + 1900);
    center(array);

    sprintf(array, "�� ����������� �������� %d ���� � %d �����", (7 - mytime->tm_wday), (23 - mytime->tm_hour));
    center(array);

    sprintf(array, "� ������ ���� ������ %d ����� � %d �����", mytime->tm_hour - 9, mytime->tm_min - 30);
    center(array);

    sprintf(array, "�� ������ ���� �������� %d ������� � %d ����", (12 - mytime->tm_mon - 1), (31 - mytime->tm_mday));
    center(array);

    sprintf(array, "�� ����� ���� �������� %d ����� � %d ������", (90 - mytime->tm_min), (59 - mytime->tm_sec));
    center(array);

    sprintf(array, "�� ����� ������ %d ����, �� ����� ���� %d �������", (31 - mytime->tm_mday), (12 - mytime->tm_mon));
    center(array);

    switch (mytime->tm_mon) {
    case 0: sprintf(array, "����� 1, ��� - %d", mytime->tm_year + 1900); break;
    case 1: sprintf(array, "����� 2, ��� - %d", mytime->tm_year + 1900); break;
    case 2: sprintf(array, "����� 3, ��� - %d", mytime->tm_year + 1900); break;
    case 3: sprintf(array, "����� 4, ��� - %d", mytime->tm_year + 1900); break;
    case 4: sprintf(array, "����� 5, ��� - %d", mytime->tm_year + 1900); break;
    case 5: sprintf(array, "����� 6, ��� - %d", mytime->tm_year + 1900); break;
    case 6: sprintf(array, "����� 7, ��� - %d", mytime->tm_year + 1900); break;
    case 7: sprintf(array, "����� 8, ��� - %d", mytime->tm_year + 1900); break;
    case 8: sprintf(array, "����� 9, ��� - %d", mytime->tm_year + 1900); break;
    case 9: sprintf(array, "����� 10, ��� - %d", mytime->tm_year + 1900); break;
    case 10: sprintf(array, "����� 11, ��� - %d", mytime->tm_year + 1900); break;
    case 11: sprintf(array, "����� 12, ��� - %d", mytime->tm_year + 1900); break;
    }
    center(array);

    return 0;
}