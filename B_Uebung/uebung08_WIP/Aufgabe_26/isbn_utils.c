#include "isbn_utils.h"
#include "random_utils.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/* ----------------------------------- */

int get_check_digit(char isbn[]) {
    int sum = 0;
    int i;
    int digit;

    for (i = 0; isbn[i] != '\0'; i++) {
        digit = isbn[i] - '0';

        /* Wenn ungerade, dann 1, gerade dann 3 */
        sum = sum + ((i % 2 == 0) ? digit : digit * 3);
    }
    return (10 - (sum % 10)) % 10;
}

void generate_random_ISBN(char isbn[]) {

    int part1_array[2] = {978, 979};
    int part1;
    int part2;
    int part3;
    int part4;
    int check_digit;

    srand((unsigned int)time(NULL));
    
    part1 = choose_random(part1_array, 2);
    part2 = random_up_to(9);
    part3 = random_up_to(99999);
    part4 = random_up_to(999);

    sprintf(isbn, "ISBN %d-%d-%d-%d-", part1, part2, part3, part4);
    check_digit = get_check_digit(isbn);
    sprintf(isbn + strlen(isbn), "%d", check_digit);
}
