#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define VALID_INPUT 0
#define INVALID_INPUT 1
#define grid_size 5
#define X 0 /* ----- */
#define Y 1 /* | */

/* Protypen */
int flush_buff(void);
int read_string(char in[], int max_len);
void spielzug_machen (void);
void darstellung (void);

/* Globale Variablen */
int pos_apfel [2]; /* Position Apfel */
int pos_roboter [2]; /* Position Roboter */
char input [6];

/* -------------------------------------------- */

int main (void) {

    int count = 0;

    /* Positionen initialissieren */
    /* Roboter */
    pos_roboter[X] = 5;
    pos_roboter[Y] = 1;
    srand(time(NULL));

    do {
        pos_apfel[X] = 1 + rand() % 5 ;
        pos_apfel[Y] = 1 + rand() % 5;
    }
    while (pos_roboter[X] == pos_apfel[X] && pos_roboter[Y] == pos_apfel[Y]);


    /* Schritte einlesen solange bis am Ziel*/
    while (pos_roboter[X] != pos_apfel[X] || pos_roboter[Y] != pos_apfel[Y]) {
        darstellung();
        printf("Nächster Schritt:\n");
        read_string(input, 6);
        spielzug_machen();
        count++;
    }
    printf("Schritte gemacht:%i", count);

    return 0;

}

/* -------------------------------------------- */

int read_string(char in[], int max_len)
{
    int i = 0;
    char c = getchar();
    while (c != '\n' && i < max_len - 1) {
        in[i++] = c;
        c = getchar();
    }

    if (i == max_len - 1 && c != '\n') {
        flush_buff();
        return INVALID_INPUT;
    }
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

void spielzug_machen (void) {

    /* HOCH */
    if (strncmp (input, "HO", 2) == 0) {
        if (pos_roboter[Y] == 1) {
            pos_roboter[Y] = grid_size;
        }

        else {
            pos_roboter[Y] = pos_roboter[Y] - 1;
        }
        
    }

    /* RUNTER */
    else if (strncmp (input, "RU", 2) == 0) {
        if (pos_roboter[Y] == grid_size) {
            pos_roboter[Y] = 1;
        }

        else {
            pos_roboter[Y] = pos_roboter[Y] + 1;
        }
    
    }

    /* Rechts */
    else if (strncmp (input, "RE", 2) == 0) {
        if (pos_roboter[X] == grid_size) {
            pos_roboter[X] = 1;
        }

        else {
            pos_roboter[X] = pos_roboter[X] + 1;
        }
    
    }

    /* LINKS */
    else if (strncmp (input, "LI", 2) == 0) {
        if (pos_roboter[X] == 1) {
            pos_roboter[X] = grid_size;
        }

        else {
            pos_roboter[X] = pos_roboter[X] - 1;
        }
    }

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
