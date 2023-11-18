#include <stdio.h>

// Functions
int set_union(int set1[], int set1_len, int set2[], int set2_len, int result[], int result_len);
int is_set(int array[], int array_len);
int is_element_of(int element,int array[], int array_len);
void print_array(int array[], int array_len);

// ------------------------------------------------------------

int main () {


    // zwei Mengen, die disjunkt sind (also keine Elemente gemeinsam haben),
    int array_A[] = {1, 2, 3, 4, 5, 6, 7, 8}; // Terminierer nur bei char array die als String verwendet werden notwendig
    int len_A = sizeof(array_A) / sizeof(array_A[0]);

    int array_B[] = {12, 13, 24, 35, 46, 57, 68, 79, 98}; // Terminierer nur bei char array die als String verwendet werden notwendig
    int len_B = sizeof(array_B) / sizeof(array_B[0]);

    int result1_len = 20;
    int result1[result1_len];

    int anzahl1 = set_union(array_A, len_A, array_B, len_B, result1, result1_len);
    printf("Anzahl Elemente: %i\n", anzahl1);
    print_array(result1, anzahl1);

    // +++++++

    // zwei Mengen, die gleich sind,
    int array_C[] = {1, 2, 3, 4};
    int len_C = sizeof(array_C) / sizeof(array_C[0]);

    int array_D[] = {1, 2, 3, 4};
    int len_D = sizeof(array_D) / sizeof(array_D[0]);

    int result2_len = 20;
    int result2[result2_len];

    int anzahl2 = set_union(array_C, len_C, array_D, len_D, result2, result2_len);
    printf("Anzahl Elemente: %i\n", anzahl2);
    print_array(result2, anzahl2);

    // +++++++

    // zwei Mengen, von denen eine leer ist,
    int array_E[] = {1, 2, 3, 4};
    int len_E = sizeof(array_E) / sizeof(array_E[0]);

    int array_F[] = {};
    int len_F = sizeof(array_F) / sizeof(array_F[0]);

    int result3_len = 20;
    int result3[result3_len];

    int anzahl3 = set_union(array_E, len_E, array_F, len_F, result3, result3_len);
    printf("Anzahl Elemente: %i\n", anzahl3);
    print_array(result3, anzahl3);

    // +++++++

    // zwei Mengen, die weder disjunkt noch gleich sind und mindestens 3 Elemente gemeinsam haben.
    int array_G[] = {1, 2, 3, 4};
    int len_G = sizeof(array_G) / sizeof(array_G[0]);

    int array_H[] = {1, 2, 3, 5, 6, 7};
    int len_H = sizeof(array_H) / sizeof(array_H[0]);

    int result4_len = 20;
    int result4[result4_len];

    int anzahl4 = set_union(array_G, len_G, array_H, len_H, result4, result4_len);
    printf("Anzahl Elemente: %i\n", anzahl4);
    print_array(result4, anzahl4);

}

// ------------------------------------------------------------

int set_union(int set1[], int set1_len, int set2[], int set2_len, int result[], int result_len) {

    // Handelt ¨es sich bei set1 oder set2 um keine Mengen gem¨aß Aufgabenteil b) oder
    // ist result len kleiner als die Anzahl der Elemente in der Vereinigung,
    // soll der Wert 0 zuruckgegeben ¨werden (stellvertretend fur die leere Menge). 
    if (is_set(set1, set1_len) == 0 || is_set(set2, set2_len) == 0) {
        printf("Keine Mengen\n");
        return 0;
    }

    // Anzahl Elemente in Vereinigung bestimmen
    int anzahl = set1_len;

    for (int i = 0; i < set2_len; i++) {
        if (is_element_of(set2[i], set1, set1_len) == 0) {
            anzahl++;
        }
    }

    printf("Vereinigung Laenge: %i\n", anzahl);

    if (result_len < anzahl) {

        printf("result_len ist zu klein\n");
        return 0;
    }

    // +++++

    // Set1 hinzufügen
    for (int i = 0; i < set1_len; i++) {
        result[i] = set1[i];
    }

    // Set2 hinzufügen zu Result
    int index = set1_len;

    // Durch Set2 Loopen bis wir Wert finden, der nicht in set1 ist,
    for (int i = 0; i < set2_len; i++) {
        if (is_element_of(set2[i], set1, set1_len) == 0) {
            result[index] = set2[i];
            index++;
        }
    }

    return anzahl;

}

// ------------------------------------------------------------

int is_set(int array[], int array_len) {

    int i = 0;
    int j = 0;

    for (i = 0; i < array_len; i++) {

        for (j = 0; j < array_len; j++) {

            if ( i != j && array[i] == array[j]) {
                return 0;
            }
        }
    }

    return 1;

}

// ------------------------------------------------------------

int is_element_of(int element,int array[], int array_len) {

    for (int i = 0; i < array_len; i++) {

        if (element == array[i]){

            return 1;

        }
        
    }

    return 0;

}

// ------------------------------------------------------------

void print_array(int array[], int array_len) {
    printf("[ ");

    for (int i = 0; i < array_len; i++) {
        printf("%i ", array[i]);
    }

    printf("]\n");

}

// ------------------------------------------------------------

