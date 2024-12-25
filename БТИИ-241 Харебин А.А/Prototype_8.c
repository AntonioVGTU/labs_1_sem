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
    printf("������� �������������: ");
    scanf("%s", routers[*count].manufacturer);
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� ��� �������: ");
    scanf("%s", routers[*count].antennaType);
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� ������ ������: ");
    scanf("%s", routers[*count].operatingModes);
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� ������� ������ ����������� (���): ");
    while (scanf("%f", &routers[*count].transmitterFrequency) != 1) {
        printf("������: ������� ���������� ��������.\n");
        while (getchar() != '\n'); // �������� ������ �����
    }
    while (getchar() != '\n'); // �������� ������ �����

    printf("������������� ������ � ���� ���������� (1 - ��, 0 - ���): ");
    while (scanf("%d", &routers[*count].dualBandOperation) != 1 || (routers[*count].dualBandOperation != 0 && routers[*count].dualBandOperation != 1)) {
        printf("������: ������� 1 - (��) ��� 0 - (���).\n");
        while (getchar() != '\n'); // �������� ������ �����
    }
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� ���������� ������ Ethernet: ");
    while (scanf("%d", &routers[*count].ethernetPorts) != 1) {
        printf("������: ������� ���������� ��������.\n");
        while (getchar() != '\n'); // �������� ������ �����
    }
    while (getchar() != '\n'); // �������� ������ �����

    printf("��������� MESH (1 - ��, 0 - ���): ");
    while (scanf("%d", &routers[*count].meshSupport) != 1 || (routers[*count].meshSupport != 0 && routers[*count].meshSupport != 1)) {
        printf("������: ������� 1 - (��) ��� 0 - (���).\n");
        while (getchar() != '\n'); // �������� ������ �����
    }
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� �������� Wi-Fi: ");
    scanf("%s", routers[*count].wifiStandard);
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� �������� �������� ������ Ethernet (����/�): ");
    while (scanf("%d", &routers[*count].ethernetSpeed) != 1) {
        printf("������: ������� ���������� ��������.\n");
        while (getchar() != '\n'); // �������� ������ �����
    }
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� ����� Wi-Fi: ");
    scanf("%s", routers[*count].wifiClass);
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� �������� �������� ����������� (dBm): ");
    while (scanf("%f", &routers[*count].transmitterPower) != 1) {
        printf("������: ������� ���������� ��������.\n");
        while (getchar() != '\n'); // �������� ������ �����
    }
    while (getchar() != '\n'); // �������� ������ �����

    printf("������� ������������ �������� ������������� ���������� (����/�): ");
    while (scanf("%d", &routers[*count].maxWirelessSpeed) != 1) {
        printf("������: ������� ���������� ��������.\n");
        while (getchar() != '\n'); // �������� ������ �����
    }
    while (getchar() != '\n'); // �������� ������ �����

    (*count)++;

    return 1;
}

bool isInteger(const char* str) {
    if (*str == '\0') return false; // ������ ������ � �� �����

    // �������� ������� ������� ������
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return false; // ���� ������ �� �����, ���������� false
        }
        str++;
    }

    return true; // ��� ������� � �����
}

int getValidInteger(const char* prompt) {
    char input[50];
    int value;

    while (true) {
        printf("%s", prompt);
        scanf("%49s", input); // ��������� ��� ������

        if (isInteger(input)) {
            sscanf(input, "%d", &value); // �������������� ������ � int
            return value;
        }
        else {
            printf("������: ������������ �������. ������� �����.\n");
        }
    }
}

