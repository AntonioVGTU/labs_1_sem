#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_ROUTERS 100

typedef struct {
    char manufacturer[50];
    char antennaType[50];
    char operatingModes[50];
    float transmitterFrequency;
    bool dualBandOperation;
    int ethernetPorts;
    bool meshSupport;
    char wifiStandard[50];
    int ethernetSpeed;
    char wifiClass[50];
    float transmitterPower;
    int maxWirelessSpeed;
} router_t;

int addRouter(router_t routers[], int* count) {
    printf("Введите производителя: ");
    scanf("%s", routers[*count].manufacturer);
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите тип антенны: ");
    scanf("%s", routers[*count].antennaType);
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите режимы работы: ");
    scanf("%s", routers[*count].operatingModes);
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите частоту работы передатчика (ГГц): ");
    while (scanf("%f", &routers[*count].transmitterFrequency) != 1) {
        printf("Ошибка: введите корректное значение.\n");
        while (getchar() != '\n'); // отчистка буфера ввода
    }
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Одновременная работа в двух диапазонах (1 - да, 0 - нет): ");
    while (scanf("%d", &routers[*count].dualBandOperation) != 1 || (routers[*count].dualBandOperation != 0 && routers[*count].dualBandOperation != 1)) {
        printf("Ошибка: введите 1 - (да) или 0 - (нет).\n");
        while (getchar() != '\n'); // отчистка буфера ввода
    }
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите количество портов Ethernet: ");
    while (scanf("%d", &routers[*count].ethernetPorts) != 1) {
        printf("Ошибка: введите корректное значение.\n");
        while (getchar() != '\n'); // отчистка буфера ввода
    }
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Поддержка MESH (1 - да, 0 - нет): ");
    while (scanf("%d", &routers[*count].meshSupport) != 1 || (routers[*count].meshSupport != 0 && routers[*count].meshSupport != 1)) {
        printf("Ошибка: введите 1 - (да) или 0 - (нет).\n");
        while (getchar() != '\n'); // отчистка буфера ввода
    }
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите стандарт Wi-Fi: ");
    scanf("%s", routers[*count].wifiStandard);
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите скорость передачи данных Ethernet (Мбит/с): ");
    while (scanf("%d", &routers[*count].ethernetSpeed) != 1) {
        printf("Ошибка: введите корректное значение.\n");
        while (getchar() != '\n'); // отчистка буфера ввода
    }
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите класс Wi-Fi: ");
    scanf("%s", routers[*count].wifiClass);
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите выходную мощность передатчика (dBm): ");
    while (scanf("%f", &routers[*count].transmitterPower) != 1) {
        printf("Ошибка: введите корректное значение.\n");
        while (getchar() != '\n'); // отчистка буфера ввода
    }
    while (getchar() != '\n'); // отчистка буфера ввода

    printf("Введите максимальную скорость беспроводного соединения (Мбит/с): ");
    while (scanf("%d", &routers[*count].maxWirelessSpeed) != 1) {
        printf("Ошибка: введите корректное значение.\n");
        while (getchar() != '\n'); // отчистка буфера ввода
    }
    while (getchar() != '\n'); // отчистка буфера ввода

    (*count)++;

    return 1;
}

bool isInteger(const char* str) {
    if (*str == '\0') return false; // пустая строка — не число

    // проверка каждого символа строки
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return false; // если символ не цифра, возвращаем false
        }
        str++;
    }

    return true; // все символы — цифры
}

int getValidInteger(const char* prompt) {
    char input[50];
    int value;

    while (true) {
        printf("%s", prompt);
        scanf("%49s", input); // считываем как строку

        if (isInteger(input)) {
            sscanf(input, "%d", &value); // преобразование строки в int
            return value;
        }
        else {
            printf("Ошибка: недопустимые символы. Введите число.\n");
        }
    }
}

int searchRouter(const router_t routers[], int count, router_t results[], char* wifiClass, char* wifiStandard, int searchOption) {
    int resultCount = 0;

    for (int i = 0; i < count; i++) {
        int mwifiClass = (searchOption == 1 || searchOption == 3) && strcmp(routers[i].wifiClass, wifiClass) == 0;
        int mwifiStandard = (searchOption == 2 || searchOption == 3) && strcmp(routers[i].wifiStandard, wifiStandard) == 0;

        if (searchOption == 1 && mwifiClass)
            results[resultCount++] = routers[i]; // сохранение указателя на запись
        else if (searchOption == 2 && mwifiStandard)
            results[resultCount++] = routers[i];
        else if (searchOption == 3 && mwifiClass && mwifiStandard)
            results[resultCount++] = routers[i];
    }

    return resultCount;// возврат количества найденных записей через указатель
}

