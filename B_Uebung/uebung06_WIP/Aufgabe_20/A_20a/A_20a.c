#include <stdio.h>
#include <string.h>

void string_ncat(char v[], char w[], int n) {
    int i = 0;
    int j;

    /* Annahme: n ist die länge, die sicher angehängt werden kann */

    /* Finde das Ende von v */
    while (v[i] != '\0') {
        i++;
    }

    /* Füge Zeichen von w hinzu, aber nicht mehr als n und nicht mehr als die Gesamtlönge von v */
    for (j = 0; j < n && w[j] != '\0'; j++) {
        v[i + j] = w[j];
    }

    /* Nullzeichen hinzufügen, um die Zeichenkette korrekt abzuschließen */
    v[i + j] = '\0';
}

int main(void) {

    char str1[50] = "Hallo ";
    char str2[] = "Welt!";
    char str3[] = "";

    char str4[10] = "Test";
    char str5[] = "Dies ist zu lang";

    char str10[50] = "Hallo ";
    char str11[] = "Welt!";
    char str12[] = "";
    
    char str13[10] = "Test";
    char str14[] = "Dies ist zu lang";

    /* normalen Zeichenketten */
    string_ncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
    printf("Ergebnis 1: %s\n", str1);

    /* leeren Zeichenkette */
    string_ncat(str1, str3, sizeof(str1) - strlen(str1) - 1);
    printf("Ergebnis 2: %s\n", str1);

    /* langen Zeichenkette */
    string_ncat(str4, str5, sizeof(str4) - strlen(str4) - 1);
    printf("Ergebnis 3: %s\n", str4);

    /* strncat */
    strncat(str13, str14, sizeof(str13) - strlen(str13) - 1);
    printf ("Eregbis 4 - strncat: %s\n", str13);

    return 0;
}
