// --------------------------------------------------------------
//
//                        strings.cpp
//
//        Author: Serena Gibbons 
//   
//
//        Trivial implementations of the routines declared
//        in strings.idl. These are for testing: they
//        just print messages.
//
//     
// --------------------------------------------------------------

// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE IMPLEMENTING. THIS MAKES SURE THE
// CODE HERE ACTUALLY MATCHES THE REMOTED INTERFACE

#include <cstdio>
#include <string>
using namespace std;

#include "strings.idl"

string concat(string s1, string s2) {
    printf("concat() invoked\n");
    return s1 + s2;
}

