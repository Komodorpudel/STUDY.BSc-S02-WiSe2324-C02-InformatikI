#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_STRING 1
#define MAX_STRING 100

#define SUCCESS 0
#define ERROR_INVALID_NUMBER -1
#define ERROR_INVALID_STRING -2
#define ERROR_BUFFER_OVERFLOW -3

/* --------------------------------------------- */

/* einfach mit toupper jeden buchstaben bearbeiten. Da ich mit char str[] ein Zeiger auf das Array bekomme, kann ich bequem alles in Funktion bearbeiten */

void some_upper(int i, char str[])
{
    int j;
    int len = strlen(str);
    for (j = 0; j < len; j++) {
        if (j % i == 0) {
            str[j] = toupper(str[j]);
        }
    }
}

/* --------------------------------------------- */

int read_and_change(void)
{
    int i;
    int ch;
    int index = 0;
    char str[MAX_STRING + 1];

    /* Einlesen der Zahl: */
    printf("Zahl:\n");

    /* Wenn scanf was anderes als genau eine Variable holt oder wenn die eingegebene Zahl negativ ist */
    if (scanf("%d", &i) != 1 || i <= 0) { 
        while ((ch = getchar()) != '\n' && ch != EOF);  /* Eingabepuffer leeren */
        return ERROR_INVALID_NUMBER;
    }

    /* Überspringen der restlichen Zeichen in der Eingabezeile (inklusive Newline) */
    while ((ch = getchar()) != '\n' && ch != EOF);

    /* Einlesen der Zeichenkette */
    printf("String:\n");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (index >= MAX_STRING) {
            while ((ch = getchar()) != '\n' && ch != EOF);  /* Eingabepuffer leeren */
            return ERROR_BUFFER_OVERFLOW;
        }
        if (!islower(ch)) {
            while ((ch = getchar()) != '\n' && ch != EOF);  /* Eingabepuffer leeren */
            return ERROR_INVALID_STRING;
        }

        /* Eingelesen char in str array abspeichern */
        str[index++] = (char) ch;
    }

    /* Terminierer */
    str[index] = '\0';

    /* Prüfen, ob die Zeichenkette die Mindestlänge hat */
    if (strlen(str) < MIN_STRING) {
        return ERROR_INVALID_STRING;
    }

    /* Anwendung der some_upper-Funktion und Ausgabe */
    some_upper(i, str);
    printf("%s\n", str);
    return SUCCESS;
}


/* --------------------------------------------- */

int main(void)
{
    int result = read_and_change();

    switch (result) {
        case SUCCESS:
            printf("Operation successful.\n");
            break;
        case ERROR_INVALID_NUMBER:
            printf("Invalid number entered.\n");
            break;
        case ERROR_INVALID_STRING:
            printf("Invalid string entered.\n");
            break;
        case ERROR_BUFFER_OVERFLOW:
            printf("String length out of bounds.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
    }

    return result;
}

/* --------------------------------------------- */
