//  Develop a C Program to find whether a number is Prime or not.

#include <stdio.h>

int main()
{
    int n, i, flag=0;

    printf("Enter number: ");
    scanf("%d",&n);

    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
        printf("Prime Number");
    else
        printf("Not Prime");

    return 0;
}
