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


int arrayMax(int m, int n, int arr[][n]);

int main() 
{
	int arr[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int m = 3, n = 3;
	arrayMax(m,n, arr);
}

int arrayMax(int m, int n, int arr[][n])
{
	int max = INT_MIN;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	}


}
