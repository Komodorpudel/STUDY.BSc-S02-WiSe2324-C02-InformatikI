#include <stdio.h>
#include <ctype.h>


int main() {

    char array[] = {'1', ':', '7', 'A', 'b', '\0'};

    int len = sizeof(array) / sizeof(array[0]) - 1;

    print_digit_array(array, len);

}


void print_digit_array(char v[], int len_v) {

    for (int i = 0; i < len_v; i++) {

        if (isidigit(v[i]) {
            printf("%c", v[i]);
        }
    }
}