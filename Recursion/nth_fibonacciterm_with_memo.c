#include <stdio.h>

long long int F[51];  // Memoization array

// Recursive Fibonacci with Memoization
long long int Fib(int n) {
    if (n <= 1) {
        return n;  
    }

    if (F[n] != -1) {  // Check if the value is already calculated
        return F[n];
    }

    // Calculate and store in memoization array
    F[n] = Fib(n - 1) + Fib(n - 2);
    return F[n];
}

int main() {
    // Initialize the memoization array with -1
    for (int i = 0; i < 100; i++) {
        F[i] = -1;
    }

    int n;
    printf("Enter a number : ");
    scanf("%d", &n);

    if (n < 0 || n > 100) {
        printf("Please enter a number between 0 and 50.\n");
        return 1;
    }

    long long int result = Fib(n-1);  // Directly call Fib(n)
    printf("The %dth Fibonacci number is: %lld\n", n, result);

    return 0;
}
