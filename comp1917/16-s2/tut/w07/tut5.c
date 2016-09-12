/*
 *  tut5.c
 *  Description: 
 *  Write a program that uses struct _student with attributes int zid
 *  and double height. Create an array of these structs and populate
 *  each struct with infromation from standard input.
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct _student Student;

struct _student {
    int zid;
    double height;
};



int main ( int argc, char * argv[] ) {
    printf( "Enter number of students:" );
    int size = 1;
    int i = 0;
    scanf( "%d", &size );
    Student s[size];
    while ( i < size ) {
        printf( "Enter zID: " );
        scanf( "%d", &s[i].zid );
        printf( "Enter height: " );
        scanf( "%lf", &s[i].height );

        i++;
    }

    i = 0; 
    while ( i < size ) {
        printf( "zID: %d, height: %.2lf\n", s[i].zid,
                s[i].height );
        i++;
    } 

    return EXIT_SUCCESS;
}

