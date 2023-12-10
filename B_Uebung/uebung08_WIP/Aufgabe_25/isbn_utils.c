#include "isbn_utils.h"
#include "random_utils.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

/* ----------------------------------- */

int get_check_digit(char isbn[]) {
    int sum = 0;
    for (int i = 0; isbn[i] != '\0'; i++) {
        int digit = isbn[i] - '0';
        sum += (i % 2 == 0) ? digit : digit * 3;
    }
    return (10 - (sum % 10)) % 10;
}

void generate_random_ISBN(char isbn[]) {
    srand((unsigned int)time(NULL));
    int part1 = choose_random((int[]){978, 979}, 2);
    int part2 = random_up_to(9);
    int part3 = random_up_to(99999);
    int part4 = random_up_to(999);

    sprintf(isbn, "ISBN %d-%d-%d-%d-", part1, part2, part3, part4);
    int check_digit = get_check_digit(isbn);
    sprintf(isbn + strlen(isbn), "%d", check_digit);
}
