#include <stdio.h>

// Prototype
int is_set(int array[], int array_len);

int main ()
{

    int array[] = {'1', '1', '3', '4', '5', '6', '7', '8',}; // Terminierer nur bei char array die als String verwendet werden notwendig
    int len = (sizeof(array) / sizeof(array[0])) - 1;

    printf("Result: %i\n", is_set(array, len));

    return 0;
}

int is_set(int array[], int array_len)
{

    int i = 0;
    int j = 0;

    for (i = 0; i < array_len; i++) {

        for (j = i + 1; j < array_len; j++) {

            if (array[i] == array[j]) {
                return 0;
            }
        }
    }

    return 1;

}
