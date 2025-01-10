#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mergeSort(int A[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m + 1, r);
    }
}

void merge(int A[], int l, int m, int r)
{
    int i, j, k, B[100000];
    i = l;
    j = m;
    k = l;
    while (i < m && j <= r)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
            B[k++] = A[j++];
    }
    for (i = 0; i < m; i++, k++)
    {
        B[k] = A[i];
    }

    for (j = 0; j <= r; j++, k++)
    {
        B[k] = A[j];
    }
    for (k = 0; k <= r; k++)
    {
        A[k] = B[k];
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
    mergeSort(A, 0, n-1);
    end = clock();
    // display(A, n);
    diff = end - start;
    printf("the time taken is %f seconds\n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}

// 10 = the time taken is 0.000000 seconds
// 100 = the time taken is 0.000000 seconds
// 1000 = the time taken is 0.006000 seconds
// 10000 = the time taken is 0.132000 seconds
// 100000 = the time taken is 11.828000 seconds