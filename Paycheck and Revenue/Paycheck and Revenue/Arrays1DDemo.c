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
#include <time.h>

#define LOW 10
#define HIGH 19

#define ARRAY_SIZE 40

#define RAND_MIN 0
#define RAND_MAX 100


void findWithRange(int[]);
void fillArray(int[]);

int main()
{
	srand((unsigned)time(NULL));
	int myArray[ARRAY_SIZE] = { 0 };
	fillArray(myArray);

}

void fillArray(int x[])
{
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		x[i] = rand() % (RAND_MAX + 1) + RAND_MIN;
	}

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%4d", x[i]);
		
	}

	puts("");
	return;
}

void findWithRange(int x[])
{

}