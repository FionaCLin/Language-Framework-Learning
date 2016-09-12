#include <stdio.h>

int main(int argc, char *argv []){
  double nums[3];
  scanf("%lf %lf %lf",&nums[0],&nums[1],&nums[2]);
   double * temp ;
  if(*nums>*(nums+1)){
    temp=nums+1;
    
  }
  else{
    temp=nums;
  }
  
  *nums=*temp;
  //*(nums+1)=*;
  printf("min: %lf\n",*nums);
  //printf("medium: %lf\n",*(nums+1));
  return 0;
}

