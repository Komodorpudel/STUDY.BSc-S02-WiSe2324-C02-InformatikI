#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------- */

double string_to_double(const char *s, char **endp) {
    /* char *s ist Zeiger auf String */
    double result = 0.0;
    int sign = 1;

    /* Führende Leerzeichen überspringen */
    while (isspace((unsigned char)*s)) {
        s++;
    }

    /* Überprüfe das Vorzeichen */
    if (*s == '+') {
        s++;
    }
    else if (*s == '-') {
        sign = -1;
        s++;
    }

    /* Verarbeite Ziffern vor dem Dezimalpunkt */
    while (isdigit((unsigned char)*s)) {

        /* für jede neue Digit wird das vorherige Result mit 10 multipliziert und dann Digit angehängt */
        result = (result * 10.0) + (*s - '0');

        /* ich muss von *s den ASCI Wert von '0' abziehen für den korrekten wert */
        s++;
    }

    /* Verarbeite Dezimalpunkt und Ziffern nach dem Dezimalpunkt */
    if (*s == '.') {

        double frac = 0.1;
        s++;

        while (isdigit((unsigned char)*s)) {
            result = result + ((*s - '0') * frac);
            frac = frac * 0.1;
            s++;
        }
    }

    /* Setze endp, wenn es nicht NULL ist */
    if (endp != NULL) {
        *endp = (char *)s;
    }

    return result * sign;
}

/* ------------------------------------------- */

void test(const char *s, char **endp1, char **endp2)
{
	printf("Zahl: %lf, Rest: %s\n", strtod(s, endp1), (endp1 != NULL ? *endp1 : "NULL"));
	printf("Zahl: %lf, Rest: %s\n\n", string_to_double(s, endp2), (endp2 != NULL ? *endp2 : "NULL"));
}

/* ------------------------------------------- */

int main(void)
{
	char *string1, *string2;
	char **endp1 = &string1, **endp2 = &string2;
	test("129", NULL, NULL);
	test("129", endp1, endp2);
	test("   129.34", endp1, endp2);
	test("856.97", endp1, endp2);
	test(".49", endp1, endp2);
	test("-.87", endp1, endp2);
	test("+76.9", endp1, endp2);
	test("-9943.0785", endp1, endp2);
	test("18.", endp1, endp2);
	test("0.", endp1, endp2);
	test("12.43Hallo", endp1, endp2);
	test("+", endp1, endp2);
	test(".", endp1, endp2);

	return 0;
}

/* ------------------------------------------- */
