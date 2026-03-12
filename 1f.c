#include <conio.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str_1[100] = "Welcome to the Earth";
    char str_2[100];
    int start, length, i;

    printf("Enter starting position: ");
    scanf("%d", &start);

    printf("Enter length of substring: ");
    scanf("%d", &length);

    for(i = 0; i < length; i++)
    {
        str_2[i] = str_1[start + i];
    }

    str_2[i] = '\0';

    printf("Given substring is: %s", str_2);

    return 0;
}
