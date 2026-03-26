//  Develop a C Program to demomstrate calloc() , malloc() and free().


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    int i;

    // malloc
    p = (int*) malloc(5 * sizeof(int));

    printf("Enter 5 numbers (malloc):\n");
    for(i=0;i<5;i++)
        scanf("%d",&p[i]);

    printf("Numbers are:\n");
    for(i=0;i<5;i++)
        printf("%d ",p[i]);

    free(p);   // free memory

    // calloc
    q = (int*) calloc(5, sizeof(int));

    printf("\nEnter 5 numbers (calloc):\n");
    for(i=0;i<5;i++)
        scanf("%d",&q[i]);

    printf("Numbers are:\n");
    for(i=0;i<5;i++)
        printf("%d ",q[i]);

    free(q);   // free memory

    return 0;
}
