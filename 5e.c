#include <stdio.h>

struct student
{
    char name[50];
    int roll;
};

int main()
{
    struct student s = {"Rahul",101};
    struct student *p = &s;

    printf("Name: %s\n", p->name);
    printf("Roll: %d", p->roll);

    return 0;
}