int saveToTextFile(router_t routers[], int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return 2;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s,%f,%d,%d,%d,%s,%d,%s,%f,%d\n",
            routers[i].manufacturer,
            routers[i].antennaType,
            routers[i].operatingModes,
            routers[i].transmitterFrequency,
            routers[i].dualBandOperation,
            routers[i].ethernetPorts,
            routers[i].meshSupport,
            routers[i].wifiStandard,
            routers[i].ethernetSpeed,
            routers[i].wifiClass,
            routers[i].transmitterPower,
            routers[i].maxWirelessSpeed);
    }
    fclose(file);
    return 1;
}

int loadFromTextFile(router_t routers[], int* count, const char* filename) {
    FILE* file = fopen(filename, "r");

    *count = 0;
    while
        (fscanf(file, "%49[^,],%49[^,],%49[^,],%f,%d,%d,%d,%49[^,],%d,%49[^,],%f,%d\n",
            routers[*count].manufacturer,
            routers[*count].antennaType,
            routers[*count].operatingModes,
            &routers[*count].transmitterFrequency,
            &routers[*count].dualBandOperation,
            &routers[*count].ethernetPorts,
            &routers[*count].meshSupport,
            routers[*count].wifiStandard,
            &routers[*count].ethernetSpeed,
            routers[*count].wifiClass,
            &routers[*count].transmitterPower,
            &routers[*count].maxWirelessSpeed) == 12) {
        (*count)++;
        if (*count >= MAX_ROUTERS) {
            return 2;
            break;
        }
    }

    fclose(file);
    return 1;
}

int bubbleSort(router_t* routers, int count, int criterion) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swapNeeded = 0;

            if (criterion == 1) {
                // сортировка по одновременной работе в двух диапазонах
                if (routers[j].dualBandOperation < routers[j + 1].dualBandOperation) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 2) {
                // сортировка по стандарту Wi-Fi
                if (strcmp(routers[j].wifiStandard, routers[j + 1].wifiStandard) > 0) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 3) {
                // сортировка по обоим критериям
                if (routers[j].dualBandOperation < routers[j + 1].dualBandOperation ||
                    (routers[j].dualBandOperation == routers[j + 1].dualBandOperation &&
                        strcmp(routers[j].wifiStandard, routers[j + 1].wifiStandard) > 0)) {
                    swapNeeded = 1;
                }
            }

            // обмен элементов
            if (swapNeeded) {
                router_t temp = routers[j];
                routers[j] = routers[j + 1];
                routers[j + 1] = temp;
            }
        }
    }
    return 1;
}

