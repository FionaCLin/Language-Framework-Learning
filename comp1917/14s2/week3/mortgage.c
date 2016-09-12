/** \file mortgage.c

   Sample program for COMP1917

   Compare loan terms for monthly and fortnightly mortgage repayments.

   Test doxygen on this program by running
   ~cs1917/bin/doxygen mortgage.c loan.c
*/

#include <stdio.h>

// tell compiler that loan_term() is defined elsewhere
double loan_term(
                 double rate,
                 double principal,
                 double pay_amount,
                 double num_per_year
                );
/**
   Input interest rate, amount borrowed and monthly payment and
   print the loan term for both monthly and fortnightly payments.
*/
int main( void )
{
   double interest_rate;
   double principal;
   double monthly_payment;
   double time;

   printf( "Enter percentage rate ? " );
   scanf( "%lf", &interest_rate );
   printf( "Enter amount borrowed ? " );
   scanf( "%lf", &principal );
   printf( "Enter monthly payment ? " );
   scanf( "%lf", &monthly_payment );

   // compute loan term with monthly repayments
   time = loan_term(interest_rate,principal,monthly_payment,12);
   printf("\n    Monthly payments of $%1.2f, ",monthly_payment);
   if( time >= 0 ) {
      printf( "loan term is %1.2f years.\n", time );
   }
   else {
      printf( "loan will never be repaid.\n" );
   }

   // compute loan term with fortnightly repayments
   time = loan_term(interest_rate,principal,0.5*monthly_payment,26);
   printf("Fortnightly payments of $%1.2f, ", 0.5*monthly_payment );
   if( time >= 0 ) {
      printf( "loan term is %1.2f years.\n\n", time );
   }
   else {
      printf( "loan will never be repaid.\n\n" );
   }

   return 0;
}

