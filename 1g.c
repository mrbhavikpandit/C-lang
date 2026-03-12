#include <stdio.h>

int compare(char a[], char b[])
{
    int i = 0;

    while(a[i] != '\0' && b[i] != '\0')
    {
        if(a[i] != b[i])
            return 0;   // strings are not equal
        i++;
    }

    if(a[i] == '\0' && b[i] == '\0')
        return 1;       // strings are equal
    else
        return 0;
}

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if(compare(str1, str2))
        printf("Strings are equal");
    else
        printf("Strings are not equal");

    return 0;
}
