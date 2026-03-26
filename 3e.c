//e. Develop a C Program to find sum of natural numbers using Recursion.

#include <stdio.h>
int sum(int n)
{
    if(n==0)
        return 0;
    else
        return n + sum(n-1);
}

int main()
{
    int n;

    printf("Enter number: ");
    scanf("%d",&n);

    printf("Sum = %d", sum(n));

    return 0;
}
