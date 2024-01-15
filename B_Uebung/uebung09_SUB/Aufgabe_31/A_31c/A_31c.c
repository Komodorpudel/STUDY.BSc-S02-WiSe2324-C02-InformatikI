#include <stdio.h>

int read_probability(double *probability)
{

    double in;
    int c;

    if (probability == NULL) {
        return -1;
    }

    printf("Gleitkommazahl eingeben:");

    /* Ungültige Eingabe */
    if (scanf("%lf", &in) != 1 || in < 0.0 || in > 1.0) {

        /* Puffer Leeren */
        while ((c = getchar()) != '\n' && c != EOF);

        return 1;
    }

    else {
        *probability = in;
        return 0;
    }

}

int main(void)
{

    double prob;
    int result;

    result = read_probability(&prob);
    if (result == 0) {
        printf("Gültige Eingabe: %lf\n", prob);
    }
    
    else if (result == -1) {
        printf("Ungültiger Pointer übergeben.\n");
    }
    
    else {
        printf("Ungültige Eingabe.\n");
    }
    return 0;
}
