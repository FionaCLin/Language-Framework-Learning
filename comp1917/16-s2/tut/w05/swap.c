/*
 *  template.c
 *  Description: 
 *  
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:
 */

#include <stdio.h>
#include <stdlib.h>

void swap ( int *first, int *second ) ;

int main ( int argc, char * argv[] ) {
    int a = 12;
    int b = 13;

    swap (&a, &b);
    
    printf("a = %d\nb = %d\n", a, b);

    return EXIT_SUCCESS;
}


void swap ( int *first, int *second ) {
    int temp = *first;
    *first = *second;
    *second = temp ;
    return ;
}
