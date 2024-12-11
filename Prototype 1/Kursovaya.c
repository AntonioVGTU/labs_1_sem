#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define MAX_MICE 15

typedef struct {
    char manufacturer[50];
    int isGaming;
    char connectionType[1];
    int hasLighting;
    char interface[20];
    int silentButtons;
    int buttonCount;
    char color[20];
    char type[20];
    int maxDPI;
    char sensorType[20];
} mouse_t;

int addMouse(mouse_t mice[], int* count) {
    if (*count >= MAX_MICE) {
        printf("Максимальное количество записей достигнуто.\n");
        return;
    }
    printf("Введите производителя: ");
    scanf("%s", mice[*count].manufacturer);

    printf("Игровая? (1 - да, 0 - нет): ");
    scanf("%d", &mice[*count].isGaming);

    printf("Введите тип подключения: (1 - проводная, 2 - беспроводная): ");
    scanf("%s", mice[*count].connectionType);

    printf("Наличие подсветки: (1 - да, 0 - нет): ");
    scanf("%d", &mice[*count].hasLighting);

    printf("Введите интерфейс подключения: ");
    scanf("%s", mice[*count].interface);

    printf("Бесшумные кнопки: (1 - да, 0 - нет): ");
    scanf("%d", &mice[*count].silentButtons);

    printf("Общее количество кнопок: ");
    scanf("%d", &mice[*count].buttonCount);

    printf("Цвет: ");
    scanf("%s", mice[*count].color);

    printf("Тип мыши: ");
    scanf("%s", mice[*count].type);

    printf("Максимальное разрешение датчика (dpi): ");
    scanf("%d", &mice[*count].maxDPI);

    printf("Тип сенсора: ");
    scanf("%s", mice[*count].sensorType);

    (*count)++;

    return 1;
}

#include <string.h> // Для strcmp

int searchMouse(const mouse_t mice[], int count, mouse_t results[], char* color, char* interface, int searchOption) {
    int resultCount = 0;

    for (int i = 0; i < count; i++) {
        int mcolor = (searchOption == 1 || searchOption == 3) && strcmp(mice[i].color, color) == 0;
        int minterface = (searchOption == 2 || searchOption == 3) && strcmp(mice[i].interface, interface) == 0;

        if (searchOption == 1 && mcolor)
            results[resultCount++] = mice[i];
        else if (searchOption == 2 && minterface)
            results[resultCount++] = mice[i];
        else if (searchOption == 3 && mcolor && minterface)
            results[resultCount++] = mice[i];
    }

    return resultCount;
}


int saveToTextFile(mouse_t mice[], int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return 2;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%s,%d,%s,%d,%d,%s,%s,%d,%s\n",
            mice[i].manufacturer,
            mice[i].isGaming,
            mice[i].connectionType,
            mice[i].hasLighting,
            mice[i].interface,
            mice[i].silentButtons,
            mice[i].buttonCount,
            mice[i].color,
            mice[i].type,
            mice[i].maxDPI,
            mice[i].sensorType);
    }
    fclose(file);
    return 1;
}

int loadFromTextFile(mouse_t mice[], int* count, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: невозможно открыть файл для чтения.\n");
        return;
    }

    *count = 0;
    while
        (fscanf(file, "%49[^,],%d,%19[^,],%d,%19[^,],%d,%d,%19[^,],%19[^,],%d,%19[^\n]\n",
            mice[*count].manufacturer,
            &mice[*count].isGaming,
            mice[*count].connectionType,
            &mice[*count].hasLighting,
            mice[*count].interface,
            &mice[*count].silentButtons,
            &mice[*count].buttonCount,
            mice[*count].color,
            mice[*count].type,
            &mice[*count].maxDPI,
            mice[*count].sensorType) == 11) {
        (*count)++;
        if (*count >= MAX_MICE) {
            return 2;
            break;
        }
    }

    fclose(file);
    return 1;
}

