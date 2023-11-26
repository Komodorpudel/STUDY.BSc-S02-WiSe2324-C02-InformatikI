
#include <stdio.h>


int main () {
    if (1 || (1 != 1)) {
        printf("is true");
    }

    else {
        printf("is false");
    }
}