#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EUR 1
#define USD 2
#define NOK 3
#define JPY 4

/* ----------------------------------- */

int is_valid_float(const char *str) /* z.B. 12.36 oder 12.3717 */
{ 
    int i = 0;

    /* Ich konvertiere Vorzeichen, Digits, und dezimal points zu einer float */
    float num = atof(str);

    char formatted[11];

    /* string print formatted */
    /* An Position des decimal points steht dann eine "." im Array */
    sprintf(formatted, "%.2f", num);

    /* test */
    printf("So wird die float im array gespeichert:\n");
    for (; i < 11; i++) {
        printf("%c",formatted[i]);
        printf(" ,");
    }
    printf("\n");

    /* Ich vergleiche. Wenn identisch, dann kommt 1 zurück */
    return strcmp(formatted, str) == 0 ? 1 : 0;
}

/* ----------------------------------- */

int get_currency(const char *currency)
{
    if (strcmp(currency, "EUR") == 0) return EUR;
    if (strcmp(currency, "USD") == 0) return USD;
    if (strcmp(currency, "NOK") == 0) return NOK;
    if (strcmp(currency, "JPY") == 0) return JPY;

    return 0;
}

/* ----------------------------------- */

float convert_currency(float amount, char* from, char* to) 
{

    float conversion_rates[4][4] = {
        {1.0, 1.07, 11.95, 161.51},
        {0.94, 1.0, 11.18, 151.16},
        {0.084, 0.089, 1.0, 13.52},
        {0.0062, 0.0066, 0.074, 1.0}
    };

    int from_currency = get_currency(from);
    int to_currency = get_currency(to);

    if (!from_currency || !to_currency) {
        /* Wenn einer der Werte 0 ist weil Währung nicht existiert, dann returnen wir 0.0 */
        return 0.0;
    }



    return amount * conversion_rates[from_currency - 1][to_currency - 1];
}

/* ----------------------------------- */

int main(int argc, char *argv[])
{

    float amount;
    float converted;

    if (argc != 4) {
        printf("Fehler: Ungültige Anzahl an Argumenten.\n");
        printf("Benutzung: <Betrag> <Start-Währung> <Ziel-Währung>\n");
        return 1;
    }

    if (!is_valid_float(argv[1])) {
        printf("Fehler: Ungültiger Betrag.\n");
        return 1;
    }

    if (!get_currency(argv[2]) || !get_currency(argv[3])) {
        /* Wenn eine der beiden Currencies 0 ist, dann werden sie nicht unterstützt */
        printf("Fehler: Eine oder beide angegebenen Währungen werden nicht unterstützt.\n");
        return 1;
    }

    /* to float convertieren */
    amount = atof(argv[1]);

    /* amount dann umrechnen from to */
    converted = convert_currency(amount, argv[2], argv[3]);

    printf("%.2f %s entsprechen %.2f %s.\n", amount, argv[2], converted, argv[3]);
    return 0;
}
