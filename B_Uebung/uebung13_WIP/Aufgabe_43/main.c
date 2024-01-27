#include <stdio.h>



/* ------------------------------ */
/* Test ob v ein Präfix von w ist */
int vergleicheStrings(const char *v, const char *w)
{
    int k = 1; /* Initialisiere k als 1 (wahr) */
    int i;
    
    /* Gehe durch beide Strings */
    for (i = 0; v[i] != '\0'; i++) {
        if (w[i] == '\0' || v[i] != w[i]) {
            k = 0; /* Setze k auf 0, wenn ein Unterschied gefunden wird oder w endet, bevor v endet */
            break;
        }
    }

    return k;
}

/* ------------------------------ */

int main()
{
    char v[] = "Test";
    char w[] = "TestString";

    int ergebnis = vergleicheStrings(v, w);
    printf("Ergebnis: %d\n", ergebnis);

    return 0;
}
