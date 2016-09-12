/*
 *    sumkcube.c
 *    Description: week3 tut ex3:
 *    a program called sumk.c which, for each number k from 1 to 15,
 *    prints the sum of of the cubes of the numbers between 1 and k.
 *	  Compile it to produce an executable called sumcube. 
 *    Tutorial class: 
 *    Tutor name:
 *    Author: Fiona Lin
 *    Date:8-Aug
 */
#include <stdio.h>
#include <stdlib.h>

#include <math.h>


int main (int argc, char * argv [] ) {
   
   printf ("    k    sum \n");
   int k    = 1;
   int sum  = 0;
   printf("----------------\n");
   while (k <= 15) {
      sum += pow(k,3);
      printf(" %5d  %5d \n", k, sum);
      k++;
   }
}
