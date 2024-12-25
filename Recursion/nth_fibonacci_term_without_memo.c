// fibonacci series as follows : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, and so on...


#include <stdio.h>

// Recursive Fibonacci without memoization
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the position of the Fibonacci sequence: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n-1));
    return 0;
}
