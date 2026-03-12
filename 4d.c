#include <stdio.h>

struct date
{
    int day, month, year;
};

struct employee
{
    char name[50];
    float salary;
    struct date join;
};

int main()
{
    struct employee e;

    printf("Enter name: ");
    scanf("%s", e.name);

    printf("Enter salary: ");
    scanf("%f",&e.salary);

    printf("Enter joining date (day month year): ");
    scanf("%d %d %d",&e.join.day,&e.join.month,&e.join.year);

    printf("\nEmployee Details\n");
    printf("Name: %s\n",e.name);
    printf("Salary: %.2f\n",e.salary);
    printf("Joining Date: %d/%d/%d",e.join.day,e.join.month,e.join.year);

    return 0;
}