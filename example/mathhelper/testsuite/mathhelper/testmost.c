#include <stdio.h>
#include "mathhelper.h"
#include <dejagnu.h>

// simple test code to link in lib and call its functions
int main ( void )
{
  int r;

  r = mathhelper('+', 5 , 5 );
  if ( r == 10 ) pass( "testmost - case 1" );
  else           fail( "testmost - case 1" );
  printf("5 + 5 = %d \n", r );

  r = mathhelper('-', 5 , 5 );
  if ( r == 0 ) pass( "testmost - case 2" );
  else          fail( "testmost - case 2" );
  printf("5 - 5 = %d \n", r );

  r =  mathhelper('*', 5 , 5 );
  if ( r == 25 ) pass( "testmost - case 3" );
  else           fail( "testmost - case 3" );
  printf("5 * 5 = %d \n",r );

  r =  mathhelper('/', 5 , 5 );
  if ( r == 1 ) pass( "testmost - case 4" );
  else          fail( "testmost - case 4" );
  printf("5 / 5 = %d \n",r );

  r =  mathhelper('%', 5 , 5 );
  if ( r == -999 ) pass( "testmost - case 5" );
  else             fail( "testmost - case 5" );
  printf("5 % 5 = %d \n",r );

  r =  mathhelper('\\', 5 , 0 );
  if ( r == -999 ) pass( "testmost - case 6" );
  else             fail( "testmost - case 6" );
  printf("5 \\ 0 = %d \n",r );

  r =  mathhelper('\\', 5 , 5 );
  if ( r == 1 ) pass( "testmost - case 7" );
  else          fail( "testmost - case 7" );
  printf("5 \\ 5 = %d \n",r );
  pass("testmost  - case 8" );
  return 0;
} 
