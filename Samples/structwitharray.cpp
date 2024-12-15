// --------------------------------------------------------------
//
//                        structwitharray.cpp
//
//        Author: Serena Gibbons 
//   
//
//        Trivial implementations of the routines declared
//        in structwitharray.idl. These are for testing: they
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

#include "structwitharray.idl"

int getSumOfm1(s s1) {
    printf("getSumOfm1() invoked\n");
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += s1.m1[i];
    }
    return sum;
}