#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tut11.c"

int main( void ) {
    Queue q = createQueue();
    assert( q != NULL );
    enqueue( q, 1 );    
    enqueue( q, 2 );    
    enqueue( q, 3 );    
    enqueue( q, 4 );    
    enqueue( q, 5 );
    printQ( q );
    dequeue( q );
    printQ( q );
    dequeue( q );
    printQ( q );
    dequeue( q );
    printQ( q );
    dequeue( q );
    printQ( q );
    return EXIT_SUCCESS;
}

