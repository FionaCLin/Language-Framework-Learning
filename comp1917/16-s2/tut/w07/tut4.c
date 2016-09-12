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
typedef struct point Point;

struct point {
    double x;
    double y;
};


double distA( double p[2], double q[2] );

double distS( Point p, Point q );


int main ( int argc, char * argv[] ) {
    double p[2] = { 0, 0 };
    double q[2] = { 3, 4 };
    double distance = distA( p, q );
    printf( "p and q are %.2lf away.\n", distance );

    Point pointA;
    pointA.x = 0;
    pointA.y = 0;
    Point pointB;
    pointB.x = 3;
    pointB.y = 4;

    distance = distS( pointA, pointB );

    printf( "a and b are %.2lf away.\n", distance );
    return EXIT_SUCCESS;
}

double distA( double p[2], double q[2] ) {
    double deltax = p[0] - q[0];
    double deltay = p[1] - q[1];
    double distance = sqrt( ( pow( deltax, 2 ) + pow( deltay, 2 ) ) );
    return distance;
}
double distS( Point p, Point q ) {
    double deltax = p.x - q.x;
    double deltay = p.y - q.y;
    double distance = sqrt( ( pow( deltax, 2 ) + pow( deltay, 2 ) ) );
    return distance;
}
