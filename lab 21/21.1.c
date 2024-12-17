#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

typedef struct Cornice {
    int length;
    int ceilingWidth;
    int wallHeight;
    char material[20];
} cornice_t;

int addCornice(cornice_t mice[], int* count) {
    if (*count >= SIZE) {
        printf("Максимальное количество записей достигнуто.\n");
        return;
    }
    printf("Длина: ");
    scanf("%d", &mice[*count].length);

    printf("Ширина: ");
    scanf("%d", &mice[*count].ceilingWidth);

    printf("Высота: ");
    scanf("%d", &mice[*count].wallHeight);

    printf("Материал: ");
    scanf("%s", mice[*count].material);

    (*count)++;

    return 1;
}

int searchMouse(const cornice_t mice[], int count, cornice_t results[], int length, char* material, int searchOption) {
    int resultCount = 0;

    for (int i = 0; i < count; i++) {
        int mcolor = (searchOption == 1 || searchOption == 3) && (mice[i].length == length);
        int minterface = (searchOption == 2 || searchOption == 3) && strcmp(mice[i].material, material) == 0;

        if (searchOption == 1 && mcolor)
            results[resultCount++] = mice[i]; // сохранение указателя на запись
        else if (searchOption == 2 && minterface)
            results[resultCount++] = mice[i];
        else if (searchOption == 3 && mcolor && minterface)
            results[resultCount++] = mice[i];
    }

    return resultCount;// возврат количества найденных записей через указатель
}


int saveToTextFile(cornice_t mice[], int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return 2;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%d,%d,%s\n",
            mice[i].length,
            mice[i].ceilingWidth,
            mice[i].wallHeight,
            mice[i].material);
    }
    fclose(file);
    return 1;
}

int loadFromTextFile(cornice_t mice[], int* count, const char* filename) {
    FILE* file = fopen(filename, "r");

    *count = 0;
    while
        (fscanf(file, "%d,%d,%d,%19[^\n]\n",
            &mice[*count].length,
            &mice[*count].ceilingWidth,
            &mice[*count].wallHeight,
            mice[*count].material) == 4) {
        (*count)++;
        if (*count >= SIZE) {
            return 2;
            break;
        }
    }

    fclose(file);
    return 1;
}

void bubbleSort(cornice_t* mice, int count, int criterion) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swapNeeded = 0;

            if (criterion == 1) {
                // сортировка по длине
                if (mice[j].length < mice[j + 1].length) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 2) {
                // сортировка по высоте
                if (mice[j].wallHeight > mice[j + 1].wallHeight) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 3) {
                // сортировка по обоим критериям
                if (mice[j].length < mice[j + 1].length ||
                    (mice[j].length == mice[j + 1].length &&
                        mice[j].wallHeight > mice[j + 1].wallHeight)) {
                    swapNeeded = 1;
                }
            }

            // обмен элементов
            if (swapNeeded) {
                cornice_t temp = mice[j];
                mice[j] = mice[j + 1];
                mice[j + 1] = temp;
            }
        }
    }
}

int compare(const void* a, const void* b) {

    const cornice_t* corniceA = (const cornice_t*)a;
    const cornice_t* corniceB = (const cornice_t*)b;

    // Расчет площади для каждой записи
    int areaA = corniceA->length * corniceA->ceilingWidth;
    int areaB = corniceB->length * corniceB->ceilingWidth;
    // Сравнение площадей

    if (areaA < areaB) {
        return -1;
    }
    else if (areaA > areaB) {
        return 1;
    }
    return 0;
}

