// unit.cc -- This is a test case for the dejagnu.h classes.
// Copyright 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

// This file is part of DejaGnu.

// DejaGnu is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// DejaGnu is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with DejaGnu; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

#include <sys/types.h>
#include <iostream>
#include <regex.h>
#include <string>
#include <fstream>
#include <set>
#include <dejagnu.h>

using namespace std;

TestState runtest;
TestState test;

class TestClass1
{
public:
  string tname;
  unsigned int tnum;
};

TestClass1 testClass1, testClass2, testClass3;
TestClass1 *testClassPtr;

// We have to do this silly crap with renaming the output string, so
// the generic Tcl code that looks for the output state gets confused,
// and records random duplicate messages.
const char *os1[] = {
    "FAI: ", "PAS: ", "UNT: ", "UNR: "
};

const char *os2[] = {
    "FAILED: ", "PASSED: ", "UNTESTED: ", "UNRESOLVED: "
};

int
main (int argc, char *argv[])
{
  regex_t regex_pat;
  outstate = os1;

  // Replace the output buffer for cout, so we can examine it to see
  // what was displayed. Otherwise, there is no way we can test the
  // logging functions completely.
  char buf[5120];
#ifdef __STDC_HOSTED__
  cout.rdbuf ()->pubsetbuf (buf, 5120);
#else
  cout.rdbuf ()->setbuf (buf, 5120);
#endif
  
  testClass1.tname = "testType1";
  testClass1.tnum = 1;
  testClass2.tname = "testType2";
  testClass2.tnum = 2;
  testClass3.tname = "testType3";
  testClass3.tnum = 3;
  
  // Test the pass message.
  test.pass ("bogus pass message for testing");
  outstate = os2;
  if (strncmp (buf, "\tPAS: bogus pass message", 22) == 0)
    runtest.pass ("Pass message");
  else
    runtest.fail ("Pass message");
  
  // Test the fail message.
  outstate = os1;
  test.fail ("bogus fail message for testing");
  cout.flush ();
  outstate = os2;
  if (strncmp (buf, "\tFAI: bogus fail message", 22) == 0)
    runtest.pass ("Fail message");
  else
    runtest.fail ("Fail message");
  
  // Test the untested message.
  outstate = os1;
  test.untested ("bogus untested message for testing");
  cout.flush ();
  outstate = os2;
  if (strncmp (buf, "\tUNT: bogus untested message", 21) == 0) {
    runtest.pass ("Untested message");
  } else {
    runtest.fail ("Untested message");
  }
  
  // Test the unresolved message.
  outstate = os1;
  test.unresolved ("bogus unresolved message for testing");
  cout.flush ();
  outstate = os2;
  if (strncmp (buf, "\tUNR: bogus unresolved message", 21) == 0)
    runtest.pass ("Unresolved message");
  else
    runtest.fail ("Unresolved message");
  
  // Make sure we got everything in the totals.
  regcomp (&regex_pat,
	   "\r\n\t#passed.*#failed.*#untested.*#unresolved",
	   REG_NOSUB | REG_NEWLINE);

  if (regexec (&regex_pat, buf, 0, (regmatch_t *) 0, 0))
    runtest.pass ("Totals message");
  else
    runtest.fail ("Totals message");

  return 0;
}


