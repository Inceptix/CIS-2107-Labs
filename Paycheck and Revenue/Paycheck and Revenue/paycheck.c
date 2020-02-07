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

void welcome();
void employeeInput();
void paycheckCalculator();
void calculateOvertime();
void goodbye();
int employeeNumber = 0;
int hourlySalary = 0;
int weeklyTime = 0;

int amain()
{

	welcome();
	employeeInput();
	paycheckCalculator();
	goodbye();
	
}

void welcome()
{
	puts("Welcome to \"TEMPLE HUMAN RESOURCES\"\n");
}

void employeeInput()
{
	
	printf("\tEnter Employee Number: ");
	scanf("%d", &employeeNumber);

	//Catch error if employee number is 0 or less than 0
	if (employeeNumber <= 0)
	{
		printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\n");
		goodbye();
	}
		
	
	printf("\tEnter Hourly Salary: ");
	scanf("%d", &hourlySalary);

	//Catch error if hourly salary is 0 or less than 0
	if (hourlySalary <= 0)
	{
		printf("\n\tThis is not a valid Hourly Salary.\n\tPlease run the program again\n\n");
		goodbye();
	}

	
	printf("\tEnter Weekly Time: ");
	scanf("%d", &weeklyTime);

	//catch error if hours are 0 or less than 0
	if (weeklyTime < 0)
	{
		printf("\n\tThis is not a valid Weekly Time.\n\tPlease run the program again\n\n");
		goodbye();
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
	//checks if hours are above 40 and calculates the total amount accordingly
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
	exit(0);
}
