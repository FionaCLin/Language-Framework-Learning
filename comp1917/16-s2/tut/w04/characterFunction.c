/*
 *  characterFunction.c
 *  Description: 
 *  my versions of these character functions (from the library ctype.h):
 *  int isdigit( int ch )
 *  int islower( int ch )
 *  int toupper( int ch )
 *  Tutorial class: 
 *  Tutor name:
 *  Author: Fiona Lin
 *  Date:14 Aug
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
    
    char num = '5';
    char l   = 'l';
    if ( isdigit( num )) {
        printf("%c is a digit.\n", num);
    }

    if ( islower(l)) {
        printf("%c is in lower case\n", l);

    }
    printf("convert %c to upper case: %c \n", l, toupper(l));


    return EXIT_SUCCESS;
}

int isdigit( int ch ) {
    int result = 0;
    if ( ch > '0' && ch <'9') {
        result = 1;
    }
    return result;
}

int islower( int ch ) {
    int result = 0;
    if ( ch > 'a' && ch <'z') {
        result = 1;
    }
    return result;
}


int toupper( int ch ) {
    int diff = 'a' - 'A';
    return ch - diff;
}


