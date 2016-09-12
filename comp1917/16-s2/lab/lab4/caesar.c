/*
 *  caesar.c
 *  Description: 
 *  
 *  Tutorial class: 
 *  Tutor name:
 *  Author: Fiona Lin
 *  Date:
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int rotate_right( int ch );
int rotate_left( int ch );
int encode( int ch, int shift);
int isALphabetic( int ch );

int main ( int argc, char * argv[] ) {

    int sh;
    char ch;

    printf("Enter shift: ");
    scanf("%d", &sh);
    printf("Enter text:\n");
    getchar();    
    while( ( ch = getchar()) != EOF ) {
        putchar( encode( ch, sh ) );
    }

    printf("\n");

    return EXIT_SUCCESS;
}

int isALphabetic( int ch ) {
    int re = FALSE;
    if( ch > 64 && ch < 91 ) {
        re = TRUE;
    }
    else if ( ch > 96 && ch < 123 ) {
        re = TRUE;
    }
    return re;
}


int rotate_right( int ch ) {
    if ( isALphabetic( ch ) ) {  
        if ( ch == 'z' ) {
            ch = 'a';
        } else if ( ch == 'Z' ) {
            ch = 'A';
        } else{
            ch ++;
        }
    }
    return ch ;
}



int rotate_left( int ch ) {
    if ( isALphabetic( ch ) ) {  
        if ( ch == 'a' ) {
            ch = 'z';
        } else if ( ch == 'A' ) {
            ch = 'Z';
        } else {
            ch --;
        }
    }
    return ch;
}


int encode( int ch, int shift) {
    int re = ch;
    while( shift < 0 ) {
//      printf("before sh=%d, re=%d,%c\n", shift, re, re);
        re = rotate_left( re );
//      printf("after sh=%d, re=%d,%c\n", shift, re, re);
        shift ++;
    }
    while( shift > 0 ) {
        re = rotate_right( re );
        shift --;
    }
    return re;
}





