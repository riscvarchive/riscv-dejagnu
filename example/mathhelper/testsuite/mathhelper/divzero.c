#include <stdio.h>
#include "mathhelper.h"
#include <dejagnu.h>

// simple test code to link in lib and call its functions
int main ( void )
{
  fail("divzero - bogus fail just to increment the test count");
  pass("divzero - bogus pass just to increment the test count");
  fail("divzero - bogus fail just to increment the test count");
  printf("test uncaught div by zero.\n");
  printf("5 / 0 = %d \n", mathhelper('/', 5 , 0 ));
  fail("divzero");
  return 0;
}
