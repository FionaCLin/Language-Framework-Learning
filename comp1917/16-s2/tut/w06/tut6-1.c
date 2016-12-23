/*
 * Fiona Lin
 * z5131048
 *
 */


#include <stdio.h>
#include <stdlib.h>

int len_str( char * str ) ;

int main( int argc, char * argv [] ) {

    char * str1 = "Fiona";
    char * str2 = "String Function";
    printf( "%s length is %d\n", str1, len_str(str1) );
  
    printf( "%s length is %d\n", str2, len_str(str2) );
    
    return EXIT_SUCCESS;
}

int len_str( char * str ) {
    int len = 0;
    while ( str[len] != '\0' ) {
        len++;
    }
    return len;
}
