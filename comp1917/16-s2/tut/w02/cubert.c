#include <stdio.h>
#include <math.h>

int main(int argc,char * argv []){
  float num;
  printf("Enter a number:");
  scanf("%f",&num);
  double result = pow(num,1/3.0);
  printf("The cube root of %.2f is %.2f\n",num,result);
  return 0;
}
