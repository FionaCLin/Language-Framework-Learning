#include<stdio.h>

int main(int argc,char * argv []){
  char c='\n';
  printf("Enter a character: ");
  scanf("%c", &c);
  if(isdigit(c)){
    printf("%c is a number\n",c);
  }
  else if(islower(c)){
    printf("%c is in lower case format; \n",c);
    printf("Would you like to convert it to upper case?(Y/N)\n");
    char a; 
    //lession: \n got your scanf stuck with it. use getchar() consume it. 
    getchar();
    scanf("%c", &a);
    if(a=='y'||a=='Y'){
       printf("%c\n", toupper(c));
     }
  }
  return 0;
  
}

int isdigit(int ch){
  if(ch<'0'&& ch>'9'){
    return 0;
  }
  return 1;
}

int islower(int ch){
  if(ch<'a'&& ch>'z'){
    return 0;
  }
  return 1;
}

int toupper(int ch){
  return ch+='A'-'a';
}
