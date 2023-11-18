#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funktion, die negative Zufallswerte in ein Array einfügt
void array_randneg(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = -1 * ((rand()+1) % 100); // Generiert eine negative Zufallszahl
    }
}

// Funktion, die überprüft, ob alle Werte in einem Array negativ sind
int array_isneg(int a[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] >= 0) {
            return 0;
        }
    }
    return 1; // Alle Zahlen sind negativ
}

// Hauptprogramm
int main() {
    srand(time(NULL)); // Initialisierung des Zufallszahlengenerators

    int size = 10;
    int a[size];

    // Fülle das Array mit negativen Zufallswerten
    array_randneg(a, size);

    // Ausgabe des Arrays
    printf("Array-Werte: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Überprüfe, ob alle Werte im Array negativ sind
    if (array_isneg(a, size)) {
        printf("Alle Werte im Array sind negativ.\n");
    } else {
        printf("Nicht alle Werte im Array sind negativ.\n");
    }

    return 0;
}
