#include <stdio.h> /* z.B. printf und sprintf */
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LEN 10

#define EURO "EUR"
#define DOLLAR "DOLLAR"
#define NORWEGIAN "NK"
#define YEN "YEN"

#define EUR 1
#define USD 2
#define NOK 3
#define JPY 4

/* ------------------------------------------ */

int represents_float(char* input) /* Alternativ char input[] -> Macht eig klarar was kommt */
{

    float value;
    char converted_value[MAX_STRING_LEN + 1];

    /* prüfen ob Zeichenkette maximal 10 Zeichen hat */
    if(strlen(input) > MAX_STRING_LEN){
        return 0;
    }

    /* Mit atoF umwandeln */
    value = atof(input);

    /* Mit sprintf in Zeichenkette konvertieren und in converted value speichern*/
    sprintf(converted_value, "%.2f", value); /* Achtung, die Funktion will einne Zeiger haben, also muss ich die Adresse des ersten Elements übergeben, wenn ich aber converted_value[] mache, dann übergebe ich einen Zeiger */

    if(strcmp(converted_value, input) != 0){
        return 0;
    }

    return 1;

}

/* ------------------------------------------ */

int is_supported_currency(char* input)
{
    if (strcmp(input, EURO) == 0){
        return EUR;
    }
    else if (strcmp(input, DOLLAR) == 0){
        return USD;
    }
    else if (strcmp(input, NORWEGIAN) == 0){
        return NOK;
    }
    else if (strcmp(input, YEN) == 0){
        return JPY;
    }
    else{
        return 0;
    }
}

/* ------------------------------------------ */

float convert_currency(float amount, char* from, char* to)
{

    /* Entspricht nicht aufgabenstellung, aber geht schneller */

        float conversion_rates[4][4] = {
        {1.0, 1.07, 11.95, 161.51},
        {0.94, 1.0, 11.18, 151.16},
        {0.084, 0.089, 1.0, 13.52},
        {0.0062, 0.0066, 0.074, 1.0}
        };

        int from_currency = is_supported_currency(from);
        int to_currency = is_supported_currency(to);
        

        if (from_currency == 0 || to_currency  == 0){
            return 0.0;
        }

        return amount * conversion_rates[from_currency - 1][to_currency - 1];


}

/* ------------------------------------------ */

int main(int argc, char* argv[])
{

    float amount;
    if (argc != 4){
        printf("Fehlermeldung!\n");

        return 1; /* 1 für Fehler */
    }

    if (represents_float(argv[1]) != 1){

        printf("%s ist kein Float", argv[1]);

        return 1;

    }

    if(is_supported_currency(argv[2]) == 0|| is_supported_currency(argv[3]) == 0){
        printf("keine gültigen Währungen");
        return 1;
    }

    amount = atof(argv[1]);



    printf("%.2f %s entspricht %.2f %s", amount, argv[2], convert_currency(amount, argv[2], argv[3]), argv[3]);

    return 0;
}

