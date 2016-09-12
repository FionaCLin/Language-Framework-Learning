/*
 *  triangle-a.c
 *  Description:week 3 tut ex 4
 *  a program that allows the user to enter at integer and 
 *  then prints a triangle  
 *  Tutorial class: 
 *  Tutor name: 
 *  Author: Fiona Lin
 *  Date:8-Aug
 */
#include <stdio.h>
#include <stdlib.h>

int main (int argc,char * argv[]) {
	int num;
	int row,col;
	//Obtain input
	printf ("Enter number:");
	scanf ("%d", &num);
	row = num;
	for ( ; row > 0; row --) {
		for (col = num; col > 0; col--) {
			printf ("*");
		}
		num --;
		printf ("\n");
	}
	return EXIT_SUCCESS;
}
