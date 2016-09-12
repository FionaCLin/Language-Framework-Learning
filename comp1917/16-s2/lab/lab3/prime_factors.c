/*
 *    prime_factors.c
 *    Description: week3 tut ex5: 
 *    Write a program prime_factors.c that reads an integer n from 
 *    standard input and prints the decomposition of n into prime 
 *    factors. If n is prime it should instead print a message 
 *    indicating.
 *    Tutorial class: 
 *    Tutor name:
 *    Author: Fiona Lin
 *    Date:8-Aug
 */

#include <stdio.h>
#include <stdlib.h>

int primeFactorize (int input);

int isPrime (int num) ;


int main (int argc, char * argv []) {
   int input = 0;
   printf ("Enter number: ");
   scanf ("%d", &input);
   
   int product = 1;
   printf ("%d ", input);
   
   if ( isPrime(input)) {
      printf ("is prime\n");
   } else {
      printf ("= ");
      while (product != input) {
         int primeFactor = primeFactorize (input/product);
         if (primeFactor != input) {
            printf ("%d", primeFactor);
            product *= primeFactor;
          }
         if (product != input) { 
            printf ("*");
         }
      }
      printf ("\n");
   }
   return EXIT_SUCCESS;
}

int primeFactorize (int input) {
   int result = input;
   int i = 2;
   while (i < input) {
      if (input % i == 0) {
         if (isPrime (i)) {
            result = i;
            break;
         }
      }
      i ++;
   }
   return result;
}

int isPrime (int num) {
   int result = 1;
   int i = 2;
   while (i < num) {
      if (num % i == 0) {
         result = 0;
      }
      i ++;
   }
   return result;
}


