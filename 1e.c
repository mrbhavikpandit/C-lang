// write a program to concatenate two strings using strcat().
#include <stdio.h>
#include <string.h>
 int main()
{
    char str1[100]="bhsvik";
    char str2[100]="pandit";
    strcat(str1, str2);
    printf("%s", str1);
     return 0;
}
