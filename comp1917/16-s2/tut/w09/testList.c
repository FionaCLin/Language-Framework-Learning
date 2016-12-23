#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"


int main( int argc, char * argv[] ) {
    Lnode test1 = newNode( 2 );
    printList( test1 ); 
    Lnode test2 = newNode( 4 );
    printList( test2 );
    test2 = prepend( test2, test1 );
    printList( test2 );
    Lnode test3 = newNode(6);
    test2 = append( test2, test3 );
    printList( test2 );
    test2 = deleteNode( test2, 2 );
    printList( test2 );
    
    return EXIT_SUCCESS;
}
