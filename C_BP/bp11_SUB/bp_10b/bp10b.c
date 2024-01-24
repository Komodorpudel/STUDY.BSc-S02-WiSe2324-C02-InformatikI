#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING 15

void array_swap(char w[], int i, int j);
int read_string(char in[]);
void reverse(char w[]);

int main(void)
{
	char input[MAX_STRING] = {"Test"};
	printf("Zeichenfolge eingeben:\n");
	if (!read_string(input)) {
		printf("Eingabe zu lang");
		return 1;
	}
	printf("%s\n", input);
	printf("Zeichenfolge rueckwaerts gelesen:\n");
	reverse(input);
	printf("%s\n", input);
	return 0;
}

void array_swap(char w[], int i, int j)
{
	int hilf = w[i];
	w[i] = w[j];
	w[j] = hilf;
}

int read_string(char in[])
{
	int i = 0;
	char c = getchar();
	while (c != '\n' && i++ < MAX_STRING - 1) {
		in[i] = c;
		c = getchar();
	}
	if (i == MAX_STRING - 1 && c != '\n')
		return 0;
	in[i] = '\0';
	return 1;
}

void reverse(char w[])
{
	int i;
	int n = strlen(w);
	for (i = 0; i <= n / 2 - 1; ++i)
		array_swap(w, i, n - i);
}
