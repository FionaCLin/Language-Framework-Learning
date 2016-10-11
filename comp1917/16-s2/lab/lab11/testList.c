#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void test_print_reverse( void );
void test_extract_unique( void );

void reverse_empty( void );
void reverse_one( void );
void reverse_two( void );
void reverse_five( void );
void reverse_ten( void );

void unique_empty( void );
void unique_one( void );
void unique_disjoinDuplication( void );
void unique_disjoinTripleDuplication( void );
void unique_adjacentDuplication( void );
void unique_adjacentTripleDuplication( void );

int main( void ){
    //call individual test functions
    test_print_reverse( );
    test_extract_unique( );

    return 0;
}


void test_print_reverse( void ){
    //add any additional functions to test your implementation here
    reverse_empty( );
    reverse_one( );
    reverse_two( );
    reverse_five( );
    reverse_ten( );
}

void reverse_empty( void ){
    printf( "Testing print_reverse with empty element\n" );
    List new = newList( );
    printf( "Expected output:\n" );
    printList( new );
    printf( "Your output:\n" );
    print_reverse( new );
    destroy( new );
    printf( "=========================\n" );
}

void reverse_one( void ){
    printf( "Testing print_reverse with 1 element\n" );
    List new = newList( );
    append( new, 0 );
    printf( "Expected output:\n" );
    printf( "[0]->X\n" );
    printf( "Your output:\n" );
    print_reverse( new );
    destroy( new );
    printf( "=========================\n" );
}
void reverse_two( void ){
    printf( "Testing print_reverse with 2 element\n" );
    List new = newList( );
    append( new, 0 );
    append( new, 2 );
    printf( "Expected output:\n" );
    printf( "[2]->[0]->X\n" );
    printf( "Your output:\n" );
    print_reverse( new );
    destroy( new );
    printf( "=========================\n" );
}
void reverse_five( void ){
    printf( "Testing print_reverse with 5 element\n" );
    List new = newList( );
    append( new, 0 );
    append( new, 2 );
    append( new, 4 );
    append( new, 6 );
    append( new, 8 );
    printf( "Expected output:\n" );
    printf( "[8]->[6]->[4]->[2]->[0]->X\n" );
    printf( "Your output:\n" );
    print_reverse( new );
    destroy( new );
    printf( "=========================\n" );
}
void reverse_ten( void ){
    printf( "Testing print_reverse with 10 element\n" );
    List new = newList( );
    append( new, 0 );
    append( new, 2 );
    append( new, 4 );
    append( new, 6 );
    append( new, 8 );
    append( new, 1 );
    append( new, 3 );
    append( new, 5 );
    append( new, 7 );
    append( new, 9 );
    printf( "Expected output:\n" );
    printf( "[9]->[7]->[5]->[3]->[1]->[8]->[6]->[4]->[2]->[0]->X\n" );
    printf( "Your output:\n" );
    print_reverse( new );
    destroy( new );
    printf( "=========================\n" );
}



//##################################################################
void test_extract_unique( void ){
    unique_empty( );
    //add any additional functions to test your implementation here
    unique_one(  );
    unique_disjoinDuplication(  );
    unique_disjoinTripleDuplication(  );
    unique_adjacentDuplication(  );
    unique_adjacentTripleDuplication(  );
}
void unique_empty( void ){
    printf( "Testing extract_unique with empty list\n" );
    List new = newList( );
    List u = extract_unique( new );
    assert( num_nodes( new ) == 0 );
    assert( num_nodes( u ) == 0 );
    destroy( new );
    printf( "Passed\n" );
    printf( "=========================\n" );
}
void unique_one( void ){
    printf( "Testing extract_unique with 1 element list\n" );
    List new = newList( );
    append( new, 1 );
    List u = extract_unique( new );
    assert( num_nodes( new ) == 1 );
    assert( num_nodes( u ) == 1 );
    destroy( new );
    printf( "Passed\n" );
    printf( "=========================\n" );
}

void unique_disjoinDuplication( void ){
    printf( "Testing extract_unique with disjoin duplication element list\n" );
    List new = newList( );
    append( new, 1 );
    append( new, 3 );
    append( new, 1 );
    append( new, 4 );
    List u = extract_unique( new );
    printf( "Expected output:\n" );
    printf( "[1]->[3]->[4]->X\n" );
    printList( u );
    destroy( new );
    destroy( u );
    printf( "Passed\n" );
    printf( "=========================\n" );
}
void unique_disjoinTripleDuplication( void ){
    printf( "Testing extract_unique with disjoin triple duplication element list\n" );
    List new = newList( );
    append( new, 1 );
    append( new, 3 );
    append( new, 1 );
    append( new, 4 );
    append( new, 1 );
    List u = extract_unique( new );
    printf( "Expected output:\n" );
    printf( "[1]->[3]->[4]->X\n" );
    printList( u );
    destroy( new );
    destroy( u );
    printf( "Passed\n" );
    printf( "=========================\n" );
}


void unique_adjacentDuplication( void ){
    printf( "Testing extract_unique with adjacent duplication element list\n" );
    List new = newList( );
    append( new, 1 );
    append( new, 1 );
    append( new, 2 );
    append( new, 2 );
    append( new, 3 );
    append( new, 3 );
    List u = extract_unique( new );
    printf( "Expected output:\n" );
    printf( "[1]->[2]->[3]->X\n" );
    printList( u );
    destroy( new );
    destroy( u );
    printf( "Passed\n" );
    printf( "=========================\n" );
}
void unique_adjacentTripleDuplication( void ){
    printf( "Testing extract_unique with adjacent triple duplication element list\n" );
    List new = newList( );
    append( new, 1 );
    append( new, 1 );
    append( new, 1 );
    append( new, 3 );
    append( new, 3 );
    append( new, 3 );
    List u = extract_unique( new );
    printf( "Expected output:\n" );
    printf( "[1]->[3]->X\n" );
    printList( u );
    destroy( new );
    destroy( u );
    printf( "Passed\n" );
    printf( "=========================\n" );
}







