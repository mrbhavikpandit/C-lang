#include <stdio.h>

int x = 10;   // Global variable

int main()
{
    int x = 20;   // Local variable

    printf("Local x = %d\n", x);
    printf("Global x = %d", ::x);

    return 0;
}
