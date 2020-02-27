/*
Marinos Rrapaj
February 16, 2020
CIS2107_Lab05. 2D Arrays and Array of Pointers to Functions

Statement: To write a program in C called ArraysofPointers.c and implement different functionality to show
proficiency in working with pointers and arrays that hold pointers to functions. This is a program provided by
the slides which requires modifications in the function signatures and arguments as well. The objective was to
implement all the functions as array of pointers and have them call separate functions.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define STUDENTS 3
#define EXAMS 4

void    printArray  (const int grades[][EXAMS], size_t pupils, size_t test);
void    minimum     (const int grades[][EXAMS], size_t pupils, size_t test);
void    maximum     (const int grades[][EXAMS], size_t pupils, size_t test);
void    average     (const int grades[][EXAMS], size_t pupils, size_t test);
void    endProgram();
void    displayMenu();

void (*processGrades) (const int[][EXAMS], size_t, size_t);

int amain()
{
    const int studentGrades[STUDENTS][EXAMS] =
    {
        { 77, 68, 86, 73},
        { 96, 87, 89, 78},
        { 70, 90, 86, 81}
    };

    void (*processGrades[4]) (const int[][EXAMS], size_t, size_t) = {printArray, minimum, maximum, average};

    printf("Enter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all test for each student\n\t4 End Program\n");
	size_t choice;
	scanf("%lu", &choice);

        //main menu
		while (choice >= 0 && choice < 4)
        {
            (*processGrades[choice])(studentGrades, STUDENTS, EXAMS);
            printf("Enter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all test for each student\n\t4 End Program\n");
            scanf("%lu", &choice);
        }



}

void displayMenu()
{
	printf("Enter a choice:\n\t0 Print the array of grades\n\t1 Find the minimum grade\n\t2 Find the maximum grade\n\t3 Print the average on all test for each student\n\t4 End Program\n");
	return;
}

void minimum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int lowGrade = 100; //highest possible value

    for (size_t i = 0; i < pupils; i++)
    {
        for (size_t j = 0; j < tests; j++)
        {
            if (grades[i][j] < lowGrade)
            {
                lowGrade = grades[i][j];
            }
        }
    }

    printf("\n\nLowest grade: %d\n", lowGrade);
}

void maximum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int highGrade = 0; //lowest possible value

    for (size_t i = 0; i < pupils; i++)
    {
        for (size_t j = 0; j < tests; j++)
        {
            if (grades[i][j] > highGrade)
            {
                highGrade = grades[i][j];
            }
        }
    }

    printf("\nHighest grade: %d\n\n", highGrade);
}

void average(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    for (size_t i = 0; i < pupils; i++)
    {
        float sum = 0;
        for (size_t j = 0; j < tests; j++)
        {
            sum = sum + grades[i][j];
        }
        printf("The average grade for student %lu is %.2f\n", i, (sum/tests));
    }
    puts("");
}

void printArray(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    puts("The array is: ");

    printf("%s", "\t\t[0]  [1]  [2]  [3]");

    for (size_t i = 0; i < pupils; i++)
    {
        printf("\nstudentGrades[%lu] ", i);

        for (size_t j = 0; j < tests; j++)
        {
            printf("%-5d", grades[i][j]);
        }
    }
    puts("");
    puts("");
}

void endProgram()
{
    exit(0);
}





