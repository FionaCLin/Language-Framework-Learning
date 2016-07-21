#include <stdio.h>
int main(){
  int num;
  printf("Please enter an integer:");
  scanf("%d",&num);
  for(int i=0;i<num;i++){
    printf("*\n");
  }
  return 0;
}
