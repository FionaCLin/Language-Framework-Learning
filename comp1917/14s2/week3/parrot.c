#include <stdio.h>

int main(int argc, char * argv []){
  int a[7];
  printf("Enter 7 numbers:\n");
  for(int i =0; i<7;i++){
    scanf("%d", &a[i]);
  }
  for(int i =0; i<7;i++){
    printf("a[%d] = %d \n",i, a[i]);
  }
    
  return 0;
}
