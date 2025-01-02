#include<stdio.h>
void TOH(char source, char destination, char temporary, int n)
{
    if(n==1)
    {
        printf("Move disc %d from %c to %c\n",n,source,destination);
    }
    else
    {
        TOH(source,temporary,destination,n-1);
        printf("Move disc %d from %c to %c\n",n,source,destination);
        TOH(temporary,destination,source,n-1);
    }
}


int main(){
    int n;
    printf("Enter number of Pegs:");
    scanf("%d",&n);
    TOH('A','C','B',n);
    return 0;
}


