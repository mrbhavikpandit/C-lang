/*
 * ============================================================
 *  ABC Super Market - Billing System (Presentation-Ready)
 *  Features:
 *    - Data persistence: product list saved/loaded via products.dat
 *    - ANSI color-coded UI (Blue headers, Green success, Red errors)
 *    - Screen clearing between menu actions for a clean interface
 *    - Input validation for prices and quantities
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ========== CONSTANTS ========== */
#define MAX_PRODUCTS    100
#define MAX_CART        100
#define TAX_RATE        0.05
#define DISCOUNT_RATE   0.10
#define DISCOUNT_LIMIT  1000.0
#define PRODUCTS_FILE   "products.dat"
#define BILL_FILE       "bill.txt"

/* ========== ANSI COLOR CODES ========== */
#define COLOR_RESET  "\033[0m"
#define COLOR_BLUE   "\033[1;34m"   /* Headers / titles        */
#define COLOR_GREEN  "\033[1;32m"   /* Success messages        */
#define COLOR_RED    "\033[1;31m"   /* Error / warning messages */
#define COLOR_CYAN   "\033[1;36m"   /* Prompts                 */

/* Clear the terminal in a cross-platform way */
#ifdef _WIN32
#define CLEAR_SCREEN() system("cls")
#else
#define CLEAR_SCREEN() system("clear")
#endif

/* ========== STRUCTURES ========== */
struct Product
{
    int   code;
    char  name[50];
    float price;
};

struct CartItem
{
    char  name[50];
    int   quantity;
    float price;
    float cost;
};

/* ========== GLOBAL VARIABLES ========== */
/* Default product catalogue – used only when no saved file is found */
struct Product products[MAX_PRODUCTS] = {
    {1,  "Rice (1kg)",        60.0f},
    {2,  "Milk (1L)",         25.0f},
    {3,  "Bread",             30.0f},
    {4,  "Eggs (12 pcs)",     70.0f},
    {5,  "Sugar (1kg)",       45.0f},
    {6,  "Wheat Flour (1kg)", 50.0f},
    {7,  "Butter (200g)",     90.0f},
    {8,  "Cheese (200g)",    120.0f},
    {9,  "Salt (1kg)",        20.0f},
    {10, "Cooking Oil (1L)", 180.0f},
    {11, "Tea (100g)",        80.0f},
    {12, "Coffee (100g)",    150.0f},
    {13, "Biscuits (Pack)",   40.0f},
    {14, "Cereal (500g)",    130.0f},
    {15, "Juice (1L)",        60.0f}
};

int product_count = 15;

/* ========== FUNCTION DECLARATIONS ========== */
void loadProducts();
void saveProducts();
void displayProducts();
void addProduct();
void generateBill();
void saveBillToFile(struct CartItem cart[], int cart_count,
                    float subtotal, float tax,
                    float discount, float total);

/* ========== MAIN FUNCTION ========== */
int main()
{
    int choice;

    /* Load the persisted product catalogue on startup */
    loadProducts();

    while (1)
    {
        CLEAR_SCREEN();

        /* Blue header */
        printf(COLOR_BLUE
               "\n  ╔══════════════════════════════════╗\n"
               "  ║       ABC SUPER MARKET           ║\n"
               "  ╚══════════════════════════════════╝\n"
               COLOR_RESET);

        printf(COLOR_CYAN
               "  1. New Billing\n"
               "  2. Add New Product\n"
               "  3. Exit\n"
               COLOR_RESET);

        printf(COLOR_CYAN "  Enter your choice: " COLOR_RESET);

        if (scanf("%d", &choice) != 1)
        {
            /* Flush invalid non-numeric input */
            while (getchar() != '\n');
            printf(COLOR_RED "  Invalid input! Please enter a number.\n" COLOR_RESET);
            continue;
        }

        switch (choice)
        {
        case 1:
            generateBill();
            break;
        case 2:
            addProduct();
            break;
        case 3:
            printf(COLOR_GREEN "\n  Thank You! Visit Again!\n\n" COLOR_RESET);
            exit(0);
        default:
            printf(COLOR_RED "  Invalid choice! Try again.\n" COLOR_RESET);
        }

        /* Pause so the user can read any output before clearing */
        printf(COLOR_CYAN "\n  Press Enter to continue..." COLOR_RESET);
        while (getchar() != '\n');   /* consume newline left by scanf */
        getchar();                   /* wait for the user to press Enter */
    }
}

