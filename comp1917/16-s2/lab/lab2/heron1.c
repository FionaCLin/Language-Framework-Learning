// Name:Fiona Lin, Student Number:z5131048.
// Date:31/07/2016

// this file is lab2 triangle area compute program

#include <stdio.h>
#include <math.h>

int main(int argc, char * argv []){
  double a,b,c;
  printf("Enter sidelengths of triangle: \n");
  scanf("%lf %lf %lf",&a,&b,&c);
  double s=(a+b+c)/2.0;
  double area = sqrt(s*(s-a)*(s-b)*(s-c));
  printf("Area for triangle %lf,%lf,%lf is %lf \n",a,b,c,area);
  return 0;  
}
