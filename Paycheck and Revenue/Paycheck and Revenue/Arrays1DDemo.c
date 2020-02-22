/*
Marinos Rrapaj
February 16, 2020
CIS2107_Lab03_Processing1DArrays

Statement: To write a program in C called Arrays1DDemo.c and implement different functionality to show
proficiency in working with arrays. Some of the functions include being able to find a certain value
within a range provided, being able to reverse an array, and also finding a given sequence of numbers.
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

int dmain()
{
	srand((unsigned)time(NULL));
	int myArray[ARRAY_SIZE] = { 0 };
	fillArray(myArray);
	findWithRange(myArray);
	reverseArray(myArray);
	reverseSequence(myArray);

	int scan1, scan2;
	scan1 = 0;
	//implement an easy way of testing for sequence
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
		//this gives a random number for every index
		x[i] = rand() % (RAND_MAX + 1) + RAND_MIN;
	}

	printf("Original Array:\n");

	//custom function for printing the array similarly to the demo
	printArray(x);

	puts("");
	return;
}

void findWithRange(int x[])
{
	//declare max variable to be ther first given number in the range
	//then check if any other numbers are bigger and reassign
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
	//revCounter basically acts as the reverse index for the new array
	int revCounter = ARRAY_SIZE - 1;

	//created a new array which is reversed
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
	//custom print function
	int counter = 0;
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%5d", x[i]);
		counter++;

		//chaning this number will change the number of columns that appear on the screen
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

	//the array with a reversed sequence is also a separate array
	//it uses the same logic for reversing the sequence as the function above
	int revArray[ARRAY_SIZE] = { 0 };
	for (size_t i = LOW; i <= HIGH; i++)
	{
		revArray[revCounter] = x[i];
		revCounter--;
	}

	//fills the rest of the array with the same values as the original array
	for (size_t i = 0; i < LOW; i++)
	{
		revArray[i] = x[i];
	}

	//fills the rest of the array with the same values as the original array
	for (size_t i = HIGH+1; i < ARRAY_SIZE; i++)
	{
		revArray[i] = x[i];
	}

	printf("\nReversed Sequence:\n");
	printArray(revArray);
}

void findSequence(int x[], int y, int z)
{
	//loop through array
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		//chech if the index is equal to the value
		//have to make sure to stay within the bounds of the array and not read data outside the array
		if ((y == x[i]) && (i < ARRAY_SIZE-1))
		{
			//if the second value is also true then print message.
			//in the case that there are multiple sequences that exist this message will print all those times
			if (z == x[i + 1])
			{
				printf("sequence found at index %u\n", i);
			}
		}
	}
	//once we have finished scanning the whole array then print the message that sequence does not exist
	printf("Sequence not found -1\n");
}