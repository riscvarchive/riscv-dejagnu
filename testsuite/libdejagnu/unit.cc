// unit.cc -- This is a test case for the Dejagnu.h classes.

#include <iostream>
#include <dejagnu.h>

#include <regex.h>
#include <string>
#include <fstream>
#include <set>
#include <sys/types.h>

TestState runtest;
TestState test;

class TestClass1 {
public:
	string tname;
	unsigned int tnum;
};

TestClass1 testClass1, testClass2, testClass3;
TestClass1 *testClassPtr;

// We have to so this silly crap with renaming the output string, so the generic
// Tcl code that looks for the output state gets confused, and records random
// duplicate messages.
char *os1[] = {
    "FAI: ",
    "PAS: ",
    "UNT: ",
    "UNR: "
};

char *os2[] = {
    "FAILED: ",
    "PASSED: ",
    "UNTESTED: ",
    "UNRESOLVED: "
};

int
main (int argc, char *argv[]) {
    regex_t regex_pat;

//    char **os2 = outstate;
    outstate = os1;

    // Replace the output buffer for cout, so we can examine it to
    // see what was displayed. Otherwise, there is no way we can test
    // the logging functions completely.
    streambuf *sb =  cout.rdbuf();
    char bbuuff[5120];
    sb->setbuf(bbuuff, 5120);

    testClass1.tname = "testType1";
    testClass1.tnum = 1;  
    testClass2.tname = "testType2";
    testClass2.tnum = 2;  
    testClass3.tname = "testType3";
    testClass3.tnum = 3;  
    
    // Test the pass message
    test.pass ("bogus pass message for testing");
    outstate = os2;
    if (strncmp(bbuuff, "\tPAS: bogus pass message", 22) == 0) {
	runtest.pass ("Pass message");
    } else {
	runtest.fail ("Pass message");
    }

    // Test the fail message
    outstate = os1;
    test.fail ("bogus fail message for testing");
    cout.flush();
    outstate = os2;
    if (strncmp(bbuuff, "\tFAI: bogus fail message", 22) == 0) {
	runtest.pass ("Fail message");
    } else {
	runtest.fail ("Fail message");
    }

    // Test the untested message
    outstate = os1;
    test.untested ("bogus untested message for testing");
    cout.flush();
    outstate = os2;
    if (strncmp(bbuuff, "\tUNT: bogus untested message", 21) == 0) {
	runtest.pass ("Untested message");
    } else {
	runtest.fail ("Untested message");
    }

    // Test the unresolved message
    outstate = os1;
    test.unresolved ("bogus unresolved message for testing");
    cout.flush();
    outstate = os2;
    if (strncmp(bbuuff, "\tUNR: bogus unresolved message", 21) == 0) {
	runtest.pass ("Unresolved message");
    } else {
	runtest.fail ("Unresolved message");
    }

    // Make sure we got everything in the totals
    regcomp (&regex_pat, "\r\n\t#passed.*#failed.*#untested.*#unresolved", REG_NOSUB|REG_NEWLINE);
    if (regexec (&regex_pat, bbuuff, 0, (regmatch_t *)0, 0)) {
	runtest.pass ("Totals message");
    } else {
	runtest.fail ("Totals message");
    }

}


