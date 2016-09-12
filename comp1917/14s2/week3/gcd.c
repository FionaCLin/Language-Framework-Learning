/*
   gcd.c

   Sample program for COMP1917

   Input two numbers and print their Greatest Common Divisor.
*/

#include <stdio.h>

int gcd( int a, int b ); // function prototype


int main( void )
{
  int a,b,g;

  printf("Enter two positive numbers ? " );
  scanf( "%d %d", &a, &b );

  g = gcd( a, b ); // compute the greatest common divisor
  // note that a and b still retain their previous values

  printf("Greatest Common Divisor of %d and %d is: %d\n",a,b,g);

  return 0;
}

/*
   Use Euclid's method to compute
   the greatest common divisor of two numbers.
*/
int gcd( int a, int b )
{
  int r; // remainder

  while( b > 0 ) {
     r = a % b;
     a = b; // only the local "copies" of a and b are changing,
     b = r; // not the ones in the calling function
     //printf("a = %d, b=%d\n", a, b );
  }

  return( a );
}
