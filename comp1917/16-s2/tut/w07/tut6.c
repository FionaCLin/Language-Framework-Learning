/*
 *  tut6.c
 *  Description: 
 *  Write a program that uses struct _student with attributes int zid
 *  and double height. Create an array of these structs and populate
 *  each struct with infromation from standard input.
 *  Extend previous program to use function tallest_student that takes
 *  in an array of student structs and returns zid of the tallest
 *  student.
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


int getTallest( Student input[], int len );

int main ( int argc, char * argv[] ) {
    printf( "Enter number of students:" );
    int tallest;
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
    tallest = getTallest( s, size );
    printf( "Tallest Student Id : %d\n", tallest );
    return EXIT_SUCCESS;
}


int getTallest( Student input[], int len ) {
    printf( "%d people in sample data\n", len );
    double tallest = input[0].height;
    int zid = input[0].zid;
    int i;
    for ( i = 1; i < len; i++ ) {
        if ( input[i].height > tallest ) {
            zid = input[i].zid;
            tallest = input[i].height;
        }
    }
    return zid;
}
