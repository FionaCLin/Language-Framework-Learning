/*
 *  tut1.c
 *  Description: 
 *  Write a program that scans in the size of an array and then uses the
 *  function int *readArray(int size) to dynamically allocate an array
 *  of appropriate size and populate it with numbers from standard
 *  input.
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:
 */

#include <stdio.h>
#include <stdlib.h>


int *readArray(int size);

int main ( int argc, char * argv[] ) {

    int size = 0;
    scanf("%d", &size);
    int * myReturn = readArray( size );    
    int i;
    printf( "myReturn begin: %p\n", myReturn );
    for ( i = 0; i < size; i++ ) { 
        printf( " element %d = %d\n", i , *myReturn );
        myReturn ++;
    }
    printf( "myReturn end: %p\n", myReturn );
    printf( "myReturn reset: %p\n", myReturn - size );
    return EXIT_SUCCESS;
}

int *readArray(int size){
    int * intArray = malloc( sizeof(int) * size );
    int i = 0;
    int * result = intArray;
    if ( intArray != NULL ) {
        for ( i = 0; i < size; i++) {
            scanf( "%d", intArray);
            // printf("element %d = %d \n", i+1, *intArray );
            intArray++;
        }
    }

    //    printf("intArray: %p\n", intArray);
    //    printf("result: %p\n", result);

    return result;
}
