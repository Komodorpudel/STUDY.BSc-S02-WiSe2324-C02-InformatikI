#include <stdio.h>

int read_probability (double *probability)
{

    int status;

    if (probability == NULL){
        return -1;
    }
    
    printf("Zahl eingeben:\n");

    status = scanf("%lf", probability);

    if (status != 1 || *probability > 1 || *probability < 0){

        while(getchar() != '\n'){}

        return 1; /* Weil Fehler */
    }

    while(getchar() != '\n'){}
    return 0;

}


int main(void)
{
    double probability;

    printf("Geben Sie Wkeit zwischen 0 und 1 ein\n");

    if(read_probability(&probability) == 1){
        printf("Ungültige Eingabe\n");
        return -1;
    }

    printf("Gültige Eingabe! Eingabe war: %f\n", probability);
    return 0;
    
}