/* ========== LOAD PRODUCTS FROM FILE ========== */
/* Reads the binary products.dat file.
 * If the file does not exist, the default catalogue is kept. */
void loadProducts()
{
    FILE *file = fopen(PRODUCTS_FILE, "rb");

    if (file == NULL)
    {
        /* First run – no saved data yet; default catalogue is already loaded */
        return;
    }

    int saved_count = 0;

    if (fread(&saved_count, sizeof(int), 1, file) == 1 &&
        saved_count > 0 && saved_count <= MAX_PRODUCTS)
    {
        int read = (int)fread(products, sizeof(struct Product), (size_t)saved_count, file);

        if (read == saved_count)
            product_count = saved_count;
    }

    fclose(file);
}

/* ========== SAVE PRODUCTS TO FILE ========== */
/* Persists the current products array to products.dat so that
 * any products added during this session survive program restarts. */
void saveProducts()
{
    FILE *file = fopen(PRODUCTS_FILE, "wb");

    if (file == NULL)
    {
        printf(COLOR_RED "  Warning: Could not save product list to file.\n" COLOR_RESET);
        return;
    }

    fwrite(&product_count, sizeof(int), 1, file);
    fwrite(products, sizeof(struct Product), (size_t)product_count, file);

    fclose(file);
}

/* ========== DISPLAY PRODUCTS ========== */
void displayProducts()
{
    printf(COLOR_BLUE
           "\n  %-6s %-26s %s\n"
           "  ------------------------------------------\n"
           COLOR_RESET,
           "Code", "Product Name", "Price (Rs.)");

    for (int i = 0; i < product_count; i++)
    {
        printf("  %-6d %-26s %.2f\n",
               products[i].code,
               products[i].name,
               products[i].price);
    }

    printf("  ------------------------------------------\n");
}

/* ========== ADD NEW PRODUCT ========== */
/* Validates that the price is a positive number before accepting it. */
void addProduct()
{
    CLEAR_SCREEN();
    printf(COLOR_BLUE "\n  --- Add New Product ---\n" COLOR_RESET);

    if (product_count >= MAX_PRODUCTS)
    {
        printf(COLOR_RED "  Product limit reached! Cannot add more products.\n" COLOR_RESET);
        return;
    }

    /* Product code */
    printf(COLOR_CYAN "  Enter Product Code: " COLOR_RESET);
    if (scanf("%d", &products[product_count].code) != 1)
    {
        while (getchar() != '\n');
        printf(COLOR_RED "  Invalid code! Product not added.\n" COLOR_RESET);
        return;
    }

    /* Product name */
    printf(COLOR_CYAN "  Enter Product Name: " COLOR_RESET);
    if (scanf(" %49[^\n]", products[product_count].name) != 1)
    {
        while (getchar() != '\n');
        printf(COLOR_RED "  Invalid name! Product not added.\n" COLOR_RESET);
        return;
    }

    /* Product price – must be positive */
    float price = 0.0f;
    printf(COLOR_CYAN "  Enter Product Price: " COLOR_RESET);
    if (scanf("%f", &price) != 1 || price <= 0.0f)
    {
        while (getchar() != '\n');
        printf(COLOR_RED "  Invalid price! Price must be a positive number. Product not added.\n" COLOR_RESET);
        return;
    }

    products[product_count].price = price;
    product_count++;

    /* Persist the updated catalogue immediately */
    saveProducts();

    printf(COLOR_GREEN "  Product added successfully!\n" COLOR_RESET);
}

