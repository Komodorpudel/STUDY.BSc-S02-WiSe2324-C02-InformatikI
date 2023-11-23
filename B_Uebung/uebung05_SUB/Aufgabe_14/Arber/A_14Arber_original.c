#include <stdio.h>

int get_bit_value_at(int pos, int x)
{
    int num_bits;
    int mask;
    int bit;

    num_bits = sizeof(x) * 8; /* Größe von num_bits in Bits ermitteln */
    /* Ausnahmen: */
    if (pos < 0 || pos >= num_bits) { 
        return -1;
    }

    /* Maske erstellen mit einem gesetzten Bit an der ges. Position */
    mask = 1 << pos;

    /* Maske auf x anwenden und verschiebung an die niedrigste Position */
    bit = (x & mask) >> pos;
     
    /* Bitwert zurückgeben */
    return bit;
}

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

int implication(int x, int y)
{
    int num_bits = sizeof(x) * 8;
    int i;
    int result;

    for(i = 0; i < num_bits; i++) {
        if (get_bit_value_at(i, x) == get_bit_value_at(i, y)) {
            result = result | (get_bit_value_at(i, x) << i);
        } else if (get_bit_value_at(i, x) == 1){ 
            result = result | (0 << i);
        } else {
            result = result | (1 << i);
        }
    }

    return result;

}

int main()
{
    int x = -205869332;
    int y = 1432434762;

    print_bit_sequence(x);
    print_bit_sequence(y);
    print_bit_sequence(implication(x, y));

    return 0;
}
