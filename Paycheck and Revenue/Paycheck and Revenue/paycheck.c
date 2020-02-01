
#include <stdio.h>
#include <stdlib.h>

void welcome();
void employeeInput();
void paycheckCalculator();
void calculateOvertime();
void goodbye();
int employeeNumber = 0;
int hourlySalary = 0;
int weeklyTime = 0;

int smain()
{

	welcome();
	employeeInput();
	paycheckCalculator();
	goodbye();
	exit(0);
}

void welcome()
{
	puts("Welcome to \"TEMPLE HUMAN RESOURCES\"\n");
}

void employeeInput()
{
	
	printf("\tEnter Employee Number: ");
	scanf("%d", &employeeNumber);
	if (employeeNumber <= 0)
	{
		printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\n");
		goodbye();
		exit(0);
	}
		
	
	printf("\tEnter Hourly Salary: ");
	scanf("%d", &hourlySalary);
	if (hourlySalary <= 0)
	{
		printf("\n\tThis is not a valid Hourly Salary.\n\tPlease run the program again\n\n");
		goodbye();
		exit(0);
	}

	
	printf("\tEnter Weekly Time: ");
	scanf("%d", &weeklyTime);
	if (weeklyTime < 0)
	{
		printf("\n\tThis is not a valid Weekly Time.\n\tPlease run the program again\n\n");
		goodbye();
		exit(0);
	}

	printf("\t==============================\n");
}

void paycheckCalculator()
{
	printf("\tEmployee #: ");
	printf("%d\n", employeeNumber);

	printf("\tHourly Salary: ");
	printf("$%.1f\n", (float)hourlySalary);

	printf("\tWeekly Time: ");
	printf("%.1f\n", (float)weeklyTime);

	calculateOvertime();
	 
	printf("\t==============================\n");

	
}

void calculateOvertime()
{
	if (weeklyTime > 40)
	{
		unsigned int regularPay = hourlySalary * 40;
		printf("\tRegular Pay: ");
		printf("$%.1f\n", (float)regularPay);

		unsigned int overtimePay = (weeklyTime - 40) * (hourlySalary * 1.5);
		printf("\tOvertime Pay: ");
		printf("$%.1f\n", (float)overtimePay);

		printf("\tNet Pay: ");
		printf("$%.1f\n", (float)regularPay + (float)overtimePay);
	}
	else
	{
		unsigned int regularPay = hourlySalary * weeklyTime;
		printf("\tRegular Pay: ");
		printf("$%.1f\n", (float)regularPay);

		printf("\tOvertime Pay: None\n");

		printf("\tNet Pay: ");
		printf("$%.1f\n", (float)regularPay);
	}
}

void goodbye()
{
	puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
}
