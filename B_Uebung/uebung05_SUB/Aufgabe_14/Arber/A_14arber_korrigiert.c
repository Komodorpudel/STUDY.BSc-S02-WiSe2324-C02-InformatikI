#include <stdio.h>

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
    int result = 0;

    for(i = 0; i < num_bits; i++) {

        // Beide 1 oder beide 0
        if (get_bit_value_at(i, x) == get_bit_value_at(i, y)) {
            
            result = result | (1 << i);
        }

        //  Wenn x 1 und y 0
        else if (get_bit_value_at(i, x) == 1){ 
            result = result | (0 << i);
        }

        // Wenn x 0 und y 1
        else {
            result = result | (1 << i);
        }
    }

    return result;

}

int main()
{
    /* printf("Arber's code:\n"); */
    int x = -205869332;
    int y = 1432434762;

    /* int x = 8;
    int y = 3; */

    /*  printf("Bit-Value an pos 3 von x = 8 :%i\n", get_bit_value_at(3, x));
    printf("Bit-Value an pos 2 von x:%i\n", get_bit_value_at(2, x));
    printf("Bit-Value an pos 1 von x:%i\n", get_bit_value_at(1, x));
    printf("Bit-Value an pos 0 von x:%i\n", get_bit_value_at(0, x)); */

    print_bit_sequence(x);
    print_bit_sequence(y);
    printf("Implication:\n");
    print_bit_sequence(implication(x, y));

    return 0;
}
