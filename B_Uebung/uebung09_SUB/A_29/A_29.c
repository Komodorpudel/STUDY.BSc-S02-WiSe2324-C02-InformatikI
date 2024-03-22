#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Konstanten */
#define VALID_INPUT 0
#define INPUT_TOO_LONG 1
#define INPUT_ERROR 2

#define grid_size 5
#define X 0 /* ----- */
#define Y 1 /* | */

/* Protypen */
int flush_buff(void);
int read_string(char in[], int max_len);
int spielzug_machen (void);
void darstellung (void);

/* Globale Variablen */
int pos_apfel [2]; /* Position Apfel */
int pos_roboter [2]; /* Position Roboter */


/* -------------------------------------------- */
int main (void) {

    int count = 0;
    int status;

    /* Positionen initialisieren */
    /* Roboter */
    pos_roboter[X] = 5;
    pos_roboter[Y] = 1;
    srand(time(NULL));

    /* Roboter und Apfel zufällig positionieren */
    do {
        pos_apfel[X] = 1 + rand() % 5 ;
        pos_apfel[Y] = 1 + rand() % 5;
    }
    while (pos_roboter[X] == pos_apfel[X] && pos_roboter[Y] == pos_apfel[Y]);

    /* Anweisung */
    printf("Du bist Roboter r, laufe zum Apfel a\n");

    /* Schritte einlesen solange bis am Ziel*/
    while (pos_roboter[X] != pos_apfel[X] || pos_roboter[Y] != pos_apfel[Y]) {
        darstellung();
        status = spielzug_machen();

        if (status == INPUT_ERROR) {
            printf("EOF erreicht.\n");
            break;
        }
        count++;
    }
    printf("Schritte gemacht:%i", count);

    return 0;

}


/* -------------------------------------------- */
int read_string(char in[], int max_len)
{
    int i = 0;
    char c;

    /* in[] mit Daten aus Buffer befüllen */
    while ((c = getchar()) != '\n' && c != EOF && i < max_len - 1) {
    /* Ich schreib bis Ende oder max_len */
        in[i++] = c;
    }

    /* Wenn ich bei max_len von in[] angekommen bin, aber buffer noch nicht leer ist, flushen */
    if (i == max_len - 1 && c != '\n' && c != EOF) { 
        flush_buff();
        return INPUT_TOO_LONG;
    }
    else if (c == EOF){
        return INPUT_ERROR;
    }

    /* Wenn letzter Wert ausgelesen */
    in[i] = '\0'; 
    return VALID_INPUT;
}


/* -------------------------------------------- */
int flush_buff(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return c != EOF;
}


/* -------------------------------------------- */
int spielzug_machen (void) {

    char input [7];
    int status;

    /* Zeichenkette vom Nutzer einlesen */
    printf("Nächster Schritt( \"HOCH\", \"RUNTER\", \"LINKS\", \"RECHTS\"):\n");
    status = read_string(input, 7);

    if (status != 0) {
        
        return status;
    }
    
    /* Eingabe ausführen */
    /* HOCH */
    if (strncmp (input, "HOCH", 2) == 0) {
        if (pos_roboter[Y] == 1) {
            pos_roboter[Y] = grid_size;
        }

        else {
            pos_roboter[Y] = pos_roboter[Y] - 1;
        }
        
    }

    /* RUNTER */
    else if (strncmp (input, "RUNTER", 2) == 0) {
        if (pos_roboter[Y] == grid_size) {
            pos_roboter[Y] = 1;
        }

        else {
            pos_roboter[Y] = pos_roboter[Y] + 1;
        }
    
    }

    /* Rechts */
    else if (strncmp (input, "RECHTS", 2) == 0) {
        if (pos_roboter[X] == grid_size) {
            pos_roboter[X] = 1;
        }

        else {
            pos_roboter[X] = pos_roboter[X] + 1;
        }
    
    }

    /* LINKS */
    else if (strncmp (input, "LINKS", 2) == 0) {
        if (pos_roboter[X] == 1) {
            pos_roboter[X] = grid_size;
        }

        else {
            pos_roboter[X] = pos_roboter[X] - 1;
        }
    }

    return VALID_INPUT;

}


/* -------------------------------------------- */
void darstellung (void) {
    int i = 1;
    int j = 1;

    for (; i <= grid_size; i++) {
        for (j = 1;j <= grid_size; j++) {
            printf("| ");

            if (pos_apfel[X] == j && pos_apfel[Y] == i) {
                printf ("a ");
            }
            else if (pos_roboter[X] == j && pos_roboter[Y] == i) {
                printf("r ");
            }
            else {
                printf("_ ");
            }

        }

        printf("|\n");

    }
}
