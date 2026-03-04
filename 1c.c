 //write a program to calculate the length of a string using strlen().
#include <stdio.h>
#include <string.h>
 int main() {
    char str[150];
     printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 
    printf("Length = %lu\n", strlen(str));
     return 0;
}
