// mathhelper.c
// simplest test case for libtool and dejagnu library interaction
// Given a char from this set [+ - * /] perform desired operation on
// x and y and return the result
// -999 is returned if an error occures
#include "mathhelper.h"

int mathhelper( char op, int x, int y )
{
  int retval = 0;
  int errorval = -999;
  switch (op) {
    case '+':
      retval = x + y;
      break;
    case '-':
     retval = x - y;
     break;
    case '*':
      retval = x * y;
      break;
    case '/':
      // divide by zero as possible case for dejagnu
      retval = x / y;
      break;
    case '\\':
      // divide by zero as possible case for dejagnu
      if ( y !=  0)  
        retval = x / y;
      else
        retval = errorval;
      break;

    default:
      retval = errorval;
  }
  return retval;
}
