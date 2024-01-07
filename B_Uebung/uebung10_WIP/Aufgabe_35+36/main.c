#include <stdio.h>
#include <stdlib.h>
#include "A_35+36.c"
#include "print-utils.c"

int main(int argc, char *argv[]) {
    int width, height;
    int **field;
    int y;
    int x;

    /* Überprüfung der Anzahl der Kommandozeilenparameter */
    if (argc != 3) {
        fprintf(stderr, "Fehler: Bitte genau zwei Parameter angeben (Breite und Höhe)\n");
        return 1;
    }

    /* Umwandlung der Kommandozeilenparameter in int-Werte */
    width = atoi(argv[1]);
    height = atoi(argv[2]);

    /* Überprüfung der Spielfeldgröße */
    if (width < 3 || height < 3) {
        fprintf(stderr, "Fehler: Breite und Höhe müssen mindestens 3 sein\n");
        return 1;
    }

    /* Speicher für das Spielfeld reservieren */
    field = field_init(width, height);
    if (field == NULL) {
        fprintf(stderr, "Fehler: Speicher konnte nicht reserviert werden\n");
        return 1;
    }

    /* Initialisierung des Spielfeldes mit zufälligen Zuständen */
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            field[y][x] = random_state(0.5); /* 50% Wahrscheinlichkeit für lebende Zellen */
        }
    }

    /* Ausführung von Conways Spiel des Lebens */
    if (game_of_life(field, width, height) != 0) {
        fprintf(stderr, "Fehler: Problem beim Ausführen des Spiels\n");
        return 1;
    }

    return 0;
}
