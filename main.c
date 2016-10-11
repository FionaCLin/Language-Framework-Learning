/* 
 * assign2.c
 * Description: 
 * a simplified scoring system for Yahtzee
 * Tutorial class: T14A
 * Tutor name: Curtis Millar
 * Author: Fiona Lin(Z5131048)
 * Date:8 Oct 2016
 */ 



#include <stdio.h>
#include <stdlib.h>
#include "Pkmn.h"

void printMenu();
void readPkmnInput(int * id, char ** name, double * height, double *
        weight, int * type1, int * type2) ;

int main( int argc, char * argv[] ) {

    PkmnList list = createPkmnList();
    int id, type1, type2;
    char * name;
    double height, weight;
    printMenu();
    char selection;
    scanf( " %c", &selection );
    while ( selection != 'q' ) {
        if( selection == 'a' ) {
            // ADD YOUR CODE HERE (to add a new Pokemon to the list)
            readPkmnInput( &id, &name, &height, &weight, &type1, &type2 );
            printf("---You have enterred---\nID: #%03d \nName: %s\nHeight: %.2fm\nWeight: %.2fkg\n", id, name,
                    height, weight);
            printf( "Type: %s", getTypeString( type1 ) );
            if ( type2 != -1) {
                printf("/%s\n", getTypeString( type2 ) );
            } else {
                printf("\n");
            }
            Pkmn new = createPkmn( id, name, height, weight, type1, type2);
            addPkmnToList( list, new );
        } else if ( selection == 'p' ) {
            // ADD YOUR CODE HERE (to print the list of Pokemon)
            printPkmnList( list );
        } else if ( selection == 'd' ) {
            // ADD YOUR CODE HERE (to display the details of the current Pokemon)
            printCurrentPkmn( list );
        } else if ( selection == '>' ) {
            // ADD YOUR CODE HERE (to move to the next Pokemon)
            nextPkmn( list );             
        } else if ( selection == '<' ) {
            // ADD YOUR CODE HERE (to move to the previous Pokemon) 

            prevPkmn( list);
        } else if ( selection == 'j' ) {
            // ADD YOUR CODE HERE (to jump to a specific Pokemon)
            printf( "Enter ID: " );
            scanf( "%d", &id );
            jumpToPkmn( list, id);
        } else if ( selection == 'r' ) {
            // ADD YOUR CODE HERE (to remove the current Pokemon)
            removePkmn( list);
        } else if ( selection == 'f' ) {
            // ADD YOUR CODE HERE (to find Pokemon)
        } else if ( selection == 'c' ) {
            // ADD YOUR CODE HERE (to count the number of Pokemon which
            // have been found))
        } else if ( selection == 'e' ) {
            // ADD YOUR CODE HERE (to add an evolution to a Pokemon)
        } else if ( selection == 's' ) {
            // ADD YOUR CODE HERE (to show the evolutions of the current Pokemon)
        }

        printMenu();
        scanf( " %c", &selection );
    }

    freePkmnList( list );

    return EXIT_SUCCESS;
}

void printMenu() {

    printf( "a - Add a Pokemon to the list\n" );
    printf( "p - Print list\n" );
    printf( "d - Display details of the current Pokemon\n" );
    // ADD YOUR CODE HERE (to display more menu options)
    printf( "> - Move to the next Pokemon\n" );
    printf( "< - Move to the previous Pokemon\n" );
    printf( "j - Jump to a specific Pokemon\n" );
    printf( "r - Remove the current Pokemon\n" );
    printf( "f - Find Pokemon\n" );
    printf( "c - Count the number of Pokemon which have been found\n" );
    printf( "e - Add an evolution to a Pokemon\n" );
    printf( "s - Show the evolutions of the current Pokemon\n" );
    printf( "q - Quit\n" );
}

void readPkmnInput(int * id, char ** name, double * height, double *
        weight, int * type1, int * type2) {
    *name = malloc( sizeof( MAX_LEN ) );
    int i;
    printf( "Enter ID: " );
    scanf( "%d", id );
    printf( "Enter name: " );
    scanf( "%s", *name );
    printf( "Enter height: " );
    scanf( "%lf", height );
    printf( "Enter weight: " );
    scanf( "%lf", weight );
    printf( "Enter type1:" );
    for ( i = 0; i < NUM_TYPES; i++ ) {
        printf( " %d) %s", i, getTypeString( i ) );
        if ( i < ( NUM_TYPES - 1 ) ) {
            putchar( ';' );
        } else {
            putchar( ':' );
        }
        if ( i % 4 == 0 ) {
            putchar( '\n' );

        }
    }
    scanf( "%d", type1 );
    printf( "Enter type2:" );
    for ( i = 0; i < NUM_TYPES; i++ ) {
        printf( " %d) %s", i, getTypeString( i ) );
        if ( i < ( NUM_TYPES - 1 ) ) {
            putchar( ';' );
        } else {
            putchar( ':' );
        }
        if ( i % 4 == 0 ) {
            putchar( '\n' );

        }
    }
    scanf( "%d", type2 );
}
