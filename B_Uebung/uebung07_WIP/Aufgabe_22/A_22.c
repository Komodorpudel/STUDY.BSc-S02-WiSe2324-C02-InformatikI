#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX_LENGTH 100

/* ----------------------------------- */

int is_palindrome(char v[])
{
    int len = strlen(v);
    int i;

    for (i = 0; i < len / 2; ++i) { /* Normalerweise irrelevant ob ++i oder i++ in for loop deklaration */
        
        if (v[i] != v[(len -1) - i]) {
            return FALSE;
        }

    }
    return TRUE;
}

/* ----------------------------------- */

int string_reverse(char v[], char w[], int len_w) {

    /* Länge von v bestimmen */
    int len_v = strlen(v);

    int i;

    /* Wenn v zu kurz ist, dann return FALSE */
    if (len_v > len_w) {
        return FALSE;
    }

    /* Durch Loopen */
    for (i = 0; i < len_v; ++i) {

        /*  */
        w[i] = v[(len_v - 1) - i];
    }

    w[len_v] = '\0'; // Nullterminierung
    return TRUE;
}

/* ----------------------------------- */

int main(int argc, char *argv[]) {

    int i;

    /* Wenn kein Param übergeben, dann 0 */

    if (argc < 2) {
        printf("Fehler: Keine Parameter übergeben.\n");
        return 1;
    }

    for (i = 1; i < argc; ++i) {

        char *param = argv[i];

        if (is_palindrome(param)) {
            printf("%s ist ein Palindrom.\n", param);
        }
        
        else {
            int len = strlen(param);
            if (len <= MAX_LENGTH / 2) {
                char palindrome[MAX_LENGTH + 1];
                strcpy(palindrome, param);

                char reversed[MAX_LENGTH / 2 + 1];
                if (string_reverse(param, reversed, MAX_LENGTH / 2)) {
                    strcat(palindrome, reversed);
                    printf("Original: %s, Kombiniert: %s\n", param, palindrome);
                }
            }
            
            else {
                printf("%s ist kein Palindrom und zu lang.\n", param);
            }
        }
    }

    return 0;
}
