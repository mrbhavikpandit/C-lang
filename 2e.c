// Write a program with a global variable and a local variable with the same name. Demonstrate how to access both.

#include <stdio.h>

int x = 10;   // Global variable

int main()
{
    int x = 20;   // Local variable

    printf("Local x = %d\n", x);
    printf("Global x = %d", ::x);

    return 0;
}
