/*
 *  memoryDemo.c
 *  Description: 
 *  print size of different data type.
 *  Tutorial class: T14A
 *  Tutor name: Curtis Millar
 *  Author: Fiona Lin
 *  Date:23 Aug
 *  reference: http://en.cppreference.com/w/c/language/arithmetic_types
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>   // integer limits
#include <float.h>

int main ( int argc, char * argv[] ) {

    printf("The number of bits in a byte %d\n", CHAR_BIT);

    printf("Bits in char = %d\n", CHAR_BIT);

    printf("\nsizeof(char) is %lu bytes.\n", sizeof(char));
    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);
    printf("The maximum+1  value of CHAR = %c<-%d\n", CHAR_MAX+1, CHAR_MAX+1);

    printf("\nsizeof(int) is %lu bytes.\n", sizeof(int));
    printf("The minimum value of INT = %d\n", INT_MIN);
    printf("*The minimum-1 value of INT = %d\n", INT_MIN-1);
    printf("\nThe maximum value of INT = %d\n", INT_MAX);
    printf("*The maximum+1 value of INT = %d\n", INT_MAX+1);

    printf("\nsizeof(unsigned int) is %lu bytes.\n", sizeof(unsigned int));
    printf("unsigned int max = %u\n", UINT_MAX);
    printf("unsigned int max+1 = %u\n", UINT_MAX+1);

    printf("\nsizeof(long int) is %lu bytes.\n", sizeof(long int));
    
    printf("\nsizeof(unsigned long long) is %lu bytes.\n", sizeof(unsigned long long));
    printf("unsigned long long max = %llu\n", ULLONG_MAX);
    printf("unsigned long long max+1 = %llu\n", ULLONG_MAX+1);
    
    printf("\nsizeof(float) is %lu bytes.\n", sizeof(float));
    printf("The minimum value of float = %.10e\n", FLT_MIN);
    printf("The maximum   value of float = %.10e\n", FLT_MAX);
    printf("Precision value: %d\n", FLT_DIG );
    printf("The number of digits in the number = %.10d\n", FLT_MANT_DIG);
    
    printf("\nsizeof(double) is %lu bytes.\n", sizeof(double));
    printf("The maximum value of double = %.10e\n", DBL_MAX);
    printf("The minimum value of double = %.10e\n", DBL_MIN);
    printf("Precision value: %d\n", DBL_DIG );
    printf("The maximum value of double = %.10e\n", DBL_MAX);
    printf("The minimum value of double = %.10e\n", DBL_MIN);

    printf("\nsizeof(char*) is %lu bytes.\n", sizeof(char*));
    printf("\nsizeof(int*) is %lu bytes.\n", sizeof(int*));
    printf("\nsizeof(unsigned int*) is %lu bytes.\n", sizeof(unsigned int*));
    printf("\nsizeof(float*) is %lu bytes.\n", sizeof(float*));
    printf("\nsizeof(double*) is %lu bytes.\n", sizeof(double*));
    return EXIT_SUCCESS;
}






/*
 *    printf("\nsizeof(signed char) is %lud bytes.\n", sizeof(signed char));
    printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
   
    printf("\nsizeof(unsigned char) is %lud bytes.\n", sizeof(unsigned char));
    printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);
    
    printf("\nsizeof(short) is %lud bytes.\n", sizeof(short));
    printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
    printf("The maximum value of SHORT INT = %d\n", SHRT_MAX); 

    printf("\nsizeof(long) is %lud bytes.\n", sizeof(long));
    printf("The minimum value of LONG = %ld\n", LONG_MIN);
    printf("The maximum value of LONG = %ld\n", LONG_MAX);

    printf("\nsizeof(unsigned long) is %lud bytes.\n", sizeof(unsigned long));
    printf("unsigned long max = %lu\n", ULONG_MAX);

    printf("\nsizeof(long double) is %ld bytes.\n", sizeof(long double));
    printf("The maximum value of long double = %.10Le\n", LDBL_MAX);
    printf("The minimum value of long double = %.10Lf\n", LDBL_MIN);
    printf("Precision value: %d\n", LDBL_DIG );
 *
 * */
