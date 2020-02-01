#include <stdio.h>
#include <stdlib.h>

void fWelcome();
void fItemInputs();
void fOutput();
void fGoodbye();
int nPrice;
int nQuantity;


int main()
{
    fWelcome();
    fItemInputs();
    fOutput();
    fGoodbye();
    exit(0);
}

void fWelcome()
{
	puts("Welcome to \"Temple\" store\n");
}

void fItemInputs()
{
    printf("\tEnter item price: ");
    scanf("%d", &nPrice);
    if (nPrice <= 0)
    {
        printf("\n\tThis is not a valid item price.\n\tPlease run the program again\n");
        fGoodbye();
        exit(0);
    }

    printf("\tEnter quantity: ");
    scanf("%d", &nQuantity);
    if (nQuantity <= 0)
    {
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n");
        fGoodbye();
        exit(0);
    }

}

void fOutput()
{
    unsigned int nCost = nPrice * nQuantity;
    float nDiscount;

    printf("\n\tThe item price is: $%.1f\n", (float)nPrice);
    printf("\tThe order is: %d item(s)\n", nQuantity);
    printf("\tThe cost is: $%.1f\n", (float)(nCost));
    
    if (nQuantity >= 1 && nQuantity <= 49)
    {
        nDiscount = 0;
    }
    else if (nQuantity >= 50 && nQuantity <= 99)
    {
        nDiscount = 0.1;
    }
    else if (nQuantity >= 100 && nQuantity <= 149)
    {
        nDiscount = 0.15;
    }
    else 
    {
        nDiscount = 0.25;
    }

    printf("\tThe discount is: %.1f%%\n", (nDiscount * 100.0f));

    
    float nDiscountTotal = ((nDiscount * ((float)(nPrice))) * nQuantity);
    printf("\tThe discount amount is: $%.1f\n", (nDiscountTotal));

    float nTotal = nCost - nDiscountTotal;
    printf("\tThe total is $%.1f\n", (nTotal));

}

void fGoodbye()
{
    puts("\nThank You for using \"Temple\" store\n");
}