/*
 *  orderM.c
 *  Description: week3 tut ex2
 *  program to check if three numbers are in ascending or descending 
 *  order. 
 *  Tutorial class: 
 *  Tutor name:
 *  Author: Fiona Lin
 *  Date:8-Aug
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc,char * argv[]) {
	int first, second, third;
	printf ("Enter numbers: ");
	scanf ("%d %d %d", &first, &second, &third);
	if (first > second && second > third) {
		printf ("The numbers are in strictly descending order.\n");
	} else if (first < second && second < third){
		printf ("The numbers are in strictly ascending order.\n");
	} else {
		printf ("The numbers are not in any order.\n");
	}
	return EXIT_SUCCESS;
}
