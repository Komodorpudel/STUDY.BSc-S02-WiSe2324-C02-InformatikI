
#include <stdio.h>

// Functions
int get_bit_value_at(int pos, int x);
void print_bit_sequence(int x);
int implication (int x, int y) ;

int main() {

    int x = -205869332; // int-Variable x mit dem Wert -205869332
    int y = 1432434762; // int-Variable y mit dem Wert 1432434762

    printf("Bit-Repraesentation von x (%d):\n", x);
    print_bit_sequence(x);

    printf("Bit-Repraesentation von y (%d):\n", y);
    print_bit_sequence(y);

    printf("Bit-Repraesentation der Implikation von x und y:\n");
    print_bit_sequence(implication(x, y));

    return 0;
}

int get_bit_value_at(int pos, int x) {

    // Größe von x in Bits
    int max_bit_pos = sizeof(x) * 8; // Sizeof gibt Bytes zurück
    int check_value = 1;

    if (pos < 0 || pos >= max_bit_pos) {
        return -1;
    }

    x = x >> pos;

    return x & 1;

}

// --------------

void print_bit_sequence(int x) {

    // Anzahl der Bits in x
    int num_bits = sizeof(x) * 8;
    int i = num_bits - 1;
    int bit = 0;

    for (; i >= 0; i--) {

        // Verschieben und das Bit extrahieren
        bit = (x >> i) & 1; 

        // Bit ausgeben
        printf("%d", bit); 
    }
    printf("\n"); // Zeilenumbruch nach dem Ende der Bit-Sequenz
}

// ---------------

int implication (int x, int y) {

    return (~x) | y;

}

// ---------------