/** \file loan.c

   Sample program for COMP1917

   Compute the time required to pay off a loan.

   Test doxygen on this program by running
   ~cs1917/bin/doxygen mortgage.c loan.c
*/

#include <stdio.h>

/**
   @param rate         percentage interest rate
   @param principal    amount of money borrowed
   @param pay_amount   amount of each payment
   @param num_per_year number of payments per year

   @return number of years to pay off the loan
*/
double loan_term(
                 double rate,
                 double principal,
                 double pay_amount,
                 double num_per_year
                )
{
  double balance = principal;
  double years = 0.0;
  int day = 0;

  while( balance > 0.0 ) {
    // update time in years
    years += 1.0 / num_per_year;
    // charge daily interest for this period
    while( day < years * 365.0 ) {
      balance *= ( 1.0 + 0.01 * rate / 365.0 );
      day++;
    }
    // deduct loan repayment
    balance -= pay_amount;
    if( balance > principal ) {
      years = -1.0; // signal that loan will never be paid
      break;
    }
  }
  return( years );
}