int editMouse(cornice_t mice[], int count, const char* material) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(mice[i].material, material) == 0) {
            found = 1;
            printf("Редактирование записи по материалу %s\n", material);

            int choice;
            do {
                printf("\nВыберите поле для изменения:\n");
                printf("1. Длина\n");
                printf("2. Ширина\n");
                printf("3. Высота\n");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                    printf("Новая длина: ");
                    scanf("%d", &mice[i].length);
                    break;
                case 2:
                    printf("Новая ширина ");
                    scanf("%s", &mice[i].ceilingWidth);
                    break;
                case 3:
                    printf("Новая высота ");
                    scanf("%d", &mice[i].wallHeight);
                    break;
                }

                if (choice != 0) {
                    return 1;
                }
            } while (choice != 0);

            return;
        }
    }
    if (!found) {
        printf("Запись не найдена.\n");
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    cornice_t cornices[SIZE];
    int count = 0;
    int choice;
    char filename[] = "data_base.txt";
    int sortCr = 0;

    do {
        printf("Меню:\n");
        printf("1. Добавить новую запись\n");
        printf("2. Найти запись по длине или материалу\n");
        printf("3. Сохранить данные в файл\n");
        printf("4. Загрузить данные из файла\n");
        printf("5. Показать все записи\n");
        printf("6. Изменить запись по материалу\n");
        printf("7. Сортировать записи\n");
        printf("8. Сортировка по площади\n");
        printf("0. Выход\n");
        printf("Выберите опцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {

            int result1 = addCornice(cornices, &count);
            if (result1 == 1)
                printf("\nЗапись добавлена.\n");
            else
                printf("\nОшибка добавления записи\n");
            break;
        }
        case 2: {
            int searchOption;
            printf("Выберите вариант поиска:\n1. По длине\n2. По материалу\n3. По длине и материалу\n");
            scanf("%d", &searchOption);

            int length = 0;
            char material[20];

            if (searchOption == 1 || searchOption == 3) {
                printf("Введите длину: ");
                scanf("%d", &length);
            }

            if (searchOption == 2 || searchOption == 3) {
                printf("Введите материал: ");
                scanf("%19s", material);
            }
            cornice_t results[SIZE];
            int foundCount = searchMouse(cornices, count, results, length, material, searchOption);

            if (foundCount > 0) {
                printf("Найдено %d записей:\n", foundCount);
                for (int i = 0; i < foundCount; i++) {
                    printf("Длина: %d, Ширина: %d, Высота: %d, Материал: %s\n", results[i].length, results[i].ceilingWidth, results[i].wallHeight, results[i].material);
                }
            }
            else {
                printf("Записи не найдены.\n");
            }

            break;
        }
        case 3: {
            int result3 = saveToTextFile(cornices, count, filename);
            if (result3 == 1)
                printf("\nДанные успешно сохранены в текстовый файл.\n");
            else if (result3 == 2)
                printf("Ошибка: невозможно открыть файл для записи.\n");
            else
                printf("\nОшибка сохранения данных\n");
            break;
        }
        case 4: {
            int result4 = loadFromTextFile(cornices, &count, filename);
            if (result4 == 1)
                printf("\nДанные успешно загружены из текстового файла.\n");
            else if (result4 == 2)
                printf("\nДостигнуто максимальное количество записей.\n");
            else
                printf("\nОшибка считывания данных\n");

            break;
        }
        case 5:
            for (int i = 0; i < count; i++) {
                printf("Длина: %d, Ширина: %d, Высота: %d, Материал: %s\n", cornices[i].length, cornices[i].ceilingWidth, cornices[i].wallHeight, cornices[i].material);
            }
            break;
        case 6: {
            char manufacturer[50];
            printf("Введите материал: ");
            scanf("%s", manufacturer);
            int result6 = editMouse(cornices, count, manufacturer);
            if (result6 == 1)
                printf("Поле успешно обновлено.\n");
            else
                printf("\nОшибка обновления поля\n");
            break;
        }
        case 7: {
            printf("Выберите параметр сортировки:\n1. Длина\n2. Высота\n3. По обоим критериям\n");
            scanf("%d", &sortCr);

            bubbleSort(cornices, count, sortCr);

            printf("Записи после сортировки:\n");
            for (int i = 0; i < count; i++) {
                printf("Длина: %d, Ширина: %d, Высота: %d, Материал: %s\n", cornices[i].length, cornices[i].ceilingWidth, cornices[i].wallHeight, cornices[i].material);
            }
            break;
        }
        case 8: {
            qsort(cornices, SIZE, sizeof(cornice_t), compare);
            printf("Записи после сортировки: (по возрастанию).\n");
            for (int i = 0; i < count; i++) {
                printf("Длина: %d, Ширина: %d, Высота: %d, Материал: %s, Площадь: %d\n", cornices[i].length, cornices[i].ceilingWidth, cornices[i].wallHeight, cornices[i].material, cornices[i].length * cornices[i].ceilingWidth);
            }
            break;
        }
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор.\n");
        }
    } while (choice != 0);
    system("data_base.txt");
}