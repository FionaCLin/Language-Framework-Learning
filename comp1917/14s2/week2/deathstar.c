/*
   deathstar.c

   Sample program for COMP1917

   Print an image of the Death Star on a starry background.
   Inspired by  www.asciimation.co.nz
*/

// standard input/output functions (e.g. printf)
#include <stdio.h>

// standard library functions (e.g. random)
#include <stdlib.h>

/* radius of Death Star */
#define  RADIUS  4

int main( void )
{
  int r, c;  // co-ordinates of a point in the image

  // the image is created by two "nested" for loops

  for( r = -8; r <= 8; r++ ) {  // 17 rows, from -8 to 8

    for( c = -10; c <= 10; c++ ) { // 21 columns, from -10 to 10

      if( r*r + c*c <= RADIUS*RADIUS ) {
        // if point (x,y) is inside the circle, draw an '8'
        printf("8");
      }
      else if(( random() % 10 ) == 0 ) {
        /* use the random() library function to draw dots
           in random locations, with probability  1/10    */
        printf( "." );
      }
      else { // leave the rest as empty space
        printf( " " );
      }
    }
    // print a newline character at the end of each row
    printf( "\n" );
  }

  return 0;
}
