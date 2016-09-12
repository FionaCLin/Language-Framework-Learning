/*
*  ex5.c
*  Description:
*   week 3 tut ex5:
*  a program that generates two random 
*  numbers between 1 and 107 and check 
*  if a smaller number is a factor of a larger. 
*  Author: Fiona Lin
*  Date:8-August
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void isFactor(int small, int large);

int main (int argc,char * argv[]) {
   
   srandom (time (NULL));

   int num1 = rand () % 107 + 1;
   int num2 = rand () % 107 + 1;

   if (num1 <=  num2){
      isFactor (num1, num2);
   } else {
      isFactor (num2, num1);
   }

   return EXIT_SUCCESS;
}

void isFactor (int small, int large) {
   if (large % small == 0) {
      printf ("%d is a factor of %d\n", small, large);
   } else {
      printf ("%d is not a factor of %d\n", small, large);
   }
}
