#include <stdio.h>
#include <locale.h>
void sort_buble(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                int temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

void sort_shaker(int* ptrarr, int n) {
    int left = 0;
    int right = n - 1;
    int lastSwap;

    do {
        lastSwap = 0;

        for (int i = left; i < right; i++) {
            if (ptrarr[i] > ptrarr[i + 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = temp;
                lastSwap = i;
            }
        }
        right = lastSwap;

        for (int i = right; i > left; i--) {
            if (ptrarr[i] < ptrarr[i - 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = temp;
                lastSwap = i;
            }
        }
        left = lastSwap;

    } while (left < right);
}

void sort_select(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = ptrarr[i];
            ptrarr[i] = ptrarr[minIndex];
            ptrarr[minIndex] = temp;
        }
    }
}

void sort_insert(int* ptrarr, int n) {
    for (int i = 1; i < n; i++) {
        int key = ptrarr[i];
        int j = i - 1;
        while (j >= 0 && ptrarr[j] > key) {
            ptrarr[j + 1] = ptrarr[j];
            j--;
        }
        ptrarr[j + 1] = key;
    }
}

int main() {
    int arr[100], n, choice;

    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Выберите тип сортировки:\n");
    printf("1. Пузырьковая сортировка\n");
    printf("2. Шейкерная сортировка\n");
    printf("3. Сортировка простым выбором\n");
    printf("4. Сортировка вставками\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        sort_buble(arr, n);
        break;
    case 2:
        sort_shaker(arr, n);
        break;
    case 3:
        sort_select(arr, n);
        break;
    case 4:
        sort_insert(arr, n);
        break;
    default:
        printf("Неверный выбор!\n");
        return 1;
    }

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}