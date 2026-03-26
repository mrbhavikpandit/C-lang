//  Develop a C Program to reverse a string using Recursion.

#include <stdio.h>

void reverse(char str[], int i)
{
    if(str[i]=='\0')
        return;

    reverse(str, i+1);
    printf("%c", str[i]);
}

int main()
{
    char str[100];

    printf("Enter string: ");
    scanf("%s",str);

    reverse(str,0);

    return 0;
}
