#include <stdio.h>

// Function to calculate the factorial
unsigned long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// main
int main() {
    int number;
    unsigned long long result;

    // Ask the user for a number
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);

    // Calculate factorial
    result = factorial(number);

    // Display the result
    printf("The factorial of %d is %llu.\n", number, result);

    return 0;
}
