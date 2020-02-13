/*
Marinos Rrapaj
February 1, 2020
CIS2107_Lab02_Paycheck_and_Revenue

Statement: To write a program in C called paycheck that calculated the paycheck for a Temple employee
based on their weekly hours and the rate per hour. The goal is also to figure out if the employee
worked overtime (more than 40 hours) and multiply their hourly rate by x1.5 for any hours above 40.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define PIN 3014
#define WITHDRAWAL_LIMIT 1000
#define DEPOSIT_LIMIT 10000

void ATMwelcome();
void ATMgoodbye();

int dUserPin;
int dAttempts;
int dReceipt;
int dWithdrawalAttempt = 0;
int dDepositAttempt = 0;

int dBalance = 5000;
int dCashWithdrawalTotal = 0;
int dCashDepositTotal = 0;

int dTranscation = 0;

void displayMenu();
void balance();
void cashWithdrawal(int x);
void cashDeposit(int x);


int cmain()
{
	ATMwelcome();
	int dWithdrawalAmount;
	int dDepositAmount;

	bool bIsMenu = true;
	while (bIsMenu)
	{
		int dMenu;

		displayMenu();

		scanf("%d", &dMenu);

		switch (dMenu)
		{

		case 1:
			balance();
			break;

		case 2: 
			
			printf("Please enter the amount that you would like to withdraw in multiplies of 20\n");
			scanf("%d", &dWithdrawalAmount);
			cashWithdrawal(dWithdrawalAmount);
			break;

		case 3:
			
			printf("Please enter the amount that you would like to deposit. Coins not accepted.\n");
			scanf("%d", &dDepositAmount);
			cashDeposit(dDepositAmount);
			break;

		case 4:
			ATMgoodbye();
			exit(0);
		default:
			exit(0);
			break;
		}
	}
}

void cashWithdrawal(int x)
{
	
	if (dCashWithdrawalTotal > WITHDRAWAL_LIMIT || (x + dCashWithdrawalTotal > WITHDRAWAL_LIMIT))
	{
		printf("Withdrawal value exceeds limit. $%d left to withdraw\n", (WITHDRAWAL_LIMIT - dCashWithdrawalTotal));
		
		return;
	}

	if (x <= 0 || (x % 20 != 0))
	{
		printf("Invalid withdrawal amount. Try again.\n");
		dWithdrawalAttempt++;
		if (dWithdrawalAttempt >= 3)
		{
			printf("Too many wrong entries. Please try again later. Goodbye.\n");
			exit(0);
			return;
		}
		return;
	}

	dBalance -= x;
	dCashWithdrawalTotal += x;
	//debug
	printf("Balance is: %d\n", dBalance);
	//print recepit
	printf("Press 1 for receipt or press 2 to continue: ");
	scanf("%d", &dReceipt);

	if (dReceipt == 1)
	{
		printf("Printing recepit...\n");
		dTranscation++;
		dWithdrawalAttempt = 0;
		return;
	}
	else
	{
		dTranscation++;
		dWithdrawalAttempt = 0;
		return;
	}
}

void cashDeposit(int x)
{
	if (dCashDepositTotal > DEPOSIT_LIMIT || (x + dCashDepositTotal > DEPOSIT_LIMIT))
	{
		printf("Deposit value exceeds limit. $%d left to deposit\n", (DEPOSIT_LIMIT - dCashDepositTotal));

		return;
	}

	if (x <= 0)
	{
		printf("Invalid deposit amount. Try again.\n");
		dDepositAttempt++;
		if (dDepositAttempt >= 3)
		{
			printf("Too many wrong entries. Please try again later. Goodbye.\n");
			exit(0);
			return;
		}
		return;
	}

	dBalance += x;
	dCashDepositTotal += x;
	//debug
	printf("Balance is: %d\n", dBalance);
	//print recepit
	printf("Press 1 for receipt or press 2 to continue: ");
	scanf("%d", &dReceipt);

	if (dReceipt == 1)
	{
		printf("Printing recepit...\n");
		dTranscation++;
		dDepositAttempt = 0;
		return;
	}
	else
	{
		dTranscation++;
		dDepositAttempt = 0;
		return;
	}
		
}

void ATMgoodbye()
{
	printf("The total amount of transactions today is %d.\nThank you for using Temple ATM.\nGoodbye.\n", dTranscation);
	return;
}

void displayMenu()
{
	printf("Please enter a number 1-4 to access the appropriate menu:\n1. Balance\n2. Cash Withdrawal\n3. Cash Deposition\n4. Quit\n");
	return;
}

void ATMwelcome()
{
	printf("Welcome to Temple ATM. Please enter your PIN: ");
	scanf("%d", &dUserPin);

	if (dUserPin != PIN && dAttempts < 3)
	{
		dAttempts++;
		if (dAttempts >= 3)
		{
			printf("This account has been locked. Please try again later. The program will now terminate.\n");
			exit(0);
		}

		printf("Incorrect PIN. Please try again. %d out of 3 attempts.\n", dAttempts);
		ATMwelcome();
	}

	if (dUserPin == PIN)
		return;

}

void balance()
{
	printf("Current balance is $%d\n", dBalance);
	return;
}