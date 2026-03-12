#include <stdio.h>

int square(int n)
{
    return n * n;
}

int main()
{
    int num = 5;
    printf("Square = %d", square(num));
    return 0;
}
