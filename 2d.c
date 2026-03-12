#include <stdio.h>

int length(char str[])
{
    int i = 0;

    while(str[i] != '\0')
        i++;

    return i;
}

int main()
{
    char str[] = "Hello";

    printf("Length = %d", length(str));
    return 0;
}
