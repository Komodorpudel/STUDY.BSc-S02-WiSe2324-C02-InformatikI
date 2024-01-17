#include <stdio.h>
#include <stdlib.h>

unsigned int liesZahl(void);

unsigned long int multiply(unsigned int a, unsigned int b) {

	unsigned long int result = 0;

	printf("Linke Spalte - Rechte Spalte\n");

	while (b > 0) {

		/* Wenn ungerade */
		if (b & 1) {
			result = result + a;
		}

		a <<= 1;  /* bitshift eins nach rechts; verdoppelung */
		b >>= 1; /* bitshift eins nach links; halbierung */

		printf("%u\t\t%u\n", a, b); /* aktueller stand */

	}

	return result;
}

unsigned int liesZahl(void)
{
	unsigned int zahl;
	int status, c;

	do {
		printf("Bitte eine nichtnegative ganze Zahl eingeben: ");
		status = scanf("%u", &zahl);
		if (status == EOF)
			exit(1);

		do {
			if ((c = getchar()) == EOF)
				exit(1);
		} while (c != '\n');
	} while (status != 1 && printf("Da hat etwas nicht funktioniert!\n"));

	return zahl;
}

int main(void) {
    unsigned int a;
    unsigned int b;
    unsigned long int result;

	printf("Russische Bauernmultiplikation\n");

	a = liesZahl();
	b= liesZahl();
	result = multiply(a, b);

    printf("Das Produkt von %u und %u ist %lu.\n", a, b, result);

    return 0;
}
