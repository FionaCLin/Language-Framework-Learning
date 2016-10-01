/*
 *  Point.h
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


#ifndef POINT_H
#define POINT_H

typedef struct point * Point;

struct point {
    double x;
    double y;
};


Point newPoint( double x, double y );
void destroyPoint(Point p);
double getX(Point p);
double getY(Point p);
double distS( Point p, Point q );
void setPoint(Point p, double x, double y);
void shiftPoint(Point p, double xDist, double yDist);

#endif
