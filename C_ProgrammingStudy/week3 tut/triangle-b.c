#include <stdio.h>

int main(){
  int num;
  int row,col;
  //Obtain input
  printf("Enter number:");
  scanf("%d", &num);
  int n= num;
  for(row=1;row<=num;row++){
    for(col=0;col<row;col++){
      printf(" ");
    }
    for(col=n;col>0;col--){
      printf("*");
    }
    n--;
    printf("\n");
  }
  return 0;
}