int searchRouter(const router_t routers[], int count, router_t results[], char* wifiClass, char* wifiStandard, int searchOption) {
    int resultCount = 0;

    for (int i = 0; i < count; i++) {
        int mwifiClass = (searchOption == 1 || searchOption == 3) && strcmp(routers[i].wifiClass, wifiClass) == 0;
        int mwifiStandard = (searchOption == 2 || searchOption == 3) && strcmp(routers[i].wifiStandard, wifiStandard) == 0;

        if (searchOption == 1 && mwifiClass)
            results[resultCount++] = routers[i]; // ���������� ��������� �� ������
        else if (searchOption == 2 && mwifiStandard)
            results[resultCount++] = routers[i];
        else if (searchOption == 3 && mwifiClass && mwifiStandard)
            results[resultCount++] = routers[i];
    }

    return resultCount;// ������� ���������� ��������� ������� ����� ���������
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
                // ���������� �� ������������� ������ � ���� ����������
                if (routers[j].dualBandOperation < routers[j + 1].dualBandOperation) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 2) {
                // ���������� �� ��������� Wi-Fi
                if (strcmp(routers[j].wifiStandard, routers[j + 1].wifiStandard) > 0) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 3) {
                // ���������� �� ����� ���������
                if (routers[j].dualBandOperation < routers[j + 1].dualBandOperation ||
                    (routers[j].dualBandOperation == routers[j + 1].dualBandOperation &&
                        strcmp(routers[j].wifiStandard, routers[j + 1].wifiStandard) > 0)) {
                    swapNeeded = 1;
                }
            }

            // ����� ���������
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
            printf("�������������� ������ ��� ������������� %s\n", manufacturer);

            int choice;
            do {
                printf("\n�������� ���� ��� ���������:\n");
                printf("1. ��� �������\n");
                printf("2. ������ ������\n");
                printf("3. ������� ������ ����������� (���)\n");
                printf("4. ������������� ������ � ���� ���������� (1 - ��, 0 - ���)\n");
                printf("5. ���������� ������ Ethernet\n");
                printf("6. ��������� MESH (1 - ��, 0 - ���)\n");
                printf("7. �������� Wi-Fi\n");
                printf("8. �������� �������� ������ Ethernet (����/�)\n");
                printf("9. ����� Wi-Fi\n");
                printf("10. �������� �������� ����������� (dBm)\n");
                printf("11. ������������ �������� ������������� ���������� (����/�)\n");
                printf("0. �����\n");
                printf("��� �����: ");
                scanf("%d", &choice);
                while (getchar() != '\n'); // �������� ������ �����

                switch (choice) {
                case 1:
                    printf("������� ����� ��� �������: ");
                    scanf("%s", routers[i].antennaType);
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 2:
                    printf("������� ����� ������ ������: ");
                    scanf("%s", routers[i].operatingModes);
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 3:
                    printf("������� ����� ������� ������ ����������� (���): ");
                    while (scanf("%f", &routers[i].transmitterFrequency) != 1) {
                        printf("������: ������� ���������� ��������.\n");
                        while (getchar() != '\n'); // �������� ������ �����
                    }
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 4:
                    printf("������������� ������ � ���� ���������� (1 - ��, 0 - ���): ");
                    while (scanf("%d", &routers[i].dualBandOperation) != 1 || (routers[i].dualBandOperation != 0 && routers[i].dualBandOperation != 1)) {
                        printf("������: ������� 1 - (��) ��� 0 - (���).\n");
                        while (getchar() != '\n'); // �������� ������ �����
                    }
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 5:
                    printf("������� ����� ���������� ������ Ethernet: ");
                    while (scanf("%d", &routers[i].ethernetPorts) != 1) {
                        printf("������: ������� ���������� ��������.\n");
                        while (getchar() != '\n'); // �������� ������ �����
                    }
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 6:
                    printf("��������� MESH (1 - ��, 0 - ���): ");
                    while (scanf("%d", &routers[i].meshSupport) != 1 || (routers[i].meshSupport != 0 && routers[i].meshSupport != 1)) {
                        printf("������: ������� 1 - (��) ��� 0 - (���).\n");
                        while (getchar() != '\n'); // �������� ������ �����
                    }
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 7:
                    printf("������� ����� �������� Wi-Fi: ");
                    scanf("%s", routers[i].wifiStandard);
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 8:
                    printf("������� ����� �������� �������� ������ Ethernet (����/�): ");
                    while (scanf("%d", &routers[i].ethernetSpeed) != 1) {
                        printf("������: ������� ���������� ��������.\n");
                        while (getchar() != '\n'); // �������� ������ �����
                    }
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 9:
                    printf("������� ����� ����� Wi-Fi: ");
                    scanf("%s", routers[i].wifiClass);
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 10:
                    printf("������� ����� �������� �������� ����������� (dBm): ");
                    while (scanf("%f", &routers[i].transmitterPower) != 1) {
                        printf("������: ������� ���������� ��������.\n");
                        while (getchar() != '\n'); // �������� ������ �����
                    }
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 11:
                    printf("������� ����� ������������ �������� ������������� ���������� (����/�): ");
                    while (scanf("%d", &routers[i].maxWirelessSpeed) != 1) {
                        printf("������: ������� ���������� ��������.\n");
                        while (getchar() != '\n'); // �������� ������ �����
                    }
                    while (getchar() != '\n'); // �������� ������ �����
                    break;
                case 0:
                    printf("����� �� ������ ��������������.\n");
                    break;
                default:
                    printf("�������� �����. ���������� �����.\n");
                }

                if (choice != 0) {
                    return 1;
                }
            } while (choice != 0);

            return 0;
        }
    }
    if (!found) {
        printf("������ �� �������.\n");
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
    // ����� ������� ��� �������� ������
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
        printf("����:\n");
        printf("1. �������� ����� ������\n");
        printf("2. ����� ������ �� ������ Wi-Fi ��� ��������� Wi-Fi\n");
        printf("3. ��������� ������ � ����\n");
        printf("4. ��������� ������ �� �����\n");
        printf("5. �������� ��� ������\n");
        printf("6. �������� ������ �� �������������\n");
        printf("7. ����������� ������\n");
        printf("8. �������� ������\n");
        printf("0. �����\n");
        printf("�������� �����: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // �������� ������ �����

        switch (choice) {
        case 1: {
            printf("������� ������� ��������?\n");
            scanf("%d", &cnt);
            while (getchar() != '\n'); // �������� ������ �����
            for (int i = 0; i < cnt; i++) {
                printf("������ %d\n", i + 1);
                int result1 = addRouter(routers, &count);
                if (result1 == 1) {
                    printf("\n������ ���������.\n");
                }
                else
                    printf("\n������ ���������� ������\n");
            }
            printf("���� �������.\n");
            saveToTextFile(routers, count, filename);
            break;
        }
        case 2: {
            int searchOption;
            printf("�������� ������� ������:\n1. �� ������ Wi-Fi\n2. �� ��������� Wi-Fi\n3. �� ������ Wi-Fi � ��������� Wi-Fi\n");
            scanf("%d", &searchOption);
            while (getchar() != '\n'); // �������� ������ �����

            char wifiClass[20];
            char wifiStandard[20];

            if (searchOption == 1 || searchOption == 3) {
                printf("������� ����� Wi-Fi: ");
                scanf("%19s", wifiClass);
                while (getchar() != '\n'); // �������� ������ �����
            }

            if (searchOption == 2 || searchOption == 3) {
                printf("������� �������� Wi-Fi: ");
                scanf("%19s", wifiStandard);
                while (getchar() != '\n'); // �������� ������ �����
            }
            router_t results[MAX_ROUTERS];
            int foundCount = searchRouter(routers, count, results, wifiClass, wifiStandard, searchOption);

            if (foundCount > 0) {
                printf("������� %d �������:\n", foundCount);
                for (int i = 0; i < foundCount; i++) {
                    printf("�������������: %s, ������������� ������ � ���� ����������: %d, �������� Wi-Fi: %s, ����� Wi-Fi: %s\n", results[i].manufacturer, results[i].dualBandOperation, results[i].wifiStandard, results[i].wifiClass);
                }
            }
            else {
                printf("������ �� �������.\n");
            }

            break;
        }
        case 3: {
            int result3 = saveToTextFile(routers, count, filename);
            if (result3 == 1)
                printf("\n������ ������� ��������� � ��������� ����.\n");
            else if (result3 == 2)
                printf("������: ���������� ������� ���� ��� ������.\n");
            else
                printf("\n������ ���������� ������\n");
            break;
        }
        case 4: {
            int result4 = loadFromTextFile(routers, &count, filename);
            if (result4 == 1)
                printf("\n������ ������� ��������� �� ���������� �����.\n");
            else if (result4 == 2)
                printf("\n���������� ������������ ���������� �������.\n");
            else
                printf("\n������ ���������� ������\n");

            break;
        }
        case 5:
            for (int i = 0; i < count; i++) {
                printf("�������������: %s, ��� �������: %s, ������ ������: %s, ������� ������ �����������: %f ���, ������������� ������ � ���� ����������: %s, ���������� ������ Ethernet: %d, ��������� MESH: %s, �������� Wi-Fi: %s, �������� �������� ������ Ethernet: %d ����/�, ����� Wi-Fi: %s, �������� �������� �����������: %f dBm, ������������ �������� ������������� ����������: %d ����/�\n",
                    routers[i].manufacturer,
                    routers[i].antennaType,
                    routers[i].operatingModes,
                    routers[i].transmitterFrequency,
                    (routers[i].dualBandOperation ? "��" : "���"),
                    routers[i].ethernetPorts,
                    (routers[i].meshSupport ? "��" : "���"),
                    routers[i].wifiStandard,
                    routers[i].ethernetSpeed,
                    routers[i].wifiClass,
                    routers[i].transmitterPower,
                    routers[i].maxWirelessSpeed);
            }
            break;
        case 6: {
            char manufacturer[50];
            printf("������� ������������� ��� ��������������: ");
            scanf("%s", manufacturer);
            while (getchar() != '\n'); // �������� ������ �����
            int result6 = editRouter(routers, count, manufacturer);
            if (result6 == 1) {
                printf("���� ������� ��������� � ���������.\n");
                saveToTextFile(routers, count, filename);
            }
            else
                printf("\n������ ���������� ����\n");
            break;
        }
        case 7: {
            printf("�������� �������� ����������:\n1. ������������� ������ � ���� ���������� \n2. �������� Wi-Fi \n3. �� ����� ���������\n");
            scanf("%d", &sortCr);
            while (getchar() != '\n'); // �������� ������ �����

            int result7 = bubbleSort(routers, count, sortCr);
            if (result7 == 1) {
                printf("������ ����� ����������:\n");
                for (int i = 0; i < count; i++) {
                    printf("�������������: %s, ������������� ������ � ���� ����������: %s, �������� Wi-Fi: %s\n", routers[i].manufacturer, (routers[i].dualBandOperation ? "��" : "���"), routers[i].wifiStandard);
                }
            }
            break;
        }
        case 8:
        {
            char manufacturer[50];
            printf("������� ������������� ��� ��������: ");
            scanf("%49s", manufacturer);
            while (getchar() != '\n'); // �������� ������ �����

            int result = deleteRouter(routers, &count, manufacturer);

            if (result == 1) {
                printf("������ ������� ������� � ���� ��������.\n");
                saveToTextFile(routers, count, filename);
            }
            else {
                printf("������ � ��������� �������������� �� �������.\n");
            }

            break;
        }
        case 0:
            printf("����� �� ���������.\n");
            break;
        default:
            printf("�������� �����.\n");
        }
    } while (choice != 0);
}