/*
*  stars.c
*  Description:week 3 tut ex 3
*  a program that allows the user to enter at integer and 
*  then prints out that many stars, each on a new line. 
*  Tutorial class: 
*  Tutor name: 
*  Author: Fiona Lin
*  Date:8-Aug
*/
#include <stdio.h>
#include <stdlib.h>

int main (int argc,char * argv[]) {
   int num = 0;
   printf ("Enter : ");
   int result = scanf ("%d", &num);
   int i = 0;
   if (result) {
      while (i < num) {
         printf("*\n");
         i ++;
      }
   } 
   return EXIT_SUCCESS;
}
