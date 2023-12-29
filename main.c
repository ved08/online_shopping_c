#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Item items[] = {
    {"Shirt", 100, 999},
    {"Trousers", 75, 599},
    {"Jacket", 40, 1299},
    {"Hoodie", 40, 1100},
    {"Shorts", 100, 499},
};

void addToCart(struct Item cart[], int *cartSize) {
    int choice, quantity;

    printf("Available Items:\n");
    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
        printf("%d. %s - Rs.%.2f\n", i + 1, items[i].name, items[i].price);
    }

    printf("Enter the item number to add to cart: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > sizeof(items) / sizeof(items[0])) {
        printf("Invalid choice!\n");
        return;
    }

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("Invalid quantity!\n");
        return;
    }
    strcpy(cart[*cartSize].name, items[choice - 1].name);
    cart[*cartSize].quantity = quantity;
    cart[*cartSize].price = items[choice - 1].price;
    (*cartSize)++;

    printf("Item added to cart!\n");
}

void checkout(struct Item cart[], int cartSize) {
    float total = 0;

    printf("\nItems in Cart:\n");
    printf("-------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Item", "Quantity", "Total");
    printf("-------------------------------------------\n");

    for (int i = 0; i < cartSize; i++) {
        printf("%-20s %-10d Rs.%-9.2f\n", cart[i].name, cart[i].quantity, cart[i].quantity * cart[i].price);
        total += cart[i].quantity * cart[i].price;
    }

    printf("-------------------------------------------\n");
    printf("Total: Rs.%.2f\n", total);
}

int main() {
    struct Item cart[100];
    int cartSize = 0;

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add to Cart\n");
        printf("2. Checkout\n");
        printf("3. Buy\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addToCart(cart, &cartSize);
                break;
            case 2:
                checkout(cart, cartSize);
                break;
            case 3:
                printf("Thank you for shopping with us! See you again!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}


