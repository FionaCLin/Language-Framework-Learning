/*
 *  palindrome.c
 *  Description: 
 * int isPalindrome( char s[] )
 * which returns 1 if the string s is a palindrome, 0 otherwise. (Again,
 * try to do it just using the string itself, i.e. without declaring or
 * copying the characters to any other array.)
 * Add a main() function which reads a string, calls the function
 * isPalindrome() and prints "Yes, is a palindrome." or "No, not a
 * palindrome." depending on the return value. (Try to do it without
 * actually changing the string itself, or copying it into another
 * string.) 
 * [Note: fgets() keeps the newline character '\n' at the end of the
 * string. You may have to skip over this character in order to
 * correctly check for a palindrome.]
 *
 * Now modify the isPalindrome() function so that it ignores case, word
 * boundaries and non-alphabetic characters. You are free to use library
 * functions like isalpha() and toupper(). Here are some famous
 * palindromes which your program should correctly classify:
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE  1

int isPalindrome( char s[] );
void printResult( int res, char s[] );

int main ( int argc, char * argv[] ) {
    //    printf( "Enter your words: " );
    char s1[] = "kayak";
    char s2[] = "Madam, I'm Adam";
    char s3[] = "Able was I ere I saw Elba";
    char s4[] = "A man, a plan, a canal: Panama";
    char s5[] = "Are we not drawn onward, we few, drawn onward to new era?";

    printResult( isPalindrome( s1 ), s1 );
    printResult( isPalindrome( s2 ), s2 );
    printResult( isPalindrome( s3 ), s3 );
    printResult( isPalindrome( s4 ), s4 );
    printResult( isPalindrome( s5 ), s5 );
    
    return EXIT_SUCCESS;
}
void printResult( int res, char s[] ) {
    printf( "%s\n", s );
    if ( res ) {
        printf( "Yes, is a palindrome.\n" );
    } else {

        printf( "No, not a palindrome.\n" );
    }
    return ;
}
int isPalindrome( char s[] ) {
    int len = strlen( s ); 
    int i = 0;
    int j = len-1;
    int result = TRUE;
    while ( i < len && result ) {
        if ( isalpha( s[i] ) ) {
            if ( isalpha( s[j] ) ) {
                if ( toupper(s[i]) != toupper(s[j]) ) {
                    // printf( "%c %c\n ",s[i],s[j] );
                    result = FALSE;
                }          
                i++;
                j--;
            } else {
                j--;
            }
        } else {
            i++;
        }
    }
    return result;
}
