#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pretty_print(int *a, char ***b);

int main(int argc, char **argv)
{
	int number;
	if (argc != 2)
		return 1;
	number = atoi(argv[1]); /* Fix hier */
	printf("Anzahl Kommandozeilenparameter: %i\n", argc - 1);
	printf("Als Parameter eingegebene Zahl: %i\n", number);
	pretty_print(&argc, &argv);
	return 0;
}

void pretty_print(int *a, char ***b)
{
	int i;
	size_t j;
	for (i = 0; i < *a; ++i) { 
		for (j = 0; j < strlen((*b)[i]); ++j) /* Mehrere Fix hier */
			printf("%c", *(*(*b + i) + j));
		printf("\n");
	}
}
