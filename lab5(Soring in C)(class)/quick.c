#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j] i.e swaps pivot element and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
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
    // display(A, n);
    start = clock();
    quickSort(A, 0, n-1);
    end = clock();
    // display(A, n);
    diff = end - start;
    printf("the time taken is %f seconds\n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}

// 10 = the time taken is 0.000000 seconds
// 100 = the time taken is 0.000000 seconds
// 1000 = the time taken is 0.000000 seconds
// 10000 = the time taken is 0.000000 seconds
// 100000 = the time taken is 0.016000 seconds