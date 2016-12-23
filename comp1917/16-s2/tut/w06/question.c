/*
 * Fiona Lin
 * z5131048
 *
 */


#include <stdio.h>
#include <stdlib.h>

int len_str( char * str ) ;
void reverse_string( char * s );

int main( int argc, char * argv [] ) {

    char * str1 = "Fiona";
    char * str3 = "Fiona";
    char * str2 = "String Function";
    char * str4 = "String Function";
    printf( "%s length is %d\n", str1, len_str(str1) );
    printf( "%s length is %d\n", str2, len_str(str2) );
    reverse_string( str3 ); 
    reverse_string( str4 ); 
    printf( "%s after reverse is %s\n", str1, str3 );
    printf( "%s after reverse is %s\n", str2, str4 );

    return EXIT_SUCCESS;
}

int len_str( char * str ) {
    int len = 0;
    while ( str[len] != '\0' ) {
        len++;
    }
    return len;
}


void reverse_string( char * s ) {
    int j = len_str( s ) - 1;
    int i = 0;
    char * temp;
    printf("%c,%c", s[i], s[j]);

    while ( i < j ) {
        temp = &s[i];    
        printf("%p, %p", &s[i], &s[j]);
        s[i] = s[j];

        printf("%p, %p", &s[i], &s[j]);
        s[j] = *temp;
        j--;
        i++;
    }
}
