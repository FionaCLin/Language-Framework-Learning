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

char str1[] = "Hello, world!";
    char str2[] = "abcdefghijklmnopqrstuvwxyz";
    char str3[] = "1234567890";
    char str4[] = "";
    char str5[] = "live on";

    printf("Reverse of \e[1m%30s\e[0m is", str1);
    reverse_string(str1);
    printf("\e[1m%30s\e[0m\n", str1);
    printf("Reverse of \e[1m%30s\e[0m is", str2);
    reverse_string(str2);
    printf("\e[1m%30s\e[0m\n", str2);
    printf("Reverse of \e[1m%30s\e[0m is", str3);
    reverse_string(str3);
    printf("\e[1m%30s\e[0m\n", str3);
    printf("Reverse of \e[1m%30s\e[0m is", str4);
    reverse_string(str4);
    printf("\e[1m%30s\e[0m\n", str4);
    printf("Reverse of \e[1m%30s\e[0m is", str5);
    reverse_string(str5);
    printf("\e[1m%30s\e[0m\n", str5);   
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
    int temp;
   
    while ( i < j ) {
        temp = s[i];    
        s[i] = s[j];
        s[j] = temp;
        j--;
        i++;
    }
}
