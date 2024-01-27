#include <stdio.h>
#include <math.h> /* For fabs() */

/* ----------------------------------------- */

double minimalerBetrag(double a[], int n) {
    /* Ich kann die Lämge vom Array nicht nachträglich ermitteln, deswegen brauch ich die Info direkt */

    /* Initialize m with the absolute value of the first element */
    double m = fabs(a[0]);
    int i = 1;

    for (; i < n; i++) { /* Start loop from second element */
        if (fabs(a[i-1]) < m) {
            m = fabs(a[i]); /* Update m if a smaller absolute value is found */
        }
    }

    return m;
}

/* ----------------------------------------- */

/* Zum Testen: */
int main() {
    double arr[] = {3.5, -4.1, 2.0, -1.3, 5.2}; /* Example array */
    int size = sizeof(arr) / sizeof(arr[0]); /* Calculate size of the array */

    double minAbsValue = minimalerBetrag(arr, size);
    printf("Der kleinste absolute Betrag ist: %f\n", minAbsValue);

    return 0;
}

/* ----------------------------------------- */
