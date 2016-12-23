/*
 *  fizzbuzz.c
 *  Description: 
 *  a program that prints the numbers from 1 to 100. But for multiples 
 *  of three print "Fizz" instead of the number and for the multiples
 *  of five print "Buzz". For numbers which are multiples of both three
 *  and five print "FizzBuzz". 
 *  Tutorial class: 
 *  Tutor name:
 *  Author: Fiona Lin
 *  Date:14 Aug
 */

#include <stdio.h>
#include <stdlib.h>

void fizzbuzz( int i );

int main (int argc, char * argv[]) {

    for (int i = 1; i <= 100; i++) {
        fizzbuzz(i);
        printf("\n");
    }

    return EXIT_SUCCESS;
}


void fizzbuzz( int i ) {
    if ( i % 3 != 0 && i % 5 != 0) {
        printf("%d", i);
    }
    if (i % 3 == 0) {
        printf("Fizz");
    }
    if (i % 5 == 0) {
        printf("Buzz");
    }

}


