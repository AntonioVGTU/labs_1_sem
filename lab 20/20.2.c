#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
char** split_words(const char* str, int* count) {
    int capacity = 10;
    char** words = (char**)malloc(capacity * sizeof(char*));
    *count = 0;

    const char* ptr = str;
    while (*ptr) {
        while (*ptr && isspace((unsigned char)*ptr)) ptr++;
        if (!*ptr) break;

        const char* start = ptr;
        while (*ptr && !isspace((unsigned char)*ptr)) ptr++;

        int len = ptr - start;
        words[*count] = (char*)malloc((len + 1) * sizeof(char));
        strncpy(words[*count], start, len);
        words[*count][len] = '\0';
        (*count)++;

        if (*count >= capacity) {
            capacity *= 2;
            words = (char**)realloc(words, capacity * sizeof(char*));
        }
    }

    return words;
}
void transform_line(const char* line, char* transformed) {
    int count;
    char** words = split_words(line, &count);

    if (count < 2) {
        strcpy(transformed, line);
    }
    else {
        strcpy(transformed, words[count - 1]);
        for (int i = 1; i < count - 1; i++) {
            strcat(transformed, " ");
            strcat(transformed, words[i]);
        }
        strcat(transformed, " ");
        strcat(transformed, words[0]);
    }

    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
}

int main() {
    setlocale(LC_ALL, "Russian");

    char input_filename[] = "winter.txt";
    char output_filename[100];
    FILE* in, * out;

    printf("Введите имя выходного файла: ");
    scanf("%99s", output_filename);
    if ((in = fopen(input_filename, "r")) == NULL) {
        perror("Ошибка открытия файла для чтения");
        return 1;
    }
    if ((out = fopen(output_filename, "w")) == NULL) {
        perror("Ошибка открытия файла для записи");
        fclose(in);
        return 1;
    }

    char line[256];
    char transformed[512];

    while (fgets(line, sizeof(line), in)) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        transform_line(line, transformed);
        fprintf(out, "%s\n", transformed);
    }

    fclose(in);
    fclose(out);

    printf("Преобразование завершено. Результат записан в файл: %s\n", output_filename);

    return 0;
}