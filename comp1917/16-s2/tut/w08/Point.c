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
typedef struct point * Point;

struct point {
    double x;
    double y;
};


double distS( Point p, Point q ) {
    double deltax = p->x - q->x;
    double deltay = p->y - q->y;
    double distance = sqrt( ( pow( deltax, 2 ) + pow( deltay, 2 ) ) );
    return distance;
}


Point newPoint( double x, double y ) {

    Point newPoint = malloc(sizeof(Point));
    if ( newPoint != NULL ) { 
        newPoint -> x = x;
        newPoint -> y = y;
    }
    return newPoint;    
}

void destroyPoint(Point p) {
    free( p );
}

double getX(Point p) {
    return p -> x;
}

double getY(Point p) {
    return p -> y;
}

void setPoint(Point p, double x, double y) { 
    p -> x = x;
    p -> y = y;
}

void shiftPoint(Point p, double xDist, double yDist) {
    p -> x += xDist;
    p -> y += yDist;
}


