/*
   einstein.c

   Sample program for COMP1917
   Use Einstein's equation to compute relativistic
   observed mass, as a function of rest mass and velocity.
*/

#include <stdio.h>
#include <math.h>
// remember to compile with -lm

// speed of light in m/s
#define SPEED_OF_LIGHT 299792458.0

int main( void )
{
  float mass, rest_mass;
  float velocity;
  float ratio;

  printf("Enter rest mass: " );
  scanf( "%f", &rest_mass );

  printf("Enter velocity (m/s): " );
  scanf( "%f", &velocity );

  // compute velocity as a fraction of speed of light
  ratio = velocity / SPEED_OF_LIGHT;

  if( ratio >= 1.0 ) {
    printf( "Error: velocity exceeds speed of light.\n" );
  }
  else {
    // compute observed mass using Einstein's equation
    mass = rest_mass / sqrt( 1.0 - ratio*ratio );

    printf( "Observed mass = %1.6f\n", mass );
  }

  return 0;
}
