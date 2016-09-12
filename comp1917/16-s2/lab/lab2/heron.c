// Name:Fiona Lin, Student Number:z5131048.
// Date:31/07/2016

// this file is lab2 triangle area compute program

#include <stdio.h>
#include <math.h>

int isValidTriangle( double a, double b, double c);


int main(int argc, char * argv []){
   double a,b,c;
   printf("Enter sidelengths of triangle: \n");
   scanf("%lf %lf %lf", &a , &b , &c );
   if( isValidTriangle( a , b , c) ){
      double s = (a+b+c)/2.0;
      double area = sqrt( s * (s-a) * (s-b) * (s-c) );
      printf("Area = %.2lf \n", area);
   }
   else{
      printf("Invalid sidelengths inputs.\n");
   }
   return 0;  
}
int isValidTriangle( double a, double b, double c){
   int re = 0;
   double total = a + b + c;
   double max = a;
   double min = a;
   if(max < b){
      max = b;
   }
   if(max < c){
      max = c;
   }
   if(min >b){
      min =b;
   }
   if(min >c){
      min =c;
   }
   if(a > 0 || b > 0 || c > 0){
      if(min + (total-min-max) > max){
         re = 1;
      }
   }
   return re;
}

