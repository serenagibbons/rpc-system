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
#include <iostream>
#include <string>
using namespace std;

#include "strings.idl"

string concat(string s1, string s2) {
    printf("concat(s1, s2) invoked\n");
    return s1 + s2;
}

void printStringArray(string arr[3]) {
    printf("printStringArray() invoked\n");
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i] << std::endl;    
    }
}