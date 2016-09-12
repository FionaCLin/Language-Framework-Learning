/*
 *  triangle-b.c
 *  Description:week 3 tut ex 4-b
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
	int n = num;
	for (row = 1; row<=num; row++) {
		for (col = 0; col < row; col++) {
			printf (" ");
		}
		for (col = n; col > 0; col--) {
			printf ("*");
		}
		n --;
		printf ("\n");
	}
	return EXIT_SUCCESS;
}
