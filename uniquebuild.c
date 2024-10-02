#include <stdio.h>
#include "uniquebuild.h"

// Function to calculate the factorial of a number as unsigned long long
unsigned long long factorial_ull(int n) {
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the factorial as int for smaller numbers
int factorialInt(int n) {
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 0;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to print Fibonacci numbers up to a certain count
void print_fibonacci(int count) {
    int a = 0, b = 1;
    printf("Fibonacci series up to %d terms:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// Main function to demonstrate the usage of utility functions
int main() {
    int number;
    int fibonacci_count;

    // Get user input for factorial calculation
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &number);

    // Choose the appropriate factorial function based on input size
    if (number <= 12) {
        // Use int factorial for smaller values
        int factInt = factorialInt(number);
        if (factInt > 0) {
            printf("Factorial of %d (using int) is %d\n", number, factInt);
        }
    } else {
        // Use unsigned long long factorial for larger values
        unsigned long long factUll = factorial_ull(number);
        if (factUll > 0) {
            printf("Factorial of %d (using unsigned long long) is %llu\n", number, factUll);
        }
    }

    // Get user input for Fibonacci series
    printf("Enter the number of Fibonacci terms to display: ");
    scanf("%d", &fibonacci_count);
    if (fibonacci_count > 0) {
        print_fibonacci(fibonacci_count);
    } else {
        printf("Error: Please enter a positive integer for Fibonacci terms.\n");
    }

    return 0;
}