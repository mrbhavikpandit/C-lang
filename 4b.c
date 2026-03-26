//  Create a structure Book with members title, author, and price. Write a program to assign values to these members and display them.

#include <stdio.h>

struct book
{
    char title[50];
    char author[50];
    float price;
};

int main()
{
    struct book b;

    printf("Enter title: ");
    scanf("%s", b.title);
    printf("Enter author: ");
    scanf("%s", b.author);
    printf("Enter price: ");
    scanf("%f", &b.price);

    printf("\nBook Details\n");
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Price: %.2f\n", b.price);

    return 0;
}
