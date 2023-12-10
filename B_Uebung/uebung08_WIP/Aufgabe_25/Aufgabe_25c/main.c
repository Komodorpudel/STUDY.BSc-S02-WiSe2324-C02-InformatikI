#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define NON_POSITIVE_NUMBER -1
#define BUFFER_ERROR -2

int read_number_in_line()
{
    char buffer[MAX_STRING_LENGTH];
    if (fgets(buffer, MAX_STRING_LENGTH, stdin) == NULL) {
        return BUFFER_ERROR;
    }

    // Entfernen eines möglichen Newline-Zeichens am Ende der Eingabe
    buffer[strcspn(buffer, "\n")] = 0;

    int number = atoi(buffer);
    return number > 0 ? number : NON_POSITIVE_NUMBER;
}

int main()
{
    int number;

    printf("Bitte geben Sie eine Zahl ein: ");
    number = read_number_in_line();

    if (number == NON_POSITIVE_NUMBER) {
        printf("Eingegebene Zahl ist nicht positiv.\n");

    }
    
    else if (number == BUFFER_ERROR) {
        printf("Ein Pufferfehler ist aufgetreten.\n");
    }
    
    else {
        printf("Die eingegebene Zahl ist: %d\n", number);
    }

    return 0;
}
