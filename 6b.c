//  Develop a C Program to demonstrate fprintf() and fscanf().

#include <stdio.h>

int main()
{
    FILE *fp;
    char name[50];
    int age;

    fp = fopen("data.txt", "w");

    fprintf(fp, "John 21");   // writing data
    fclose(fp);

    fp = fopen("data.txt", "r");

    fscanf(fp, "%s %d", name, &age);   // reading data

    printf("Name: %s\nAge: %d", name, age);

    fclose(fp);

    return 0;
}
