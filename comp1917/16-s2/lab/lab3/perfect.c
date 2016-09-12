#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char * argv [] ) {
   int input = 0;
   printf ("Enter number: ");
   scanf ("%d", &input);

   while (input < 0) {
      printf ("Enter a positive integer: ");
      scanf ("%d", &input);
   }
   int factor = 1;
   int sum = 0;

   printf ("The factors of 6 are: \n");
   while ( factor < input ) {
      if ( input%factor == 0) {
         printf ("%d\n",factor);
         sum += factor;
      }
      factor ++ ;
   }
   printf ("%d\n", input);
   printf ("Sum of factors = %d\n", sum);
   if (sum == input) {
      printf ("%d is a perfect number\n", input);
   } else {
      printf ("%d is not a perfect number\n", input); 
   }
   return EXIT_SUCCESS;
}
