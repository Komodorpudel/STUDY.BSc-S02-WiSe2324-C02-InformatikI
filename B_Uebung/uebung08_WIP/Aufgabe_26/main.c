#include "isbn_utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

    char isbn[30];

    /* Seed the random number generator */
    srand(time(NULL));
    
    generate_random_ISBN(isbn);
    printf("%s\n", isbn);
    return 0;
}
