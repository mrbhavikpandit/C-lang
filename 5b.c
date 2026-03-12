#include <stdio.h>

int main()
{
    int x = 5;
    int *p = &x;
    int **pp = &p;

    printf("Value of x = %d\n", x);
    printf("Address of x = %p\n", &x);
    printf("Value using pointer to pointer = %d", **pp);

    return 0;
}