/* ========== GENERATE BILL ========== */
void generateBill()
{
    struct CartItem cart[MAX_CART];
    int   cart_count = 0;
    int   code;
    int   quantity;
    float subtotal = 0.0f;

    while (1)
    {
        CLEAR_SCREEN();
        displayProducts();

        printf(COLOR_CYAN "\n  Enter Item Code (0 to finish): " COLOR_RESET);

        if (scanf("%d", &code) != 1)
        {
            while (getchar() != '\n');
            printf(COLOR_RED "  Invalid input! Please enter a numeric code.\n" COLOR_RESET);
            continue;
        }

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
                    printf(COLOR_RED "  Cart limit reached!\n" COLOR_RESET);
                    break;
                }

                printf(COLOR_CYAN "  Enter Quantity: " COLOR_RESET);
                if (scanf("%d", &quantity) != 1 || quantity <= 0)
                {
                    while (getchar() != '\n');
                    printf(COLOR_RED "  Invalid quantity! Must be a positive number.\n" COLOR_RESET);
                    break;
                }

                float cost = products[i].price * (float)quantity;
                subtotal += cost;

                strcpy(cart[cart_count].name,  products[i].name);
                cart[cart_count].quantity = quantity;
                cart[cart_count].price    = products[i].price;
                cart[cart_count].cost     = cost;
                cart_count++;

                printf(COLOR_GREEN "  Item added to cart!\n" COLOR_RESET);
                break;
            }
        }

        if (!found)
            printf(COLOR_RED "  Invalid Product Code! Please try again.\n" COLOR_RESET);
    }

    /* ===== CALCULATIONS ===== */
    float tax      = subtotal * TAX_RATE;
    float discount = 0.0f;

    if (subtotal > DISCOUNT_LIMIT)
        discount = subtotal * DISCOUNT_RATE;
    float total    = subtotal + tax - discount;

    /* ===== GET CURRENT DATE & TIME ===== */
    time_t t;
    time(&t);

    /* ===== PRINT BILL ===== */
    CLEAR_SCREEN();
    printf(COLOR_BLUE
           "\n  ╔══════════════════════════════════════════════════╗\n"
           "  ║              ABC SUPER MARKET                   ║\n"
           "  ║                  BILL RECEIPT                   ║\n"
           "  ╚══════════════════════════════════════════════════╝\n"
           COLOR_RESET);

    printf("  Date & Time : %s", ctime(&t));

    printf(COLOR_BLUE
           "  %-26s %-8s %-10s %-10s\n"
           "  --------------------------------------------------\n"
           COLOR_RESET,
           "Item", "Qty", "Price", "Total");

    for (int i = 0; i < cart_count; i++)
    {
        printf("  %-26s %-8d %-10.2f %-10.2f\n",
               cart[i].name,
               cart[i].quantity,
               cart[i].price,
               cart[i].cost);
    }

    printf("  --------------------------------------------------\n");
    printf("  Subtotal                              : Rs. %.2f\n", subtotal);
    printf("  Tax (5%%)                               : Rs. %.2f\n", tax);
    printf("  Discount (10%% on orders above Rs.1000) : Rs. %.2f\n", discount);
    printf(COLOR_GREEN
           "  Grand Total                           : Rs. %.2f\n"
           COLOR_RESET, total);
    printf("  ==================================================\n");

    saveBillToFile(cart, cart_count, subtotal, tax, discount, total);
}

/* ========== SAVE BILL TO FILE ========== */
/* Appends the current bill to bill.txt so past receipts are not lost. */
void saveBillToFile(struct CartItem cart[], int cart_count,
                    float subtotal, float tax,
                    float discount, float total)
{
    FILE *file = fopen(BILL_FILE, "a");

    if (file == NULL)
    {
        printf(COLOR_RED "  Error: Could not save bill to file!\n" COLOR_RESET);
        return;
    }

    time_t t;
    time(&t);

    fprintf(file, "\n========== ABC SUPER MARKET ==========\n");
    fprintf(file, "Date & Time: %s\n", ctime(&t));
    fprintf(file, "%-26s %-8s %-10s %-10s\n", "Item", "Qty", "Price", "Total");
    fprintf(file, "--------------------------------------\n");

    for (int i = 0; i < cart_count; i++)
    {
        fprintf(file, "%-26s %-8d %-10.2f %-10.2f\n",
                cart[i].name,
                cart[i].quantity,
                cart[i].price,
                cart[i].cost);
    }

    fprintf(file, "--------------------------------------\n");
    fprintf(file, "Subtotal     : %.2f\n", subtotal);
    fprintf(file, "Tax (5%%)     : %.2f\n", tax);
    fprintf(file, "Discount     : %.2f\n", discount);
    fprintf(file, "Grand Total  : %.2f\n", total);
    fprintf(file, "======================================\n");

    fclose(file);
    printf(COLOR_GREEN "  Bill saved to '" BILL_FILE "' successfully!\n" COLOR_RESET);
}