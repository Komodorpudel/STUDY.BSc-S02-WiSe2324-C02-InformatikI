#include "isbn_utils.h"
#include <stdio.h>

int main() {
    char isbn[30];
    generate_random_ISBN(isbn);
    printf("%s\n", isbn);
    return 0;
}
