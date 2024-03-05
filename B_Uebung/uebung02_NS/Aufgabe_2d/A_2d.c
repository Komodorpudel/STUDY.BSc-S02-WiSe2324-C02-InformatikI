#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_chars(char v[], char w[], int size);
void print(char w[], int size);

/* -------------------------------------------- */

int main(void)
{
    int valid;
    char chars1[] = {'1', '2', 'a', '5'};
    char chars2[] = {'0', '0', '0', '0'};
    char chars3[] = {'3', '4', '5', '6', '7', '8', '9'};
    char neu[7];

    srand(time(NULL));
    valid = random_chars(chars1, neu, 4);

    if (valid) {
        print(neu, 4);
    } else {
        printf("array doesn't only contain digits\n");
    }

    valid = random_chars(chars2, neu, 4);
    
    if (valid) {
        print(neu, 4);
    } else {
        printf("array doesn't only contain digits\n");
    }
        valid = random_chars(chars3, neu, 7);
        if (valid) {
        print(neu, 7);
    } else {
        printf("array doesn't only contain digits\n");
    }
    return 0;
}

/* -------------------------------------------- */

int random_chars(char v[], char w[], int size)
{
    int i;

    /* Überprüfen ob alle Digits sind */
    for (i = 0; i < size; ++i) {
        if (!isdigit(v[i])) {
            return 0;
        }
    }

    for (i = 0; i < size; ++i) {
        w[i] = rand() % (v[i] - '/') + 'A';
    }

return 1;

}

/* -------------------------------------------- */

/* Es ist nicht Teil der Aufgabenstellung, eine separate print-Funktion zu schreiben */
void print(char w[], int size)
{
    int i;
    for (i = 0; i < size; ++i) {
        printf("%c", w[i]);
    }  

    printf("\n");
}

/* -------------------------------------------- */