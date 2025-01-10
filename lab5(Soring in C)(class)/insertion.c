#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int A[], int n)
{
    int temp, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        temp = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > temp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[100000], n, i;
    srand(time(NULL));
    clock_t start, end, diff;
    printf("Enter n:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        A[i] = rand();
    }
    display(A, n);
    start = clock();
    insertionSort(A, n);
    end = clock();
    display(A, n);
    diff = end - start;
    printf("the time taken is %f seconds\n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}


// 10 = the time taken is 0.000000 seconds
// 100 = the time taken is 0.000000 seconds
// 1000 = the time taken is 0.000000 seconds
// 10000 = the time taken is 0.028000 seconds
// 100000 = the time taken is 2.721000 seconds