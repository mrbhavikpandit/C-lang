// Write a function that takes an integer as an argument and returns 1 if it is even and 0 if it is odd.

#include <stdio.h>

int checkEven(int n)
{
    if(n % 2 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int num = 6;

    if(checkEven(num))
        printf("Even");
    else
        printf("Odd");

    return 0;
}
