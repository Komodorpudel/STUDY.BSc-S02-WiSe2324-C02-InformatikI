#include "A_35+36.h"

/* -------------------------------------- */

/* 
 * Funktion zur Initialisierung des Spielfelds.
 * Reserviert Speicher für ein zweidimensionales Array der Größe height x width.
 */
int **field_init(int width, int height) {
    int i;
    int **field; /* Zeiger auf Zeiger */

    /* Speicher für die Zeiger auf die Reihen allokieren */
    field = malloc(height * sizeof(int*));

    if (field == NULL) {
        return NULL; /* Bei Speichermangel NULL zurückgeben */
    }

    /* Speicher für jede Reihe allokieren */
    for (i = 0; i < height; i++) {
        field[i] = malloc(width * sizeof(int));

        if (field[i] == NULL) {
            /* Speicherfreigabe bei Fehlschlag */
            while (i > 0) {
                free(field[--i]);
            }
            free(field);
            return NULL;
        }
    }

    return field; /* Zeiger auf das reservierte Spielfeld zurückgeben */
}

/* -------------------------------------- */

/* 
 * Gibt zufällig den Wert von ALIVE oder DEAD zurück.
 * Die Wahrscheinlichkeit für ALIVE beträgt (100 * live_probability)%.
 */
int random_state(double live_probability) {

    /* srand ist in main. Wenn wir srand hier habem, ist das Problem, dass unser random Seed, hier die zeit in sekunden, jedes mal gleich ist, weil der Prozessor alles so schnell abläuft. Der Seed ist gleich und jedes mal kommt die gleiche anfängliche Zahl raus und unser Feld ist entweder immer voll oder immer leer */

    /* Wenn live_probability ≥ 1, immer ALIVE zurückgeben */
    if (live_probability >= 1.0) {
        return ALIVE;
    }
    /* Wenn live_probability ≤ 0, immer DEAD zurückgeben */
    else if (live_probability <= 0.0) {
        return DEAD;
    }
    /* Ansonsten, basierend auf der Wahrscheinlichkeit ALIVE oder DEAD zurückgeben */
    else {
        return (rand() % 100 < (live_probability * 100)) ? ALIVE : DEAD;
        /* RAND_MAX ist größte random number. Multipliziert mit
         *live_probability teile ich die menge an Zahlen auf in
         * ALIVE oder DEAD
         */
    }
}

/* -------------------------------------- */

/* 
 * Funktion zum Ausdrucken des Spielfeldes auf die Kommandozeile.
 * field: Zeiger auf das zweidimensionale Array, das das Spielfeld repräsentiert.
 */
void print_field(int **field, int width, int height) {
    int x, y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (field[y][x] == ALIVE) {
                print_living_cell();
            }
            else {
                print_dead_cell();
            }
        }
        printf("\n"); /* Neue Zeile am Ende jeder Reihe */
    }
}

/* -------------------------------------- */

/* 
 * Funktion zur Bestimmung der Anzahl lebender Nachbarn einer Zelle.
 * field: Zeiger auf das zweidimensionale Array, das das Spielfeld repräsentiert.
 * width: Breite des Spielfeldes.
 * height: Höhe des Spielfeldes.
 * x, y: Koordinaten der Zelle, für die die lebenden Nachbarn gezählt werden sollen.
 */
int alive_neighbors(int **field, int width, int height, int x, int y) {
    int count = 0;
    int i, j;
    int nx;
    int ny;

    for (i = -1; i <= 1; i++) {

        for (j = -1; j <= 1; j++) {

            /* Überspringe die Zelle selbst */
            if (i == 0 && j == 0) {
                continue;
            }

            nx = x + i; /* x-Koordinate des Nachbarn */
            ny = y + j; /* y-Koordinate des Nachbarn */

            /* Überprüfe die Grenzen des Spielfeldes */
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {

                /* Zähle, wenn Nachbarzelle lebendig ist */
                if (field[ny][nx] == ALIVE) {
                    count++;
                }
            }
        }
    }

    return count;
}

/* -------------------------------------- */

/* 
 * Funktion zur Bestimmung des Zustandes des Spielfeldes für die nächste Generation.
 * field: Zeiger auf das zweidimensionale Array, das das aktuelle Spielfeld
 * repräsentiert.
 * Gibt einen Zeiger auf das neue Spielfeld zurück.
 */
int **next_state(int **field, int width, int height) {
    int x, y;
    int live_neighbors_count;
    int **new_field;

    /* Speicher für das neue Feld allokieren */
    new_field = malloc(height * sizeof(int*));
    for (y = 0; y < height; y++) {
        new_field[y] = malloc(width * sizeof(int));
    }

    /* Zellen ablaufen und zustand ermitteln */
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            
            /* Lebende Nachbarzellen für die jeweilige Zelle */
            live_neighbors_count = alive_neighbors(field, width, height, x, y);

            /* Wenn Zelle bislang lebendig: */
            if (field[y][x] == ALIVE) {
                if (live_neighbors_count < 2 || live_neighbors_count > 3) {
                    new_field[y][x] = DEAD; /* Stirbt an Einsamkeit oder Überbevölkerung */
                }
                else {
                    new_field[y][x] = ALIVE; /* Bleibt lebend */
                }
            }
            
            /* Wenn bislang tot: */
            else {
                if (live_neighbors_count == 3) {
                    new_field[y][x] = ALIVE; /* Wird geboren */
                } 
                else {
                    new_field[y][x] = DEAD; /* Bleibt tot */
                }
            }
        }
    }

    return new_field;
}

/* -------------------------------------- */

/* 
 * Funktion zum Ausführen von Conways Spiel des Lebens.
 * field: Zeiger auf das zweidimensionale Array, das das Anfangsfeld repräsentiert.
 * Führt das Spiel für eine festgelegte Anzahl von Generationen aus.
 */
int game_of_life(int **field, int width, int height) {
    int generation;
    int **next_field;
    int y;

    /* Generationen durchlaufen */    
    for (generation = 0; generation < NUM_GENERATIONS; generation++) {

        /* Feld der aktuellen Generation ausgeben */
        clear_field();
        print_field(field, width, height);
        wait_ticks(500000000); /* Eine Sekunde warten */

        /* Zustand für die nächste Generation berechnen */
        next_field = next_state(field, width, height);

        /* Speicher des aktuellen Feldes freigeben */
        for (y = 0; y < height; y++) {
            free(field[y]);
        }
        free(field);

        /* Fortfahren mit dem nächsten Feld */
        field = next_field;
    }

    return 0; /* Erfolgreicher Abschluss */
}
