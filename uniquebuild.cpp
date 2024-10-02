#include <iostream> // Needed for printArray and std::cout
#include <string>   // Needed for std::string printing
#include "uniquebuild.h"

// Print function for std::string
void print(const std::string& str) {
    std::cout << str << std::endl;
}

// Print function for int
void print(int value) {
    std::cout << value << std::endl;
}

// Function to calculate the factorial of a number as unsigned long long
unsigned long long factorial_ull(int n) {
    if (n < 0) {
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
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
        std::cout << "Error: Factorial is not defined for negative numbers." << std::endl;
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
    std::cout << "Fibonacci series up to " << count << " terms:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    std::cout << std::endl;
}

// Main function to demonstrate the usage of utility functions
int main() {
    int number;
    int fibonacci_count;

    // Get user input for factorial calculation
    std::cout << "Enter a non-negative integer to calculate its factorial: ";
    std::cin >> number;

    // Choose the appropriate factorial function based on input size
    if (number <= 12) {
        // Use int factorial for smaller values
        int factInt = factorialInt(number);
        if (factInt > 0) {
            std::cout << "Factorial of " << number << " (using int) is " << factInt << std::endl;
        }
    } else {
        // Use unsigned long long factorial for larger values
        unsigned long long factUll = factorial_ull(number);
        if (factUll > 0) {
            std::cout << "Factorial of " << number << " (using unsigned long long) is " << factUll << std::endl;
        }
    }

    // Get user input for Fibonacci series
    std::cout << "Enter the number of Fibonacci terms to display: ";
    std::cin >> fibonacci_count;
    if (fibonacci_count > 0) {
        print_fibonacci(fibonacci_count);
    } else {
        std::cout << "Error: Please enter a positive integer for Fibonacci terms." << std::endl;
    }

    return 0;
}

// End of include guard