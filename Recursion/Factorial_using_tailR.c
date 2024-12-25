#include<stdio.h>
long int tFact(int n , long int accumulator)
{
    if (n == 1)
    {
        return accumulator;
    
    }
    else
    {
        return tFact(n-1, accumulator*n);
    }
    
}

int main()
{
    int number;
    printf("Enter a number:");
    scanf("%d", &number);
    printf("The Factorial of %d is %d\n", number,tFact(number,1));
    return 0;
}