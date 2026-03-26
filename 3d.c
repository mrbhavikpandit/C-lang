// d. Develop a C Program to find factorial of a number.

#include <stdio.h>

int factorial(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return n * factorial(n-1);
}

int main()
{
    int n;

    printf("Enter number: ");
    scanf("%d",&n);

    printf("Factorial = %d", factorial(n));

    return 0;
}
