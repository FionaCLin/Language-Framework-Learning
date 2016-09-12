#include <stdio.h>
int isPrime(int n){
  for(int i=2;i<n;i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}






int main(){
  printf("Enter a number:");
  int n;
  scanf("%d",&n);
  if(isPrime(n)){
    printf("It is a prime number\n");
  }else{
    printf("It is NOT a prime number\n");
  }
 
  return 0;
}

