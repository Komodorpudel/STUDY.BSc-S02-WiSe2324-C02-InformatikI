#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ------------------------------------------- */

double string_to_double(const char *s, char **endp) {
    double result = 0.0;
    int sign = 1;
    int exp_sign = 1;
    int exponent = 0;

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
        result = (result * 10.0) + (*s - '0');
        s++;
    }

    /* Verarbeite Dezimalpunkt und Ziffern nach dem Dezimalpunkt */
    if (*s == '.') {
        double frac = 0.1;
        s++;
        while (isdigit((unsigned char)*s)) {
            result += (*s - '0') * frac;
            frac *= 0.1;
            s++;
        }
    }

    /* +++++++++++++++++++++++++++++++++++ */

    /* Verarbeite Exponenten, falls vorhanden */
    if ((*s == 'e' || *s == 'E') && (*(s+1) != '\0')) {

        /* Falls nächster Wert ein Vorzeichen und übernächster Wert eine Zahl ist ODER nächster Wert ist Zahl */
        if(((((*(s+1) != '-') || *(s+1) != '+')) && (*(s+2) != '\0') && isdigit(*(s+2)))
        ||
        isdigit(*(s+1))) {
            s++;

            /* Wenn pos oder neg Vorzeichen */
            if (*s == '+') {
                s++;
            }
            else if (*s == '-') {
                exp_sign = -1;
                s++;
            }

            /* Wenn kein Vorzeichen, gehen wir von pos aus und machen weiter: */

            while (isdigit((unsigned char)*s)) {
                exponent = (exponent * 10) + (*s - '0');
                s++;
            }
        }
    }

    /* +++++++++++++++++++++++++++++++++++ */

    /* Berechne den endgültigen Wert unter Berücksichtigung des Exponenten */
    if (exp_sign > 0) {
        while (exponent--) {
            result =  result * 10.0;
        }
    }
    else {
        while (exponent--) {
            result = result * 0.1;
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

    test("65e7", endp1, endp2);
    test("786e-6", endp1, endp2);
    test(" 43e11", endp1, endp2);
    test("+4387e2", endp1, endp2);
    test("-432e4", endp1, endp2);
    test("-167e-3", endp1, endp2);
    test("6538.3e2Ab", endp1, endp2);
    test("175e", endp1, endp2);
    test("175e-", endp1, endp2);

    test("175e-abc", endp1, endp2);

	return 0;
}

/* ------------------------------------------- */
