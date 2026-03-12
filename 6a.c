#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("test.txt", "w");   // open file in write mode

    if(fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    printf("File opened successfully");

    fclose(fp);   // close file

    printf("\nFile closed successfully");

    return 0;
}