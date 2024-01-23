#include <stdio.h>

#define MAX_INPUT 10

int search_seq_sorted(int a[], int n, int s);
int search_unsorted(int a[], int n, int s);
int array_max(int a[], int n);
void array_swap(int a[], int i, int j);
void auswahlsort(int a[], int n);
void array_print(int a[], int n);

int main(void)
{
	int folge[MAX_INPUT] = {2, 6, 3, 5, 8, 1, 9, 7, 0, 4};
	int suchzahl = 12;
	int found, pos;
	array_print(folge, MAX_INPUT);
	found = search_unsorted(folge, MAX_INPUT, suchzahl);
	printf("\nSuchzahl %i gefunden an Position %i\n", suchzahl, found);
	auswahlsort(folge, MAX_INPUT);
	array_print(folge, MAX_INPUT);
	pos = search_seq_sorted(folge, MAX_INPUT, suchzahl);
	printf("\nNeue Zahl %i einfügen an Position %i\n", suchzahl, pos);
	return 0;
}

int search_unsorted(int a[], int n, int s)
{
	int i;
	for (i = 0; i < n; ++i) {
		if (a[i] == s)
			return i;
	}
	return -1;
}

int search_seq_sorted(int a[], int n, int s)
{
	int i = -1;
	do {
		++i;
	} while (i < n && s > a[i]);
	return i;
}

int array_max(int a[], int n)
{
	int i;
	int pos = 0;
	int max = a[0];
	for (i = 1; i < n; ++i) {
		if (a[i] > max) {
			max = a[i];
			pos = i;
		}
	}
	return pos;
}

void array_swap(int a[], int i, int j)
{
	int hilf = a[i];
	a[i] = a[j];
	a[j] = hilf;
}

void auswahlsort(int a[], int n)
{
	int i;
	for (i = n; i > 1; --i) {
		int m = array_max(a, i);
		if (m != i - 1)
			array_swap(a, m, i - 1);
	}
}

void array_print(int a[], int n)
{
	int i;
	for (i = 0; i < n; ++i) {
		printf("%i ", a[i]);
	}
}
