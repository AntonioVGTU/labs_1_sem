#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ROWS 2
#define COLS 22

void fillArray(int array[ROWS][COLS]) {
    for (int j = 0; j < COLS; j++) {
        array[0][j] = rand() % 10; // ��������� ����� �� 0 �� 9 ��� ������� �����
        array[1][j] = rand() % 10; // ��������� ����� �� 0 �� 9 ��� ����������� �����
    }
}

void printArray(int array[ROWS][COLS]) {
    printf("������� ����: ");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", array[0][j]);
    }
    printf("\n");

    printf("����������� ����: ");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", array[1][j]);
    }
    printf("\n");
}

int calculatePoints(int array[ROWS][COLS]) {
    int totalPoints = 0;
    for (int j = 0; j < COLS; j++) {
        int scored = array[0][j];
        int conceded = array[1][j];
        if (scored > conceded) {
            totalPoints += 3;
        }
        else if (scored == conceded) {
            totalPoints += 1;
        }
    }
    return totalPoints;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int matchResults[ROWS][COLS];

    fillArray(matchResults);
    printArray(matchResults);

    int totalPoints = calculatePoints(matchResults);
    printf("����� ����� �����, ��������� ��������: %d\n", totalPoints);
}