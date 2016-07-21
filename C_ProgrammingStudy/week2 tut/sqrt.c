#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter a number:");
    double num;
    scanf("%lf",&num);
    double root= sqrt(num);
    double cuberoot= pow(num,(1./3.));
    printf("The square root of %f is %f\n",num,root);
    printf("The cube root of %f is %f\n",num,cuberoot);
    return 1;
}
