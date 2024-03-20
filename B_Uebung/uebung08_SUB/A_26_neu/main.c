#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "isbn_utils.h" /* Beachte andere "" anstatt <> */

#define STRING_LEN 99

int main(void)
{
    char isbn[STRING_LEN];
    srand(time(NULL));

    generate_random_ISBN(isbn);

    printf("Generierte ISBN: %s\n", isbn);

    return 0;
}
