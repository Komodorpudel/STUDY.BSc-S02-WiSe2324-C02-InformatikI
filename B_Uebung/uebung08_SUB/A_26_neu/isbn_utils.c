#include <stdio.h>
#include <stdlib.h> /* Für srand und rand */
#include <time.h> /* für time */
#include <string.h> /* für strncat */
#include <ctype.h> /* für isdigit */

#include "random_utils.h" /* Ich muss das hier inkludieren, weil ich die Funtkionen hier verwende */

/* -------------------------------------- */

int get_check_digit(char isbn[])
{
    int i = 0;
    int factor = 1;
    int checksum;
    while (isbn[i] != '\0'){
        if(isdigit(isbn[i])){
            if(factor == 1){
                checksum = checksum + factor * (isbn[i] - '0');
                factor = 3;
            }
            else{
                checksum = checksum + factor  * (isbn[i] - '0');
                factor = 1;
            }

        }

        i++;

    }

    return (10 - (checksum % 10)) % 10; /* Beachte: Wenn checksum 0 ist, dann würde 10 rauskommen wenn ich nicht nochmal modulo mache */

}

/* -------------------------------------- */

void generate_random_ISBN (char isbn[])
{

    int prefixes [] = {978,979};

    int prefix;
    int random_0_to_9;
    int random_0_to_99999;
    int random_0_to_999;
    int check_digit;
    char check_digit_char[2]; /* Länge 2 weil wir noch Terminierer brauchen */


    prefix = choose_random(prefixes, 2);
    random_0_to_9 = random_up_to(9);
    random_0_to_99999 = random_up_to(99999);
    random_0_to_999 = random_up_to(999);

    sprintf(isbn, "ISBN %i-%i-%i-%i-", prefix, random_0_to_9, random_0_to_99999, random_0_to_999);
    
    check_digit = get_check_digit(isbn);
    sprintf(check_digit_char, "%i", check_digit);

    strcat(isbn, check_digit_char);

}
