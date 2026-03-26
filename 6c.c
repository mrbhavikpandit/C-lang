// Develop a C program to demonstrate ftell,rewind, fseek.

#include <stdio.h>

int main()
{
    FILE *fp;
    int pos;

    fp = fopen("file.txt", "w+");

    fprintf(fp,"Hello World");

    pos = ftell(fp);
    printf("Current position: %d\n", pos);

    rewind(fp);
    printf("Position after rewind: %d\n", ftell(fp));

    fseek(fp, 6, SEEK_SET);
    printf("Position after fseek: %d\n", ftell(fp));

    fclose(fp);

    return 0;
}
