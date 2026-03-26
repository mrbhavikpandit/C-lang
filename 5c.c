// c. Write a program to demonstrate accessing array elements using a pointer.

#include <stdio.h>

int main()
{
    int arr[5] = {10,20,30,40,50};
    int *p = arr;
    int i;

    for(i=0;i<5;i++)
        printf("%d ", *(p+i));

    return 0;
}