int editRouter(router_t routers[], int count, const char* manufacturer) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(routers[i].manufacturer, manufacturer) == 0) {
            found = 1;
            printf("Редактирование записи для производителя %s\n", manufacturer);

            int choice;
            do {
                printf("\nВыберите поле для изменения:\n");
                printf("1. Тип антенны\n");
                printf("2. Режимы работы\n");
                printf("3. Частота работы передатчика (ГГц)\n");
                printf("4. Одновременная работа в двух диапазонах (1 - да, 0 - нет)\n");
                printf("5. Количество портов Ethernet\n");
                printf("6. Поддержка MESH (1 - да, 0 - нет)\n");
                printf("7. Стандарт Wi-Fi\n");
                printf("8. Скорость передачи данных Ethernet (Мбит/с)\n");
                printf("9. Класс Wi-Fi\n");
                printf("10. Выходная мощность передатчика (dBm)\n");
                printf("11. Максимальная скорость беспроводного соединения (Мбит/с)\n");
                printf("0. Выход\n");
                printf("Ваш выбор: ");
                scanf("%d", &choice);
                while (getchar() != '\n'); // отчистка буфера ввода

                switch (choice) {
                case 1:
                    printf("Введите новый тип антенны: ");
                    scanf("%s", routers[i].antennaType);
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 2:
                    printf("Введите новые режимы работы: ");
                    scanf("%s", routers[i].operatingModes);
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 3:
                    printf("Введите новую частоту работы передатчика (ГГц): ");
                    while (scanf("%f", &routers[i].transmitterFrequency) != 1) {
                        printf("Ошибка: введите корректное значение.\n");
                        while (getchar() != '\n'); // отчистка буфера ввода
                    }
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 4:
                    printf("Одновременная работа в двух диапазонах (1 - да, 0 - нет): ");
                    while (scanf("%d", &routers[i].dualBandOperation) != 1 || (routers[i].dualBandOperation != 0 && routers[i].dualBandOperation != 1)) {
                        printf("Ошибка: введите 1 - (да) или 0 - (нет).\n");
                        while (getchar() != '\n'); // отчистка буфера ввода
                    }
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 5:
                    printf("Введите новое количество портов Ethernet: ");
                    while (scanf("%d", &routers[i].ethernetPorts) != 1) {
                        printf("Ошибка: введите корректное значение.\n");
                        while (getchar() != '\n'); // отчистка буфера ввода
                    }
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 6:
                    printf("Поддержка MESH (1 - да, 0 - нет): ");
                    while (scanf("%d", &routers[i].meshSupport) != 1 || (routers[i].meshSupport != 0 && routers[i].meshSupport != 1)) {
                        printf("Ошибка: введите 1 - (да) или 0 - (нет).\n");
                        while (getchar() != '\n'); // отчистка буфера ввода
                    }
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 7:
                    printf("Введите новый стандарт Wi-Fi: ");
                    scanf("%s", routers[i].wifiStandard);
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 8:
                    printf("Введите новую скорость передачи данных Ethernet (Мбит/с): ");
                    while (scanf("%d", &routers[i].ethernetSpeed) != 1) {
                        printf("Ошибка: введите корректное значение.\n");
                        while (getchar() != '\n'); // отчистка буфера ввода
                    }
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 9:
                    printf("Введите новый класс Wi-Fi: ");
                    scanf("%s", routers[i].wifiClass);
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 10:
                    printf("Введите новую выходную мощность передатчика (dBm): ");
                    while (scanf("%f", &routers[i].transmitterPower) != 1) {
                        printf("Ошибка: введите корректное значение.\n");
                        while (getchar() != '\n'); // отчистка буфера ввода
                    }
                    while (getchar() != '\n'); // отчистка буфера ввода
                    break;
                case 11:
                    printf("Введите новую максимальную скорость беспроводного соединения (Мбит/с): ");
                    while (scanf("%d", &routers[i].maxWirelessSpeed) != 1) {
                        printf("Ошибка: введите корректное значение.\n");
                        while (getchar() != '\n'); // отчистка буфера ввода
                    }
                    while (getchar() != '\n'); // отчистка буфера ввода
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

            return 0;
        }
    }
    if (!found) {
        printf("Запись не найдена.\n");
    }
}

int deleteRouter(router_t routers[], int* count, const char* manufacturer) {
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(routers[i].manufacturer, manufacturer) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return 0;
    }
    // сдвиг массива для удаления записи
    for (int i = index; i < *count - 1; i++) {
        routers[i] = routers[i + 1];
    }
    (*count)--;
    return 1;
}

