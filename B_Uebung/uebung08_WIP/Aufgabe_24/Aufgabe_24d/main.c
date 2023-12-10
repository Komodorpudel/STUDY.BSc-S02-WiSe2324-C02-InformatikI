#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define NON_POSITIVE_NUMBER -1
#define BUFFER_ERROR -2
#define MIN_LINES 5

int read_number_in_line()
{
    char buffer[MAX_STRING_LENGTH];
    if (fgets(buffer, MAX_STRING_LENGTH, stdin) == NULL) {
        return BUFFER_ERROR;
    }

    buffer[strcspn(buffer, "\n")] = 0;
    int number = atoi(buffer);
    return number > 0 ? number : NON_POSITIVE_NUMBER;
}

int main()
{
    int previous_number = 0, number, is_first_number = 1;

    for (int i = 0; i < MIN_LINES; i++) {
        printf("Bitte geben Sie eine Zahl ein: ");
        number = read_number_in_line();

        if (number == NON_POSITIVE_NUMBER || number == BUFFER_ERROR) {
            printf("Ein Fehler ist aufgetreten: %s\n", 
                   number == NON_POSITIVE_NUMBER ? "Nicht-positive Zahl" : "Pufferfehler");
            return 1;
        }

        if (!is_first_number && number - previous_number != 1) {
            printf("Die Zahlen sind nicht fortlaufend.\n");
            return 1;
        }

        previous_number = number;
        is_first_number = 0;
    }

    printf("Alle Zahlen sind fortlaufend.\n");
    return 0;
}
