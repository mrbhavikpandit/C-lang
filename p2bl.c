#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100
#define MAX_CART 100
#define TAX_RATE 0.05

// ========== STRUCTURES ==========
struct Product
{
    int code;
    char name[50];
    float price;
};

struct CartItem
{
    char name[50];
    int quantity;
    float price;
    float cost;
};

// ========== GLOBAL VARIABLES ==========
struct Product products[MAX_PRODUCTS] = {
    {1, "Rice (1kg)", 60},
    {2, "Milk (1L)", 25},
    {3, "Bread", 30},
    {4, "Eggs (12 pcs)", 70},
    {5, "Sugar (1kg)", 45},
    {6, "Wheat Flour (1kg)", 50},
    {7, "Butter (200g)", 90},
    {8, "Cheese (200g)", 120},
    {9, "Salt (1kg)", 20},
    {10, "Cooking Oil (1L)", 180},
    {11, "Tea (100g)", 80},
    {12, "Coffee (100g)", 150},
    {13, "Biscuits (Pack)", 40},
    {14, "Cereal (500g)", 130},
    {15, "Juice (1L)", 60}};

int product_count = 15;

// ========== FUNCTION DECLARATIONS ==========
void displayProducts();
void addProduct();
void generateBill();
void saveBillToFile(struct CartItem cart[], int cart_count, float subtotal, float tax, float discount, float total);

// ========== MAIN FUNCTION ==========
int main()
{
    int choice;

    while (1)
    {
        printf("\n========== ABC SUPER MARKET ==========\n");
        printf("1. New Billing\n");
        printf("2. Add New Product\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            generateBill();
            break;
        case 2:
            addProduct();
            break;
        case 3:
            printf("Thank You! Visit Again!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}

// ========== DISPLAY PRODUCTS ==========
void displayProducts()
{
    printf("\nAvailable Products:\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < product_count; i++)
    {
        printf("%d. %-25s ₹%.2f\n",
               products[i].code,
               products[i].name,
               products[i].price);
    }
}

// ========== ADD NEW PRODUCT ==========
void addProduct()
{
    if (product_count >= MAX_PRODUCTS)
    {
        printf("Product limit reached!\n");
        return;
    }

    printf("Enter Product Code: ");
    scanf("%d", &products[product_count].code);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", products[product_count].name);

    printf("Enter Product Price: ");
    scanf("%f", &products[product_count].price);

    product_count++;
    printf("Product added successfully!\n");
}

// ========== GENERATE BILL ==========
void generateBill()
{
    struct CartItem cart[MAX_CART];
    int cart_count = 0;
    int code, quantity;
    float subtotal = 0;

    while (1)
    {
        displayProducts();

        printf("\nEnter Item Code (0 to Finish): ");
        scanf("%d", &code);

        if (code == 0)
            break;

        int found = 0;

        for (int i = 0; i < product_count; i++)
        {
            if (products[i].code == code)
            {
                found = 1;

                if (cart_count >= MAX_CART)
                {
                    printf("Cart limit reached!\n");
                    break;
                }

                printf("Enter Quantity: ");
                scanf("%d", &quantity);

                if (quantity <= 0)
                {
                    printf("Invalid quantity!\n");
                    break;
                }

                float cost = products[i].price * quantity;
                subtotal += cost;

                strcpy(cart[cart_count].name, products[i].name);
                cart[cart_count].quantity = quantity;
                cart[cart_count].price = products[i].price;
                cart[cart_count].cost = cost;

                cart_count++;
                printf("Item added to cart!\n");
                break;
            }
        }

        if (!found)
        {
            printf("Invalid Product Code!\n");
        }
    }

    float tax = subtotal * TAX_RATE;
    float discount = 0;

    if (subtotal > 1000)
        discount = subtotal * 0.10;

    float total = subtotal + tax - discount;

    // ===== GET CURRENT DATE & TIME =====
    time_t t;
    time(&t);

    // ===== PRINT BILL =====
    printf("\n================= BILL RECEIPT =================\n");
    printf("Date & Time: %s", ctime(&t));
    printf("%-25s %-10s %-10s %-10s\n", "Item", "Qty", "Price", "Total");
    printf("------------------------------------------------\n");

    for (int i = 0; i < cart_count; i++)
    {
        printf("%-25s %-10d %-10.2f %-10.2f\n",
               cart[i].name,
               cart[i].quantity,
               cart[i].price,
               cart[i].cost);
    }

    printf("------------------------------------------------\n");
    printf("Subtotal: ₹%.2f\n", subtotal);
    printf("Tax (5%%): ₹%.2f\n", tax);
    printf("Discount: ₹%.2f\n", discount);
    printf("Grand Total: ₹%.2f\n", total);
    printf("================================================\n");

    saveBillToFile(cart, cart_count, subtotal, tax, discount, total);
}

// ========== SAVE BILL TO FILE ==========
void saveBillToFile(struct CartItem cart[], int cart_count,
                    float subtotal, float tax,
                    float discount, float total)
{

    FILE *file = fopen("bill.txt", "w");

    if (file == NULL)
    {
        printf("Error saving bill!\n");
        return;
    }

    time_t t;
    time(&t);

    fprintf(file, "========== ABC SUPER MARKET ==========\n");
    fprintf(file, "Date & Time: %s\n", ctime(&t));
    fprintf(file, "%-25s %-10s %-10s %-10s\n", "Item", "Qty", "Price", "Total");

    for (int i = 0; i < cart_count; i++)
    {
        fprintf(file, "%-25s %-10d %-10.2f %-10.2f\n",
                cart[i].name,
                cart[i].quantity,
                cart[i].price,
                cart[i].cost);
    }

    fprintf(file, "--------------------------------------\n");
    fprintf(file, "Subtotal: %.2f\n", subtotal);
    fprintf(file, "Tax: %.2f\n", tax);
    fprintf(file, "Discount: %.2f\n", discount);
    fprintf(file, "Grand Total: %.2f\n", total);
    fprintf(file, "======================================\n");

    fclose(file);
    printf("Bill saved to file successfully!\n");
}