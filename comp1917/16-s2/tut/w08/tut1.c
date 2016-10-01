/*
 *  template.c
 *  Description: 
 *  For each of these two representations, write a function which, given
 *  two points p and q, returns the distance between them:
 *  double distA( double p[2], double q[2] );
 *   double distS( Point p, Point q );
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.h"

int main ( int argc, char * argv[] ) {

    Point pointA = newPoint( 0, 0 );
    Point pointB = newPoint( 3, 4 );

    double distance = distS( pointA, pointB );

    printf( "a and b are %.2lf away.\n", distance );


    Point p = newPoint(0,0);
    shiftPoint(p,1,-1);
    printf("x value is: %lf\n", getX(p));
    printf("y value is: %lf\n", getY(p));
    destroyPoint(p);

    return EXIT_SUCCESS;
}


