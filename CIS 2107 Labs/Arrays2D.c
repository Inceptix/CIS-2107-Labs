/*
Marinos Rrapaj
February 23, 2020
CIS2107_Lab05. 2D Arrays and Array of Pointers to Functions

Statement: To write a program in C called Arrays2D.c and implement different functionality to show
proficiency in working with 2-Dimensional arrays. Some of the functions include being able to find a max
and min value in the array, being able to sum the columns, determine whether the array is a square and
display its contents.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>


int arrayMax(int m, int n, int arr[][n]);
void rowSum(int m, int n, int arr[][n]);
void columnSum(int m, int n, int arr[][n]);
void isSquare(int m, int n);
void displayOutputs(int m, int n, int arr[][n]);

int bmain()
{

	int m , n;

	printf("Let's create a 2Dim array!\n\n");

	printf("\tHow many rows? ");
	scanf("%d", &m);

	printf("\tHow many columns? ");
	scanf("%d", &n);

	puts("");

	int arr[m][n];

    //read values for array from user
	for(int rows = 0; rows < m; rows++)
    {
        for(int columns = 0; columns < n; columns++)
        {
            printf("\tenter [%d][%d]: ", rows, columns);
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
			    //change max if the number is bigger
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
            //by incrementing only columns at first we are able to sum the values
            //of one row into variable sum
            sum = sum + arr[rows][columns];
        }
        //display the row correctly by offsetting
        printf("Sum of row %d = %d\n", rows+1, sum);
    }
}

void columnSum(int m, int n, int arr[][n])
{
    int rows, columns;

    if(m <= 1)
    {
        //check if there is only 1 0 rows
        for(int i = 0; i < n; i++)
        {
            printf("Sum of column %d = %d\n", i+1, arr[0][i]);
        }
    }

    //check the amount of columns
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
                //by incrementing the first argument we are able to sum all the vertical
                //contents which are the rows
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
                printf(", ");
            }
        }
        printf("]\n");
    }
}
