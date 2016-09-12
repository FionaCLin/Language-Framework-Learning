/*
 *  	order.c
 *  	Description: week3 tut ex1: 
 *  	a program that given three numbers first, second 
 *	   and third, finds out if the numbers are in strictly descending 
 *  	order (first > second > third).
 *  	Tutorial class: 
 *  	Tutor name:
 *  	Author: Fiona Lin
 *  	Date:8-Aug
 */
#include <stdio.h>
#include <stdlib.h>
int main (int argc,char * argv[]) {
	int first, second, third;
	printf ("Enter numbers: ");
	scanf ("%d %d %d", &first, &second, &third);
	if (first > second && second > third) {
		printf ("The numbers are in strictly descending order.\n");
	} else {
		printf ("The numbers are not in strictly descending order.\n");
	}

	return EXIT_SUCCESS;
}
