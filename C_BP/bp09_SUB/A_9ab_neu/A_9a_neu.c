#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

double string_to_double(const char *s, char **endp)
{

    double result = 0;
    int sign = 1;
    double frac;

    /* Führende Leerzeichen überspringen */
    while(isspace(*s)){
        s++;
    }

    /* Vorzeichen checken */
    if ((*s == '+' || *s == '-') && ( isdigit(*(s + 1)) || ( *(s + 1) == '.' && isdigit(*(s + 2))))){

        if(*s == '-'){
            sign = -1;
        }

    }

    s = s + 1; 

    /* Zahlen vor Punkt */
    while(isdigit(*s)){
        result = result * 10 + (*s - '0');

        s = s + 1;
    }

    /* Zahlen nach Punkt */
    if ( (*s == '.') && isdigit(*(s + 1))){
        s = s + 1;
        frac = 0.1;

        while(isdigit(*s)){
            result = result + frac * (*s - '0');
            frac = frac/10;
            s = s + 1;
        }

    }
    else{
        s = s + 1;
    }

    /* Endpoint zurückgeben - Funktion hat Zeiger auf Zeiger bekommen, um Zeiger außerhalb der Funktion auf den neuen endp zu setzen */


    if (endp != NULL){
        *endp = (char*) s;
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
