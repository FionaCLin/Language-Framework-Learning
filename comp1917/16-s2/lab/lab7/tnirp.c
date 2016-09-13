/*
 *  tnrip.c
 *  Description: 
 *  char* reverse_string( char s[] )
 *  which takes a string s as parameter and returnes a dynamically
 *  allocated reversed string. For example, the string "live on" would be
 *  converted to "no evil".
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAXLEN  128

char* reverse_string( char s[] );

int main( void )
{
   char s[MAXLEN];

   printf("Enter string:\n");
   fgets( s, MAXLEN, stdin );
   char *rev = reverse_string( s );
   printf("%s\n", rev);

   return 0;
}

char* reverse_string( char s[] ) {
    int len = strlen(s);
    int i;
    char * rev = malloc( sizeof(char)* len );
    for ( i = len-1; i >= 0; i--) {
        *rev = s[i];
        rev++;
    }
    rev = rev - len;
    return rev;
}
