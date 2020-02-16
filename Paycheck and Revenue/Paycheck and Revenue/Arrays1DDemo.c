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
void findWithRange(int[]);
void reverseArray(int[]);
void reverseSequence(int []);
void findSequence(int[], int y, int z);

void printArray(int* x);

int main()
{
	srand((unsigned)time(NULL));
	int myArray[ARRAY_SIZE] = { 0 };
	fillArray(myArray);
	findWithRange(myArray);
	reverseArray(myArray);
	reverseSequence(myArray);

	int scan1, scan2;
	scan1 = 0;
	while (scan1 != -1)
	{
		printf("Please input sequence to be found. Input -1 to quit.\n");
		scanf("%d", &scan1);
		scanf("%d", &scan2);
		findSequence(myArray, scan1, scan2);
	}
	

}

void fillArray(int x[])
{
	int counter = 0;
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		x[i] = rand() % (RAND_MAX + 1) + RAND_MIN;
	}

	printf("Original Array:\n");
	printArray(x);

	puts("");
	return;
}

void findWithRange(int x[])
{
	int max = x[LOW];
	for (size_t i = LOW; i <= HIGH; i++)
	{
		if (max < x[i])
		{
			max = x[i];
		}
	}

	printf("Max = %d\n\n", max);
	return;
}

void reverseArray(int x[])
{
	int revCounter = ARRAY_SIZE - 1;
	int revArray[ARRAY_SIZE] = { 0 };
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		revArray[revCounter] = x[i];
		revCounter--;
	}

	printf("Reversed Array:\n");
	printArray(revArray);
}

void printArray(int* x)
{
	int counter = 0;
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%5d", x[i]);
		counter++;
		if (counter > 9)
		{
			puts("");
			counter = 0;
		}
	}
}

void reverseSequence(int x[])
{
	int revCounter = HIGH;
	int revArray[ARRAY_SIZE] = { 0 };
	for (size_t i = LOW; i <= HIGH; i++)
	{
		revArray[revCounter] = x[i];
		revCounter--;
	}

	for (size_t i = 0; i < LOW; i++)
	{
		revArray[i] = x[i];
	}

	for (size_t i = HIGH+1; i < ARRAY_SIZE; i++)
	{
		revArray[i] = x[i];
	}

	printf("\nReversed Sequence:\n");
	printArray(revArray);
}

void findSequence(int x[], int y, int z)
{
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		if ((y == x[i]) && (i < ARRAY_SIZE-1))
		{
			if (z == x[i + 1])
			{
				printf("sequence found at index %d\n", i);
				return;
			}
		}
	}
	printf("Sequence not found -1\n");
}