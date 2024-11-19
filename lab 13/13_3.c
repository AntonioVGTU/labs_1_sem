#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
void find_adjacent_capitalized_words(const char* text) {
    const char* start = text;
    const char* end = text;
    int i = 0;
    int p = 0;
    int c = 0;
    while (*end != '\0') {
        if (isspace((unsigned)*end)) {
            if (i) {
                if (p && c) {
                    printf("Found pair: ");
                    while (start < end) {
                        putchar(*start);
                        start++;
                    }
                    putchar('\n');
                }
                p = c;
                c = 0;
                i = 0;
            }
            start = end + 1;
        }
        else {
            if (!i) {
                i = 1;
                c = isupper((unsigned)*end);
            }
        }
        end++;
    }
    if (i && p && c) {
        printf("Found pair: ");
        while (start < end) {
            putchar(*start);
            start++;
        }
        putchar('\n');
    }
}
int main() {
    setlocale(LC_ALL, "ru");
    char text[1000];
    printf("Enter your text: ");
    fgets(text, sizeof(text), stdin);
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
    find_adjacent_capitalized_words(text);
    return 0;
}