#include <stdio.h>

int main(){
  int num;
  int row,col;
  //Obtain input
  printf("Enter number:");
  scanf("%d", &num);
  row=num;
  for(;row>0;row--){
    for(col=num;col>0;col--){
      printf("*");
    }
    num--;
    printf("\n");
  }
  return 0;
}
