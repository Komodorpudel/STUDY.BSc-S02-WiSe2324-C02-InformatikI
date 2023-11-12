#include <stdio.h>

// Functions
int set_union(int set1[], int set1_len, int set2[], int set2_len, int result[], int result_len);
int is_set(int array[], int array_len);
int is_element_of(int element,int array[], int array_len);
void print_array(int array[], int array_len);

// ------------------------------------------------------------

int main () {

    int array_A[] = {1, 1, 2, 3, 4, 5, 6, 7, 8}; // Terminierer nur bei char array die als String verwendet werden notwendig
    int len_A = sizeof(array_A) / sizeof(array_A[0]);

    int array_B[] = {12, 13, 24, 35, 46, 57, 68, 79, 98}; // Terminierer nur bei char array die als String verwendet werden notwendig
    int len_B = sizeof(array_B) / sizeof(array_B[0]);

    int resultA_len = 66;
    int resultA[resultA_len];

    print_array(resultA, resultA_len);

    return 0;
}

// ------------------------------------------------------------

int set_union(int set1[], int set1_len, int set2[], int set2_len, int result[], int result_len) {

    // Handelt ¨es sich bei set1 oder set2 um keine Mengen gem¨aß Aufgabenteil b) oder
    // ist result len kleiner als die Anzahl der Elemente in der Vereinigung,
    // soll der Wert 0 zuruckgegeben ¨werden (stellvertretend fur die leere Menge). 
    if (is_set(set1, set1_len) == 0 || is_set(set2, set2_len) == 0) {
        return 0;
    }

    // Anzahl Elemente in Vereinigung bestimmen
    int anzahl = set1_len;

    for (int i = 0; i < set2_len; i++) {
        if (is_element_of(set2[i], set1, set1_len) == 0) {
            anzahl++;
        }
    }

    if (result_len < anzahl) {
        return 0;
    }

    // +++++


    // Set1 hinzufügen
    for (int i = 0; i < set1_len; i++) {
        result[i] = set1[i];
    }

    // Set2 hinzufügen
    for (int i = set1_len ; i < anzahl; i++) {

        // Durch Set2 Loopen bis wir Wert finden, der nicht in set1 ist,
        for (int j = 0; j < set2_len; j++) {
            if (is_element_of(set2[j], set1, set1_len) == 0) {
                result[i] = set2[j];
                break;
        }
    }

    return 0;

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

