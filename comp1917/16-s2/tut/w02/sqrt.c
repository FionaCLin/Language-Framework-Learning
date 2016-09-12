#include <stdio.h>
#include <math.h>

int main(int argc,char * argv []){
  float num;
  printf("Enter a number:");
  scanf("%f",&num);
  double result = sqrt(num);
  printf("The square root of %.2f is %.2f\n",num,result);
  return 0;
}
