#include <stdio.h>

// Functions
int is_element_of(int element, int array[], int array_len);

int main () {

    int element = 20;

    int array[] = {1, 1, 2, 3, 4, 5, 6, 7, 8}; // Terminierer nur bei char array die als String verwendet werden notwendig
    int len = sizeof(array) / sizeof(array[0]);

    printf("Result: %i\n", is_element_of(element, array, len));

    return 0;
}

int is_element_of(int element,int array[], int array_len) {

    for (int i = 0; i < array_len; i++) {

        if (element == array[i]){

            return 1;

        }
        
    }

    return 0;

}


