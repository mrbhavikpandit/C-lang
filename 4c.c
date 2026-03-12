#include <stdio.h>

struct student
{
    char name[50];
    int roll;
};

int main()
{
    struct student s[5];
    int i;

    for(i=0;i<5;i++)
    {
        printf("Enter name and roll: ");
        scanf("%s %d", s[i].name, &s[i].roll);
    }

    printf("\nStudent Details\n");

    for(i=0;i<5;i++)
    {
        printf("%s %d\n", s[i].name, s[i].roll);
    }

    return 0;
}