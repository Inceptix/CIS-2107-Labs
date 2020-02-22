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
void rowSum(int m, int n, int arr[][n]);
void columnSum(int m, int n, int arr[][n]);
void isSquare(int m, int n);
void displayOutputs(int m, int n, int arr[][n]);

int main()
{

	int m , n;

	printf("Let's create a 2Dim array!\n");

	printf("How many rows?\n");
	scanf("%d", &m);

	printf("How many columns?\n");
	scanf("%d", &n);

	int arr[m][n];

	for(int rows = 0; rows < m; rows++)
    {
        for(int columns = 0; columns < n; columns++)
        {
            printf("enter [%d][%d]: ", rows, columns);
            scanf("%d", &arr[rows][columns]);
        }
    }

	printf("\nMax number in the array is %d\n\n",arrayMax(m,n, arr));
	rowSum(m, n, arr);
	puts("");
	columnSum(m, n, arr);
	puts("");
	isSquare(m,n);
	displayOutputs(m, n, arr);
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
    return max;
}

void rowSum(int m, int n, int arr[][n])
{
    for (int rows = 0; rows < m; rows++)
    {
        int sum = 0;
        for(int columns = 0; columns < n; columns++)
        {
            sum = sum + arr[rows][columns];
        }
        printf("Sum of row %d = %d\n", rows+1, sum);
    }
}

void columnSum(int m, int n, int arr[][n])
{
    int rows, columns;

    if(m <= 1)
    {
        for(int i = 0; i < n; i++)
        {
            printf("Sum of column %d = %d\n", i+1, arr[0][i]);
        }
    }

    else if(n <=1)
    {
        int sum = 0;
        for(int i = 0; i < m; i++)
        {

            sum = sum + arr[i][0];
        }
        printf("Sum of column 1 = %d\n", sum);
    }

    else
    {
        for (rows = 0; rows < n; rows++)
        {
            int sum = 0;
            for(columns = 0; columns < m; columns++)
            {
                sum = sum + arr[columns][rows];
            }
            printf("Sum of column %d = %d\n", rows+1, sum);
        }
    }
}

void isSquare(int m, int n)
{
    if(m == n)
    {
        printf("This is a square array.\n\n");
    }
    else
    {
        printf("This is not a square array.\n\n");
    }
}

void displayOutputs(int m, int n, int arr[][n])
{
    printf("Here is your 2Dim array:\n");
    for (int i = 0; i < m; i++)
    {
        printf("[");
        for (int j  = 0; j < n; j++)
        {
            printf("%d", arr[i][j]);
            if(j+1 < n)
            {
                printf(",");
            }
        }
        printf("]\n");
    }
}
