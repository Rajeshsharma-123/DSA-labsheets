#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int A[], int n)
{
    int i,j,least, pos, temp ;
    
    for ( i = 0; i < n-1; i++)
    {
        least = A[i];
        pos = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < least){
                least = A[j];
                pos = j;
            }
        }
        
    }
    if( i!= pos){
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[pos];
        A[pos] = temp;
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
    selectionSort(A, n);
    end = clock();
    display(A, n);
    diff = end - start;
    printf("the time taken is %f seconds\n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}


// 10 = the time taken is 0.000000 seconds
// 100 = the time taken is 0.000000 seconds
// 1000 = the time taken is 0.006000 seconds
// 10000 = the time taken is 0.042000 seconds
// 100000 = the time taken is 3.275000 seconds