/*
Marinos Rrapaj
February 1, 2020
CIS2107_Lab02_Paycheck_and_Revenue

Statement: To write a program in C called revenue which calculates the revenue from a sale based on the price per unit
and the total amount of units per sale. Furthermore it also calculates discouts and the customer receives and incorporates
that into the final revenue amounts. The discounts are as follows: 
    0%  for 1-49 units                                                            
    10% for 50-99 units
    15% for 100-149 units
    25% for 150+ units. 
*/
#include <stdio.h>
#include <stdlib.h>

void fWelcome();
void fItemInputs();
void fOutput();
void fGoodbye();
int nPrice;
int nQuantity;


int bmain()
{
    fWelcome();
    fItemInputs();
    fOutput();
    fGoodbye();
}

void fWelcome()
{
	puts("Welcome to \"Temple\" store\n");
}

void fItemInputs()
{
    printf("\tEnter item price: ");
    scanf("%d", &nPrice);

    //catch error if price is equal or less than 0
    if (nPrice <= 0)
    {
        printf("\n\tThis is not a valid item price.\n\tPlease run the program again\n");
        fGoodbye();
    }

    printf("\tEnter quantity: ");
    scanf("%d", &nQuantity);

    //catch error if quantity is equal or less than 0
    if (nQuantity <= 0)
    {
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n");
        fGoodbye();
    }

}

void fOutput()
{
    unsigned int nCost = nPrice * nQuantity;
    float nDiscount;

    printf("\n\tThe item price is: $%.1f\n", (float)nPrice);
    printf("\tThe order is: %d item(s)\n", nQuantity);
    printf("\tThe cost is: $%.1f\n", (float)(nCost));
    
    //set discount based on the quantity of the items
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

    //find total discount by multiplying the discount by the total price, then by the quantity
    float nDiscountTotal = ((nDiscount * ((float)(nPrice))) * nQuantity);
    printf("\tThe discount amount is: $%.1f\n", (nDiscountTotal));

    //subtract the discount from the cost
    float nTotal = nCost - nDiscountTotal;
    printf("\tThe total is $%.1f\n", (nTotal));

}

void fGoodbye()
{
    puts("\nThank You for using \"Temple\" store\n");
    exit(0);
}
