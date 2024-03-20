#include <stdio.h>
#include <string.h> /* Für strcmp */

#define MAX 30 /* Wenn ich char Array der länge 30 mache, ist das letzte Zweichen für den nullterminierer, also habe ich Platz für 29 Zeichen */
#define MIN 3
#define ERROR 0
#define SUCCESS 1




/* --------------------------------------------- */
/* Hilfsfunktion flush() */
void flush_buffer(void)
{
    while(getchar() != '\n') /* "\n" ist String, während '\n’ einzelnes zeichen */
    {
        /* Wir leeren Buffer bis wir "Enter" bekommen */
    }; 
}

/* --------------------------------------------- */

int read_string(char input[])
{

    int i = 0;
    int character;
    /* Am besten getchar verwenden, da wir ja auf eine Länge von 30 limitiert sind. Mit scanf geht das zwar auch (scanf("30s", input)) aber ich weiß dann nicht, ob noch was im puffer ist*/

    while (i <= MAX){ /* Höchstens 30 Zeichen sollen eingelesen werden */
        character = getchar();
        if(character == '\n' ){
            break;
        }
        input[i] = character;
        i++; /* Nach erfolgreicher Einlesung ticken wir eins hoch. Nach Eintrag bei i=1  sind wir also hier auf.
        3 Chars haben wir übertragen, wenn i bei 3 steht */
    }

    if (i > MAX){ /* Letztes Zeichen war nicht '\n */
        flush_buffer(); /* Puffer leeren */
        return ERROR;
    }

    else if ( i < MIN){ /* Wenn wir also max i=1 eingelesen haben */
        return ERROR;
    } 

    else { /* Else nicht notwendig */
        input[i] = '\0'; /* Nullterminierer */
        return SUCCESS;
    }
    
}

/* --------------------------------------------- */

int count_string(char w[], char c){
    
    int counter = 0;
    int i = 0;

    while (w[i] != '\0') {
        if(w[i] == c){
            counter++;
        }
        i++;
    }
    return counter;

}

/* --------------------------------------------- */

int main(void)
{
    char eingabe[MAX +1];
    int status;

    printf("Hallo, ich bin das Program\n");

    while(1){
        printf("Gib eine Zeichenkette mit Länge 3 bis 30 ein:\n");
        status = read_string(eingabe);

        if (status == 1) {

            printf("Eingabe gültig\n");

            if(strcmp(eingabe, "exit") == 0) {
                printf("Program wird beendet\n");
                return 0;
            }
            else {
                printf("Anzahl %c: %i\n", '?', count_string(eingabe, '?'));
                printf("Anzahl %c: %i\n", '!', count_string(eingabe, '!'));

            }

        }  
    }

}

/* --------------------------------------------- */
