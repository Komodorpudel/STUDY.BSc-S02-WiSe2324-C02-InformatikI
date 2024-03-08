#include <stdio.h>

// Functions
void print_array(int array[], int array_len);

int main ()
{

    int array[] = {'1', '2', '3', '4', '5', '6', '7', '8',}; // Terminierer nur bei char array die als String verwendet werden notwendig
    int len = sizeof(array) / sizeof(array[0]) - 1;

    print_array(array, len);

    return 0;
}

void print_array(int array[], int array_len)
{

    int i;
    
    printf("[ ");

    for (i = 0; i < array_len; i++) {
        printf("%i ", array[i]);
    }

    printf("]\n");

}