void bubbleSort(mouse_t* mice, int count, int criterion) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swapNeeded = 0;

            if (criterion == 1) {
                // сортировка по игровая
                if (mice[j].isGaming < mice[j + 1].isGaming) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 2) {
                // сортировка по типу подключения
                if (mice[j].connectionType > mice[j + 1].connectionType) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 3) {
                // сортировка по обоим критериям
                if (mice[j].isGaming < mice[j + 1].isGaming ||
                    (mice[j].isGaming == mice[j + 1].isGaming &&
                        mice[j].connectionType > mice[j + 1].connectionType)) {
                    swapNeeded = 1;
                }
            }

            // обмен элементов
            if (swapNeeded) {
                mouse_t temp = mice[j];
                mice[j] = mice[j + 1];
                mice[j + 1] = temp;
            }
        }
    }
}

int editMouse(mouse_t mice[], int count, const char* manufacturer) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(mice[i].manufacturer, manufacturer) == 0) {
            found = 1;
            printf("Редактирование записи для производителя %s\n", manufacturer);

            int choice;
            do {
                printf("\nВыберите поле для изменения:\n");
                printf("1. Игровая (1 - да, 0 - нет)\n");
                printf("2. Тип подключения (1 - проводная, 2 - беспроводная): \n");
                printf("3. Подсветка (1 - да, 0 - нет)\n");
                printf("4. Интерфейс подключения\n");
                printf("5. Бесшумные кнопки (1 - да, 0 - нет)\n");
                printf("6. Общее количество кнопок\n");
                printf("7. Цвет\n");
                printf("8. Тип мыши\n");
                printf("9. Максимальное разрешение датчика (dpi)\n");
                printf("10. Тип сенсора\n");
                printf("0. Выход\n");
                printf("Ваш выбор: ");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                    printf("Игровая? (1 - да, 0 - нет): ");
                    scanf("%d", &mice[i].isGaming);
                    break;
                case 2:
                    printf("Введите новый тип подключения: (1 - проводная, 2 - беспроводная) ");
                    scanf("%s", &mice[i].connectionType);
                    break;
                case 3:
                    printf("Подсветка (1 - да, 0 - нет): ");
                    scanf("%d", &mice[i].hasLighting);
                    break;
                case 4:
                    printf("Введите новый интерфейс подключения: ");
                    scanf("%s", mice[i].interface);
                    break;
                case 5:
                    printf("Бесшумные кнопки (1 - да, 0 - нет): ");
                    scanf("%d", &mice[i].silentButtons);
                    break;
                case 6:
                    printf("Введите новое общее количество кнопок: ");
                    scanf("%d", &mice[i].buttonCount);
                    break;
                case 7:
                    printf("Введите новый цвет: ");
                    scanf("%s", mice[i].color);
                    break;
                case 8:
                    printf("Введите новый тип мыши: ");
                    scanf("%s", mice[i].type);
                    break;
                case 9:
                    printf("Введите новое максимальное разрешение датчика (dpi): ");
                    scanf("%d", &mice[i].maxDPI);
                    break;
                case 10:
                    printf("Введите новый тип сенсора: ");
                    scanf("%s", mice[i].sensorType);
                    break;
                case 0:
                    printf("Выход из режима редактирования.\n");
                    break;
                default:
                    printf("Неверный выбор. Попробуйте снова.\n");
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

int deleteMouse(mouse_t mice[], int* count, const char* manufacturer) {
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(mice[i].manufacturer, manufacturer) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return 0;
    }
    // сдвиг массива для удаления записи
    for (int i = index; i < *count - 1; i++) {
        mice[i] = mice[i + 1];
    }
    (*count)--;
    return 1;
}


int main() {
    setlocale(LC_ALL, "rus");
    mouse_t mice[MAX_MICE];
    int count = 0;
    int choice;
    char filename[] = "data_base.txt";
    int sortCr = 0;

    do {
        printf("Меню:\n");
        printf("1. Добавить новую запись\n");
        printf("2. Найти запись по цвету или интерфейсу подключения\n");
        printf("3. Сохранить данные в файл\n");
        printf("4. Загрузить данные из файла\n");
        printf("5. Показать все записи\n");
        printf("6. Изменить запись по производителю\n");
        printf("7. Сортировать записи\n");
        printf("8. Удаление записи\n");
        printf("0. Выход\n");
        printf("Выберите опцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {

            int result1 = addMouse(mice, &count);
            if (result1 == 1)
                printf("\nЗапись добавлена.\n");
            else
                printf("\nОшибка добавления записи\n");
            break;
        }
        case 2: {
            int searchOption;
            printf("Выберите вариант поиска:\n1. По цвету\n2. По интерфейсу подключения\n3. По цвету и интерфейсу подключения\n");
            scanf("%d", &searchOption);

            char color[20];
            char connectionType[20];

            if (searchOption == 1 || searchOption == 3) {
                printf("Введите цвет: ");
                scanf("%19s", color);
            }

            if (searchOption == 2 || searchOption == 3) {
                printf("Введите интерфейс подключения: ");
                scanf("%19s", connectionType);
            }
            mouse_t results[MAX_MICE];
            int foundCount = searchMouse(mice, count, results, color, connectionType, searchOption);

            if (foundCount > 0) {
                printf("Найдено %d записей:\n", foundCount);
                for (int i = 0; i < foundCount; i++) {
                    printf("Производитель: %s, Игровая: %d, Интерфейс подключения: %s, Цвет: %s\n", results[i].manufacturer, results[i].isGaming, results[i].interface, results[i].color);
                }
            }
            else {
                printf("Записи не найдены.\n");
            }

            break;
        }
        case 3: {
            int result3 = saveToTextFile(mice, count, filename);
            if (result3 == 1)
                printf("\nДанные успешно сохранены в текстовый файл.\n");
            else if (result3 == 2)
                printf("Ошибка: невозможно открыть файл для записи.\n");
            else
                printf("\nОшибка сохранения данных\n");
            break;
        }
        case 4: {
            int result4 = loadFromTextFile(mice, &count, filename);
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
                printf("Производитель: %s, Тип подключения: %s, Цвет: %s, Игровая: %s\n", mice[i].manufacturer, (mice[i].connectionType[0] == '1') ? "проводная" : "беспроводная", mice[i].color, (mice[i].isGaming == 1) ? "Да" : "Нет");
            }
            break;
        case 6: {
            char manufacturer[50];
            printf("Введите производителя для редактирования: ");
            scanf("%s", manufacturer);
            int result6 = editMouse(mice, count, manufacturer);
            if (result6 == 1)
                printf("Поле успешно обновлено.\n");
            else
                printf("\nОшибка обновления поля\n");
            break;
        }
        case 7: {
            printf("Выберите параметр сортировки:\n1. Игровая или нет\n2. Тип подключения (1 = проводная, 2 = беспроводная)\n3. По обоим критериям\n");
            scanf("%d", &sortCr);

            bubbleSort(mice, count, sortCr);

            printf("Записи после сортировки:\n");
            for (int i = 0; i < count; i++) {
                printf("Производитель: %s, Игровая: %d, Тип подключения: %s, Цвет: %s\n", mice[i].manufacturer, mice[i].isGaming, (mice[i].connectionType[0] == '1') ? "проводная" : "беспроводная", mice[i].color);
            }
            break;
        }
        case 8:
        {
            char manufacturer[50];
            printf("Введите производителя для удаления: ");
            scanf("%49s", manufacturer);

            int result = deleteMouse(mice, &count, manufacturer);

            if (result == 1) {
                printf("Запись успешно удалена.\n");
            }
            else {
                printf("Запись с указанным производителем не найдена.\n");
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
}