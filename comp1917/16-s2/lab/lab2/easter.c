#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
  printf("Enter Year: ");
  int year;
  scanf("%d",&year);
  int a=year%19;
  int b=year/100;
  int c=year%100;
  int d=b/4;
  int e=b%4;
  int f=(b+8)/25;
  int g=(b-f+1)/3;
  int h=(19*a+b-d-g+15)%30;
  int i=c/4;
  int k=c%4;
  int l=(32+2*e+2*i-h-k)%7;
  int m=(a+11*h+22*l)/451;
  //Easter Month 
  int month=(h+l-7*m+114)/31;
  char * mon;
  if(month==3){
  	mon="March";
  }
  else if(month==4){
    mon="April";
  }
  int p=(h+l-7*m+114)%31;
  //Easter Date=p+1     (date in Easter Month)
  int date=p+1;
  printf("In %d, Easter is %s %d\n",year,mon,date);

  return 0;
}
