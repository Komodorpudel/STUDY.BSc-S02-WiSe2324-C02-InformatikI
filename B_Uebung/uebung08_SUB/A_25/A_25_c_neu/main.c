#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 20

#define NON_POSITIVE_INPUT -1
#define UNEXPECTED_EOF -2
#define NUMBER_TOO_BIG -3

#define MIN_LINES 10

void flush(void){
    char c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

int read_number_in_line(void)
{
    char number_as_string[MAX_LEN + 1]; /* Darin speichern wir String */
    char current_char; /* Darin speichern wir current char */
    int i = 0; 
    int result; /* Darin speichern wir Result von atoi */

    /* Einlesen von Console */
    printf("Zahl eingeben und Enter:\n");
    while ((current_char = getchar()) != '\n' && i < MAX_LEN){
        if(current_char == EOF){ /* EOF ist Konstante die in stdio.h definiert wird */
            return UNEXPECTED_EOF;
        }

        number_as_string[i] = current_char;
        i++;
    }
    /* Fertig eingelesen */

    /* Check - Zahl zu groß */
    if(current_char != '\n') {
        flush();
        return NUMBER_TOO_BIG;
    }

    number_as_string[i] = '\0'; /* Terminierer setzen */
    result = atoi(number_as_string); 

    /* Check - Zahl negativ */
    if (result < 0) {
        return NON_POSITIVE_INPUT;
    }

    return result;

}

int main(void)
{
    int i;
    int current_number;
    int previous_number;


    for (i = 0; i < MIN_LINES; i++){
        current_number = read_number_in_line();

        /* Fehlerüberprüfung */
        if (current_number == NON_POSITIVE_INPUT){
            printf("Fehler: Zahl ist negativ\n");
            return 1;
        }
        else if (current_number == UNEXPECTED_EOF){
            printf("Fehler: Eingabefehler (EOF)\n");
            return 1;
        }
        else if (current_number == NUMBER_TOO_BIG){
            printf("Fehler: Eingabe zu lang\n");
        }


        /* Vorherige und aktuelle Zahl checken */
        if(i < 1){
            previous_number = current_number;
        }
        else {
            if (current_number != previous_number + 1){
                printf("Nummern sind nicht fortlaufend\n");
                printf("Current_number: %i, previous_number: %i\n", current_number, previous_number);

                return 1;
            }
            else {
                previous_number = current_number;
            }

        }
    }
    printf("Alle Zahlen sind aufeinanderfolgenden!\n");

    return 0;
}


