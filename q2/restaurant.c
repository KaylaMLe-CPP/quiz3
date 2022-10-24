#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Incorrect number of arguments.\n");

        return 1;
    }

    // the first argument passed is the tax
    double tax = atof(argv[1]);
    // the second argument passed is the tip
    double tip = atof(argv[2]);

    double menuPrices[4] = {9.95, 4.55, 13.25, 22.35};
    char *menuItems[4] = {"Salad", "Soup", "Sandwich", "Pizza"};
    srand(time(NULL));
    int item = rand() % 4;

    printf("\nSubtotal:\n%s\t$%.2f\n\n", menuItems[item], menuPrices[item]);

    double taxAmt = menuPrices[item] * tax;
    printf("Tax (%%%.2f): $%.2f\nTip: $%.2f\n", (tax * 100), taxAmt, tip);

    double total = menuPrices[item] + taxAmt + tip;
    printf("Total: $%.2f\n", total);

    return 0;
}