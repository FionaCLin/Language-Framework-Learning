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

int main ( int argc, char * argv[] ) {
    //    printf( "Enter your words: " );
    char s1[] = "kayak";
    char s2[] = "Madam, I'm Adam";
    char s3[] = "Able was I ere I saw Elba";
    char s4[] = "A man, a plan, a canal: Panama";
    char s5[] = "Are we not drawn onward, we few, drawn onward to new era?";
    assert( isPalindrome( s1 ) == TRUE );
    assert( isPalindrome( s2 ) == TRUE );
    assert( isPalindrome( s3 ) == TRUE );
    assert( isPalindrome( s4 ) == TRUE );
    assert( isPalindrome( s5 ) == TRUE );

    return EXIT_SUCCESS;
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
