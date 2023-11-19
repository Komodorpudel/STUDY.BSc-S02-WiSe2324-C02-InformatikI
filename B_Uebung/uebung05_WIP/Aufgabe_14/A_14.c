#include <stdio.h>

// Functions
int get_bit_value_at(int pos, int x);
void print_bit_sequence(int x);
int implication (int x, int y) ;

int main()
{

    int x = -205869332; // int-Variable x mit dem Wert -205869332
    int y = 1432434762; // int-Variable y mit dem Wert 1432434762

    //int x = 8;
    // int y = 3;

    printf("Bit-Value an pos 3 von x = 8 :%i\n", get_bit_value_at(3, x));
    printf("Bit-Value an pos 2 von x:%i\n", get_bit_value_at(2, x));
    printf("Bit-Value an pos 1 von x:%i\n", get_bit_value_at(1, x));
    printf("Bit-Value an pos 0 von x:%i\n", get_bit_value_at(0, x));

    printf("Bit-Repraesentation von x (%d):\n", x);
    print_bit_sequence(x);

    printf("Bit-Repraesentation von y (%d):\n", y);
    print_bit_sequence(y);

    printf("Bit-Repraesentation der Implikation von x und y:\n");
    print_bit_sequence(implication(x, y));

    return 0;
}

int get_bit_value_at(int pos, int x)
{

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

void print_bit_sequence(int x)
{
    int num_bits;
    int i;
    num_bits = sizeof(x) * 8;

    for(i = num_bits - 1; i >= 0; i--) {
        printf("%i",get_bit_value_at(i, x));
    }
    printf("\n");
}

// ---------------

int implication (int x, int y)
{

    return (~x) | y;

}

// 11110011101110101010111011101100 //Simon
// 01010101011000010011100001001010 //Simon

// 01010101011000010011100001001011
// 01011101011001010111100101011011


// Arber:
//11110011101110101010111011101100
//01010101011000010011100001001010
//Implication:
//01010101011000010011100001001010

//01011101011001010111100101011011
//01011101011001010111100101011011

// ---------------