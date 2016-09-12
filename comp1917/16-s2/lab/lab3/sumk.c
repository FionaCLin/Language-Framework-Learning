/*
 *    sumk.c
 *    Description: week3 tut ex2:
 *    a program called sumk.c which, for each number k from 1 to 15,
 *    prints the sum of the numbers from 1 to k. Compile it to 
 *    produce an executable called sumk. 
 *    Tutorial class: 
 *    Tutor name:
 *    Author: Fiona Lin
 *    Date:8-Aug
 */
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv [] ) {
   
   printf ("    k    sum \n");
   int k    = 1;
   int sum  = 0;
   printf("------------\n");
   while (k <= 15) {
      sum += k;
      printf(" %4d  %4d \n", k, sum);
      k++;
   }
}
