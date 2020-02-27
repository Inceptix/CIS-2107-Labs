/*
Marinos Rrapaj
February 27, 2020
CIS2107_Lab06. "Race"

Statement: To write a program in C called Race.c and implement different functionality to show
proficiency in working with pointers such as passing pointers to functions and manipulating pointer values
as well as dereferencing. Some of the functions include being able pass in address of a variable and manipulate
said variable by dereferencing as well was checking if there variables are equal to each other by using dereferencing.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include <windows.h>

#define FINISH 70

void moveTortoise( int* tortoisePtr );
void moveHare( int* harePtr );
void printPosition( const int* const tortoisePtr, const int* const harePtr );

int main( void ){
   int tortoise = 1, hare = 1, timer = 0;

   srand( time( 0 ) );

   //interface
   printf("Tortoise and Hare\n*****************\n\n");
   printf("BANG !!!!!\nAND THEY'RE OFF !!!!\n\n");

   //move untill either contender finish the race
   while(tortoise != FINISH && hare != FINISH){
      //move the tortoise
      moveTortoise( &tortoise );
      //move the hare
      moveHare( &hare );
      //print current position
      printPosition( &tortoise, &hare );

      //Delay each turn by 1 second
      struct timespec req = {0};
      req.tv_sec = 1;
      req.tv_nsec = 0;
      //uncomment the next line to make the go 1 step per second
      //nanosleep(&req, (struct timespec *)NULL);

      //calculate the timer
      timer++;
   }

   //the result
    if(tortoise > hare)
    {
      printf("TORTOISE WINS !!! YAY !!!\n");
    }
    else if(tortoise < hare)
    {
      printf("Hare wins. Yuch.\n");
    }
    else if (tortoise == hare)
    {
        printf("It is a tie but because we like the tortoise more, the tortoise wins!!");
    }

   printf("Time Elapsed: %d seconds\n", timer);


   exit(0);
}

void moveTortoise( int* tortoisePtr ){
   int i;

   i = rand() % 10;

   if(i >= 1 && i <= 5){
      //1 - 5 : Fast plod
      *tortoisePtr += 3; //move 3 square to the right
   }else if(i >= 6 && i <= 7){
      //6 - 7 : Slip
      *tortoisePtr -= 6; //move 6 square to the left
   }else{
      //8 - 10 : Slow plod
      *tortoisePtr += 1; //move 1 square to the right
   }

   if(*tortoisePtr < 1)
      *tortoisePtr = 1;
   else if(*tortoisePtr > FINISH)
      *tortoisePtr = FINISH;
}

void moveHare( int* harePtr ){
   int i;

   i = rand() % 10;

   if(i >= 1 && i <= 2){
      //1 - 2 : Sleep
      *harePtr = *harePtr;
   }else if(i >= 3 && i <= 4){
      //3 - 4 : Big hop
      *harePtr += 9;
   }else if(i == 5){
      //5 : Big slip
      *harePtr -= 12;
   }else if(i >= 6 && i<= 8){
      //6 - 8 : Small hop
      *harePtr += 1;
   }else{
      //9 - 10 : Small slip
      *harePtr -= 2;
   }

   if(*harePtr < 1)
      *harePtr = 1;
   else if(*harePtr > FINISH)
      *harePtr = FINISH;
}

void printPosition( const int* const tortoisePtr, const int* const harePtr ){
   int i;

   if(*tortoisePtr == *harePtr){
      for(i = 1; i < *tortoisePtr; i++){
         printf("%s", " " );
      }
      printf("OUCH!!!");
   }else if(*tortoisePtr < *harePtr){
      for(i = 1; i < *tortoisePtr; i++ ){
         printf("%s", " " );
      }
      printf("T");

      for(i = 1; i < (*harePtr - *tortoisePtr); i++){
         printf("%s", " " );
      }
      printf("H");
   }else{
      for(i = 1; i < *harePtr; i++){
         printf("%s", " ");
      }
      printf("H");

      for( i = 0; i < (*tortoisePtr - *harePtr); i++){
         printf("%s", " " );
      }
      printf("T");
   }

   printf("\n");
}