int main() {
    setlocale(LC_ALL, "ru");
    router_t* routers = (router_t*)malloc(MAX_ROUTERS * sizeof(router_t));
    int count = 0;
    int choice;
    char filename[] = "data_base.txt";
    int sortCr = 0;
    int cnt;

    do {
        printf("Меню:\n");
        printf("1. Добавить новую запись\n");
        printf("2. Найти запись по классу Wi-Fi или стандарту Wi-Fi\n");
        printf("3. Сохранить данные в файл\n");
        printf("4. Загрузить данные из файла\n");
        printf("5. Показать все записи\n");
        printf("6. Изменить запись по производителю\n");
        printf("7. Сортировать записи\n");
        printf("8. Удаление записи\n");
        printf("0. Выход\n");
        printf("Выберите опцию: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // отчистка буфера ввода

        switch (choice) {
        case 1: {
            printf("Сколько записей добавить?\n");
            scanf("%d", &cnt);
            while (getchar() != '\n'); // отчистка буфера ввода
            for (int i = 0; i < cnt; i++) {
                printf("Запись %d\n", i + 1);
                int result1 = addRouter(routers, &count);
                if (result1 == 1) {
                    printf("\nЗапись добавлена.\n");
                }
                else
                    printf("\nОшибка добавления записи\n");
            }
            printf("Файл сохранён.\n");
            saveToTextFile(routers, count, filename);
            break;
        }
        case 2: {
            int searchOption;
            printf("Выберите вариант поиска:\n1. По классу Wi-Fi\n2. По стандарту Wi-Fi\n3. По классу Wi-Fi и стандарту Wi-Fi\n");
            scanf("%d", &searchOption);
            while (getchar() != '\n'); // отчистка буфера ввода

            char wifiClass[20];
            char wifiStandard[20];

            if (searchOption == 1 || searchOption == 3) {
                printf("Введите класс Wi-Fi: ");
                scanf("%19s", wifiClass);
                while (getchar() != '\n'); // отчистка буфера ввода
            }

            if (searchOption == 2 || searchOption == 3) {
                printf("Введите стандарт Wi-Fi: ");
                scanf("%19s", wifiStandard);
                while (getchar() != '\n'); // отчистка буфера ввода
            }
            router_t results[MAX_ROUTERS];
            int foundCount = searchRouter(routers, count, results, wifiClass, wifiStandard, searchOption);

            if (foundCount > 0) {
                printf("Найдено %d записей:\n", foundCount);
                for (int i = 0; i < foundCount; i++) {
                    printf("Производитель: %s, Одновременная работа в двух диапазонах: %d, Стандарт Wi-Fi: %s, Класс Wi-Fi: %s\n", results[i].manufacturer, results[i].dualBandOperation, results[i].wifiStandard, results[i].wifiClass);
                }
            }
            else {
                printf("Записи не найдены.\n");
            }

            break;
        }
        case 3: {
            int result3 = saveToTextFile(routers, count, filename);
            if (result3 == 1)
                printf("\nДанные успешно сохранены в текстовый файл.\n");
            else if (result3 == 2)
                printf("Ошибка: невозможно открыть файл для записи.\n");
            else
                printf("\nОшибка сохранения данных\n");
            break;
        }
        case 4: {
            int result4 = loadFromTextFile(routers, &count, filename);
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
                printf("Производитель: %s, Тип антенны: %s, Режимы работы: %s, Частота работы передатчика: %f ГГц, Одновременная работа в двух диапазонах: %s, Количество портов Ethernet: %d, Поддержка MESH: %s, Стандарт Wi-Fi: %s, Скорость передачи данных Ethernet: %d Мбит/с, Класс Wi-Fi: %s, Выходная мощность передатчика: %f dBm, Максимальная скорость беспроводного соединения: %d Мбит/с\n",
                    routers[i].manufacturer,
                    routers[i].antennaType,
                    routers[i].operatingModes,
                    routers[i].transmitterFrequency,
                    (routers[i].dualBandOperation ? "Да" : "Нет"),
                    routers[i].ethernetPorts,
                    (routers[i].meshSupport ? "Да" : "Нет"),
                    routers[i].wifiStandard,
                    routers[i].ethernetSpeed,
                    routers[i].wifiClass,
                    routers[i].transmitterPower,
                    routers[i].maxWirelessSpeed);
            }
            break;
        case 6: {
            char manufacturer[50];
            printf("Введите производителя для редактирования: ");
            scanf("%s", manufacturer);
            while (getchar() != '\n'); // отчистка буфера ввода
            int result6 = editRouter(routers, count, manufacturer);
            if (result6 == 1) {
                printf("Поле успешно обновлено и сохранено.\n");
                saveToTextFile(routers, count, filename);
            }
            else
                printf("\nОшибка обновления поля\n");
            break;
        }
        case 7: {
            printf("Выберите параметр сортировки:\n1. Одновременная работа в двух диапазонах \n2. Стандарт Wi-Fi \n3. По обоим критериям\n");
            scanf("%d", &sortCr);
            while (getchar() != '\n'); // отчистка буфера ввода

            int result7 = bubbleSort(routers, count, sortCr);
            if (result7 == 1) {
                printf("Записи после сортировки:\n");
                for (int i = 0; i < count; i++) {
                    printf("Производитель: %s, Одновременная работа в двух диапазонах: %s, Стандарт Wi-Fi: %s\n", routers[i].manufacturer, (routers[i].dualBandOperation ? "Да" : "Нет"), routers[i].wifiStandard);
                }
            }
            break;
        }
        case 8:
        {
            char manufacturer[50];
            printf("Введите производителя для удаления: ");
            scanf("%49s", manufacturer);
            while (getchar() != '\n'); // отчистка буфера ввода

            int result = deleteRouter(routers, &count, manufacturer);

            if (result == 1) {
                printf("Запись успешно удалена и файл сохранен.\n");
                saveToTextFile(routers, count, filename);
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