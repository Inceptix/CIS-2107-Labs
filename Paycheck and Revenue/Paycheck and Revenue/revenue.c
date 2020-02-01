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
        printf("\tThis is not a valid item price.\nPlease run the program again");
        goodbye();
        exit(0);
    }

    printf("\tEnter quantity: ");
    scanf("%d", &nQuantity);
    if (nQuantity >= 0)
    {
        printf("\tThis is not a valid quantity order.\nPlease run the program again");
        goodbye();
        exit(0);
    }

}

void fOutput()
{
    unsigned int nCost = nPrice + nQuantity;
    double nDiscount;

    printf("\tThe item price is: $%d\n", nPrice);
    printf("\tThe order is: %d item(s)\n", nQuantity);
    printf("\tThe cost is: $%d\n", nCost);
    
    if (nQuantity >= 1 && nQuantity <= 49)
    {
        nDiscount = 1;
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

    printf("\tThe discount amount is: %.1f\n", (nDiscount * 100));

    
    printf("\nThe total is %.1f\n", (nCost - nDiscount));
}

void fGoodbye()
{
    puts("Thank you for using \"Temple\" store\n");
}