#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pretty_print(int *a, char ***b);

int main(int argc, char **argv)
{
	int number;
	if (argc != 2)
		return 1;
	number = argv[1][0] - 48; /* 1. Konvertierung so geht nur für einstellige Zahlen -> atoi verwenden */
	printf("Anzahl Kommandozeilenparameter: %i\n", argc - 1);
	printf("Als Parameter eingegebene Zahl: %i\n", number);
	pretty_print(&argc, &argv);
	return 0;
}

void pretty_print(int *a, char ***b) /* Hier geben wir einfach nur die Argv wieder aus */
{
	int i;
	size_t j;
	for (i = 0; i < *a; ++i) {
		for (j = i; j <= strlen(*(b[i])); ++i) /* 3. j ab 0 inkrementieren und nicht nochmal i, 4. strlen erwartet Zeiger auf Anfang von Array, wir liefern aber Zeiger auf Zeiger, 5. ebenso < anstatt <= weil sonst Überlauf */
			printf("%c", *(*(*b + i) + j)); /* besser: (*b)[i][j] */
		printf("\n");
	}
}
