#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pretty_print(int *a, char ***b);

int main(int argc, char **argv)
{
	int number;
	if (argc != 2)
		return 1;
	number = argv[1][0] - 48;
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
		for (j = i; j <= strlen(*(b[i])); ++i)
			printf("%c", *(*(*b + i) + j));
		printf("\n");
	}
}
